#include <stdbool.h>
#include <ruby.h>
#include <numo/narray.h>

#define rb_is_a(obj, cls) (rb_funcall(obj, rb_intern("is_a?"), 1, cls) == Qtrue)

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


VALUE nrw_bin_write(VALUE self, VALUE obj, VALUE filename){
    char* cfilename;
    obj = rb_funcall(obj, rb_intern("copy"), 0);
    void* data = na_get_pointer(obj);
    long size = NUM2LONG(rb_funcall(obj, rb_intern("size"), 0));

    if(rb_is_a(filename, rb_cArray)){
        long row = NUM2LONG(rb_funcall(filename, rb_intern("size"), 0));
        long col = size / row;
        struct bin_write_arg_ret st[row];
        for(long i = 0; i < row; i++){
            VALUE file = rb_ary_entry(filename, i);
            cfilename = StringValuePtr(file);
            st[i].filename = cfilename;
            st[i].size = col;
            if(rb_is_a(obj, numo_cDFloat)){
                st[i].data = (double*)data + col * i;
                st[i].ssize = 8;
            }else if(rb_is_a(obj, numo_cSFloat)){
                st[i].data = (float*)data + col * i;
                st[i].ssize = 4;
            }else if(rb_is_a(obj, numo_cInt32)){
                st[i].data = (int32_t*)data + col * i;
                st[i].ssize = 4;
            }else if(rb_is_a(obj, numo_cInt64)){
                st[i].data = (int64_t*)data + col * i;
                st[i].ssize = 8;
            }else{
                return Qfalse; // 未対応クラス
            }
            bin_write(st + i);
        }
    }else if(rb_is_a(filename, rb_cString)){
        cfilename = StringValuePtr(filename);
        struct bin_write_arg_ret st;
        st.filename = cfilename;
        st.size = size;
        st.data = data;
        if(rb_is_a(obj, numo_cDFloat)){
            st.ssize = 8;
        }else if(rb_is_a(obj, numo_cSFloat)){
            st.ssize = 4;
        }else if(rb_is_a(obj, numo_cInt32)){
            st.ssize = 4;
        }else if(rb_is_a(obj, numo_cInt64)){
            st.ssize = 8;
        }else{
            return Qfalse; // 未対応クラス
        }
        bin_write(&st);
    }

    return obj;
}