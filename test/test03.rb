#!/usr/bin/env ruby

# 各クラスごとのテスト

require "numo/binrw"

a = Numo::DFloat.cast(0...100)
a.bin_write("double.bin")

a = Numo::SFloat.cast(a)
a.bin_write("float.bin")

a = Numo::Int32.cast(a)
a.bin_write("int32.bin")

a = Numo::Int64.cast(a)
a.bin_write("int64.bin")