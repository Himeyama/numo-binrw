#!/usr/bin/env ruby

require "numo/binrw"

# 単一ファイルに書き込み
a = Numo::DFloat.cast((1..100).to_a)
a.bin_write("data01.bin")

# 複数ファイルに書き込み
b = Numo::DFloat.cast((1..100).to_a).reshape(4, true)
b.bin_write(["data11.bin", "data12.bin", "data13.bin", "data14.bin"])