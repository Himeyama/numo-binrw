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
b = Numo::DFloat.new(2 << 29).rand.reshape(8, true)
Benchmark.bm 10 do |r|
    r.report "dont use" do
        b.shape[0].times do |i|
            open("tmp3#{i}.bin", "w").write(b[i, true].to_binary)
        end
    end

    r.report "use" do
        b.bin_write(Array.new(8){ |i| "tmp4#{i}.bin"})
    end
end