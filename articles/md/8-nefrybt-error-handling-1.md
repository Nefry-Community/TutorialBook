+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 15
slug = "nefrybt-error-handling-1"
title = "ライブラリアップデート後の書き込みエラー"
title_eng = "about Nefry BT"
description = "Nefry BTのライブラリをアップデートしたあとに書き込みをしようとするとでるエラーについてです。"
draft = false
doctype = ["nefrybt"]
date = "2017-08-22T01:02:41+09:00"
+++

## エラー内容

Nefry BTのライブラリを`0.9.6`から`1.0.1`にアップデートしまたところ、プログラム書き込み時にエラーが発生しました。

Arduino IDEのログは以下の内容です。

```
Arduino：1.8.3 (Mac OS X), ボード："Nefry BT, 921600, None"
ボードnefrybt (プラットフォームesp32、パッケージNefry(ESP32))は不明です
ボードNefry BTに対するコンパイル時にエラーが発生しました。
```

ライブラリをアップデートした際のゴミが残っていることが原因です。

## 対処法

Arduinoの設定（Preferences）を開き、`以下のファイルを編集すれば~`と書いている部分のパスをクリックしましょう。そうするとArduino IDEのライブラリがあるフォルダが開かれます。ここでは`Arduino15`というフォルダが開かれました。

**この時点でArduino IDEは一度終了させましょう。**

![](https://i.gyazo.com/35831bcfd1a9849cd52c587fb5196925.png)

その後`packages > Nefy(ESP32) > hardware > esp32`とフォルダをたどっていくと、`0.9.6`、`1.0.1`などのライブラリバージョン名のフォルダがあります。

最新版以外は削除してください。今回は`0.9.6`をフォルダごと削除します。

![](https://i.gyazo.com/3e2f7a9f0588817787ba3d4cf85acb24.png)

これで再度Arduino IDEを起動してプログラムを書き込み直すとエラーが解消されます。
