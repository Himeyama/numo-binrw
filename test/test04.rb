#!/usr/bin/env ruby

require "numo/binrw"

# 読み込みテスト
files = ["data51.bin", "data52.bin", "data53.bin", "data54.bin"]

# 複数ファイルに書き込み
a = Numo::DFloat.cast(1..100).reshape(4, true)
a.bin_write(files)

# 単一ファイル読み込み
p Numo::DFloat.bin_read(files[0])

# 複数ファイル読み込み
p Numo::DFloat.bin_read(files)


# 各クラスで読み込み
p Numo::DFloat.bin_read("double.bin")
p Numo::SFloat.bin_read("float.bin")
p Numo::Int32.bin_read("int32.bin")
p Numo::Int64.bin_read("int64.bin")
