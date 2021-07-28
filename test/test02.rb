#!/usr/bin/env ruby

require "numo/binrw"
require 'benchmark'

exit

puts "単一ファイル書き込みテスト"
a = Numo::DFloat.new(2 << 26).rand # 1 GiB
Benchmark.bm 10 do |r|
    r.report "dont use" do
        open("tmp21.bin", "w").write(a.to_binary)
    end

    r.report "use" do
        a.bin_write("tmp22.bin")
    end
end

puts "複数ファイル書き込みテスト"
b = Numo::DFloat.new(2 << 28).rand.reshape(4, true)
Benchmark.bm 10 do |r|
    r.report "dont use" do
        open("tmp31.bin", "w").write(b[0, true].to_binary)
        open("tmp32.bin", "w").write(b[1, true].to_binary)
        open("tmp33.bin", "w").write(b[2, true].to_binary)
        open("tmp34.bin", "w").write(b[3, true].to_binary)
    end

    r.report "use" do
        b.bin_write(["tmp35.bin", "tmp36.bin", "tmp37.bin", "tmp38.bin"])
    end
end