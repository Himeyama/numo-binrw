#include <ruby.h>
#include <numo/narray.h>

#define rb_is_a(obj, cls) (rb_funcall(obj, rb_intern("is_a?"), 1, cls) == Qtrue)


struct bin_read_arg_ret{
    const char* filename;
    void *data;
    long size;
    int ssize;
    bool r;
};

void bin_read(struct bin_read_arg_ret* st){
    FILE* fp = fopen(st->filename, "r");
    if(fp){
        long size;
        size = fread(st->data, st->ssize, st->size, fp);
        if(size != st->size){
            st->r = false;
            return;
        }
        fclose(fp);
    }else{
        st->r = false;
        return;
    }
    st->r = true;
}

VALUE nrw_bin_read(VALUE self, VALUE cls, VALUE filename){
    long size = NUM2LONG(rb_funcall(rb_funcall(rb_cFile, rb_intern("stat"), 1, filename), rb_intern("size"), 0));
    struct bin_read_arg_ret st;
    int ssize;
    if(cls == numo_cDFloat){
        ssize = 8;
    }else if(cls == numo_cSFloat){
        ssize = 4;
    }else if(cls == numo_cInt32){
        ssize = 4;
    }else if(cls == numo_cInt64){
        ssize = 8;
    }else{
        return Qfalse; // 非対応クラス
    }
    VALUE na = rb_funcall(cls, rb_intern("zeros"), 1, LONG2NUM(size / ssize));
    st.data = na_get_pointer(na);
    st.filename = StringValuePtr(filename);
    st.size = size;
    st.ssize = ssize;
    bin_read(&st);
    return na;
}
