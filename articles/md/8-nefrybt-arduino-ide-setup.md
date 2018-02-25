+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 8
slug = "nefrybt-arduino-ide-setup"
title = "Nefry BT向けのArduino IDEセットアップ方法"
title_eng = "Arduino IDE Setup guide for Nefry BT"
description = "Nefry BTの開発をする際に行うArduino IDEのセットアップ方法を紹介します。"
draft = false
doctype = ["nefrybt"]
date = "2017-07-25T01:02:41+09:00"
+++

このページでは、Arduino IDEにNefry BTの開発環境をインストールする方法を紹介します。**Arduino IDEでNefry BTの開発をする際に必須になる項目です。**

Arduino IDEのインストールは[こちらのドキュメント](/docs/arduinoide-setup/)を参照してください。

## ボードマネージャの追加

メニューの`Arduino` > `Preferences`を選択します。環境設定のダイアログが開きます。

`追加のボードマネージャのURL`のフォームに以下のURLを追加しましょう。

```
http://nefry.studio/package_nefrybt_index.json
```

![](https://i.gyazo.com/97340ffab8e27b01fcaab1b4a1a7b0fd.png)

追加できたらOKを選択します。

## ボードマネージャを開く

メニューの`ツール` > `ボード` > `ボードマネージャ`を選択します。

![](https://i.gyazo.com/7aec4d50fe882e6faec6009492b03eea.png)

するとこのようなボードマネージャダイアログが表示されます。

![](https://i.gyazo.com/94270bbcce718a52061c544f39ea2c5e.png)

## Nefry BT用の開発環境を追加する

フォームに`Nefry`と入力して検索すると項目が表示されます。

![](https://i.gyazo.com/5232ee346a7232cdea75a96569333cc4.png)

`インストール`を押すとインストールが開始されます。

横のプルダウンメニューでバージョンを指定できますが、**[Nefry BTのライブラリ](/docs/nefrybt-library)を参考にバージョン選択**するようにしましょう。

![](https://i.gyazo.com/29a35f129c73926c160c1e948369308d.png)

あとはインストールが完了するまで待つだけです。

## 確認

メニューの`ツール` > `ボード`を選択したときに`Nefry BT`の項目が追加されていればOKです。

![](https://i.gyazo.com/0b6439948f14c13edf7b5af4254a7ab5.png)

Nefry BT R2以降は[Nefry BTのリビジョンのチェック](/docs/nefrybt-revision-check)を参考にして、`Nefry BT R2`を選択しましょう。

![](https://i.gyazo.com/effa26bf4877f9821ad2678cd49083ae.png)

お疲れ様でした。

次は、はじめてのプログラム書き込みの例として[Nefry BT付属のLEDでLチカ](/docs/nefrybt-led/)を試してみてください。
