+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 9
slug = "nefrybt-led"
title = "Nefry BTで内蔵LEDでLチカを試す"
title_eng = "about Nefry BT"
description = "Nefry BTの開発の最初のステップとしてLチカプログラムを動かしてみましょう。"
draft = false
doctype = ["nefrybt"]
date = "2017-07-25T01:02:41+09:00"
+++

このページではNefry BTでLEDを制御する方法を紹介します。
Nefry BTをArduino IDEで開発するにあたり、[こちらのドキュメントの内容](/docs/nefrybt-arduino-ide-setup/)を見てセットアップを済ませておいてください。

## ボードの選択

メニューの`ツール` > `ボード` > `Nefry BT`を選択します。
この際、使っているリビジョンに合わせて選択してください。
例えば、使っている基板がR2の場合は`ツール` > `ボード` > `Nefry BT R2`を選択します。

![](https://i.gyazo.com/0b6439948f14c13edf7b5af4254a7ab5.png)

### Nefry BT R2以降の場合

[Nefry BTのバージョン（リビジョン）をチェック](/docs/nefrybt-revision-check/)を参考に、Nefry BTの背面を確認してください。 R2の場合は以下のように選択します。

![](https://i.gyazo.com/effa26bf4877f9821ad2678cd49083ae.png)

## Nefry BTをPCのUSBポートにさしてください。

* Nefry BTをPCのUSBポートにさしてください。
* メニューの`ツール` > `シリアルポート` > `/dev/cu.usbserial-xxxxxx` を選択します。環境によっては `/dev/tty.usbserial-xxxxxx`などの場合もあります。

(Windowsだと表記が違うようです。)

## プログラムの書き込み

メニューの`ファイル` > `新規ファイル`を選択します。

以下のようなウインドウが表示されます。

![](https://i.gyazo.com/64ebbce11ab3b3efacfd83c86c194483.png)

初期状態で書かれている現状のコードを削除して、以下のコードに差し替えましょう。

```
#include <Nefry.h>
//フルカラーLED　ランダムにカラーが変わります。
#define SEED_PIN A0

void setup() {
  randomSeed(analogRead(SEED_PIN));
}

int red,green,blue;
void loop() {
  red=random(255);//random関数は0-255の数値をランダムに返します。
  green=random(255);
  blue=random(255);
  Nefry.setLed(red,green,blue);//LEDがランダムに点灯します。
  String color="Red:";color+=red;
  color+=" Green:";color+=green;
  color+=" Blue:";color+=blue;
  Nefry.ndelay(1000);//1秒待つ
}
```

`A0`を指定していますが、乱数のSeed用に使っているだけで内蔵のLEDが`A0`という訳ではないです。

![](https://i.gyazo.com/fa18b49acacf5f71425078a96ae4c470.gif)

## プログラムの保存とボードに書き込み

左上の`→`ボタンを押してボード（Nefry BT）にプログラムを書き込みます。

## 確認

無事にプログラム書き込みが終わると、Nefry BTに内蔵してあるLEDがカラフルに光ります。

お疲れ様でした。
