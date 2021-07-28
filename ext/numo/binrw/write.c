#include <stdbool.h>
#include <pthread.h>
#include <ruby.h>
#include <numo/narray.h>


extern VALUE numo_cDFloat;

struct bin_write_arg_ret{
    const char* filename;
    void *data;
    long size;
    int ssize;
    bool r;
};

void bin_write(struct bin_write_arg_ret* st){
    FILE* fp = fopen(st->filename, "w");
    if(fp){
        fwrite(st->data, st->ssize, st->size, fp);
        fclose(fp);
    }else{
        st->r = false;
        return;
    }
    st->r = true;
}


VALUE nrw_dfloat_bin_write(VALUE self, VALUE filename){
    char* cfilename;
    double* data = (double*)na_get_pointer(self);
    long size = NUM2LONG(rb_funcall(self, rb_intern("size"), 0));

    if(rb_funcall(filename, rb_intern("is_a?"), 1, rb_cArray) == Qtrue){
        long row = NUM2LONG(rb_funcall(filename, rb_intern("size"), 0));
        long col = size / row;
        struct bin_write_arg_ret st[row];
        pthread_t threads[row];
        for(long i = 0; i < row; i++){
            VALUE file = rb_ary_entry(filename, i);
            cfilename = StringValuePtr(file);
            st[i].filename = cfilename;
            st[i].data = data + col * i;
            st[i].size = col;
            st[i].ssize = sizeof(double);
            if(pthread_create(threads + i, NULL, (void*)bin_write, (void*)(st + i)))
                return Qfalse;
        }
        for(long i = 0; i < row; i++){
            if(pthread_join(threads[i], NULL))
                return Qfalse;
        }
    }else if(rb_funcall(filename, rb_intern("is_a?"), 1, rb_cString) == Qtrue){
        cfilename = StringValuePtr(filename);
        struct bin_write_arg_ret st = {cfilename, data, size, sizeof(double), false};
        bin_write(&st);
    }

    return self;
}