#!/usr/bin/env ruby
require "numo/binrw"

a = Numo::DFloat.cast(0...100)[20..50]
p a
a.bin_write("a.bin")
p Numo::DFloat.bin_read("a.bin")

b = Numo::DFloat.cast(0...100).reverse
p b
b.bin_write("b.bin")
p Numo::DFloat.bin_read("b.bin")