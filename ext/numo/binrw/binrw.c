#include <stdio.h>
#include <ruby.h>
#include <numo/narray.h>
#include "lib.h"
#include "read.h"
#include "write.h"

extern VALUE numo_cDFloat;


void Init_binrw(void){
    rb_define_singleton_method(numo_cDFloat, "dfloat_bin_read", nrw_dfloat_bin_read, 1);
    rb_define_method(numo_cDFloat, "dfloat_bin_write", nrw_dfloat_bin_write, 1);
}