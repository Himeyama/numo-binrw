# numo-binrw

[![build](https://github.com/Himeyama/numo-binrw/actions/workflows/build.yml/badge.svg)](https://github.com/Himeyama/numo-binrw/actions/workflows/build.yml)

## 開発状況
- [x] 書き込み
    - [x] 複数のファイル書き込み
    - 対応型
        - [x] 倍精度浮動小数点数
        - [x] 単精度浮動小数点
        - [x] 32 Bit 整数
        - [x] 64 Bit 整数
- [x] 読み込み
    - [ ] 複数のファイルから読み込み
    - 対応型
        - [x] 倍精度浮動小数点数
        - [x] 単精度浮動小数点
        - [x] 32 Bit 整数
        - [x] 64 Bit 整数

## To do
- 読み込みを対応させる
- 多くの型を対応させる
- rubygems に公開

## インストール
```sh
git clone https://github.com/Himeyama/numo-binrw.git
rake install
```
