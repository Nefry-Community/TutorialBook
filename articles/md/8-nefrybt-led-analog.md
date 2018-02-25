+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 10
slug = "nefrybt-led-analog"
title = "Nefry BTで通常のアナログLEDのLチカを試す"
title_eng = "about Nefry BT"
description = "Nefry BTの開発の最初のステップとしてLチカプログラムを動かしてみましょう。通常のアナログLEDを使います。"
draft = false
doctype = ["nefrybt"]
date = "2017-08-22T01:02:41+09:00"
+++

このページではNefry BTでLEDを制御する方法を紹介します。

![](https://i.gyazo.com/58d5ff01a0669eb82394d41af9afb214.gif)

事前に、Nefry BTに組み込まれているフルカラーLEDを利用したLチカを[こちらのドキュメント](/docs/nefrybt-led)を参照して試してみましょう。

ちなみにNefryBTのピンでD0とD1がありますが、その二つのピンはディスプレイの制御(I2C通信)のために使用されているため正常に動作しないことがあります。（←Nefry BT R2で修正しました。）


## アナログLED

通常のLEDです。

LEDについては[こちらのドキュメント](/docs/led/)を参照してください。

## 配線

Nefry BTのA1ピンソケットにカソード（+側、足の長い方）ピンを、隣のGNDピンソケットにアノード（-側、足の短い方）

## コード

以下のコードでこのページ上部のようなLEDの点滅になります。

```
#define LED_PIN A1
#define DELAY_TIME 1000

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_PIN, LOW);
  delay(DELAY_TIME);
}
```
