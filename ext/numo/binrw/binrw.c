#include <stdio.h>
#include <ruby.h>
#include <numo/narray.h>
#include "lib.h"
#include "read.h"
#include "write.h"

extern VALUE numo_cDFloat;
extern VALUE numo_cSFloat;
extern VALUE numo_cInt32;
extern VALUE numo_cInt64;
extern VALUE rb_mNumo;


VALUE rb_cBinrw;

void Init_binrw(void){
    rb_cBinrw = rb_define_module_under(rb_mNumo, "Binrw");
    rb_define_module_function(rb_cBinrw, "_bin_write", nrw_bin_write, 2);

    rb_define_singleton_method(numo_cDFloat, "_bin_read", nrw_bin_read, 1);
    rb_define_singleton_method(numo_cSFloat, "_bin_read", nrw_bin_read, 1);
    
}