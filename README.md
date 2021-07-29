# numo-binrw

[![build](https://github.com/Himeyama/numo-binrw/actions/workflows/build.yml/badge.svg)](https://github.com/Himeyama/numo-binrw/actions/workflows/build.yml) [![Gem Version](https://badge.fury.io/rb/numo-binrw.svg)](https://badge.fury.io/rb/numo-binrw)

## 開発状況
- [x] 書き込み
    - [x] 複数のファイル書き込み
    - 対応型
        - [x] 倍精度浮動小数点数
        - [x] 単精度浮動小数点
        - [x] 32 Bit 整数
        - [x] 64 Bit 整数
- [x] 読み込み
    - [x] 複数のファイルから読み込み
    - 対応型
        - [x] 倍精度浮動小数点数
        - [x] 単精度浮動小数点
        - [x] 32 Bit 整数
        - [x] 64 Bit 整数

## 使用法
```rb
require "numo/binrw"

# 書き込み (例: 倍精度浮動小数点数)
a = Numo::DFloat.cast(0...100)
a.bin_write("dfdata.bin")

# 他の型で書き込み (例: 単精度浮動小数点)
b = Numo::SFloat.cast(0...100)
b.bin_write("fdata.bin")

# 複数ファイルに書き込み
c = Numo::Int32.cast(0...100).reshape(4, true)
c.bin_write(["idata01.bin", "idata02.bin", "idata03.bin", "idata04.bin"])

# 読み込み
d = Numo::Int32.bin_read("idata01.bin")
p d

## 複数ファイルから読み込み
e = Numo::Int32.bin_read(["idata01.bin", "idata02.bin", "idata03.bin", "idata04.bin"])
p e
```

## インストール
```sh
gem install numo-binrw
```
