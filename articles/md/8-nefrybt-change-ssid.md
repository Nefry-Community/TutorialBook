+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 5
slug = "nefrybt-change-ssid"
title = "Nefry BTのSSIDを変更する"
title_eng = "How to Change the SSID"
description = "Nefry BTが発信するSSIDは任意の名前に変更することができます。その手順を紹介します。"
draft = false
doctype = ["nefrybt"]
date = "2017-09-19T01:02:41+09:00"
+++

このページでは、Nefry BTのSSIDを変更する方法を紹介します。

**Nefry BTが複数台ある場合**やNefry BTを使っての**ハンズオンイベントなどを行うときに役立つ項目です。**

## Nefry BTのSSID

Nefry BTを起動すると`NefryBT-XXXX`というIDがディスプレイに表示されます。

![](https://i.gyazo.com/adae1fad9391ad899e193e97eb659c5a.png)

ディスプレイがない場合は、PCなどで近くのSSIDを調べると、こちらでも表示が確認できます。

![](https://i.gyazo.com/9b2e2ee7f0e3a30625474095a39edf7d.png)

このSSIDを変更することで自分のNefry BTを認識することができます。

## Nefry BTのWi-Fiセットアップ

先に[こちらのドキュメント](/docs/nefrybt-wifi-setup/)を見て、Nefry BTをWi-Fiに接続しておくか、Nefry BTのWi-Fiに接続して http://192.168.4.1 から管理画面を開きましょう。

## 変更の仕方

先ほど同様に[Nefry BTのWi-Fiセットアップドキュメント](/docs/nefrybt-wifi-setup/)を見つつNefry BTの管理画面で`Module Config`を選択します。

![](https://i.gyazo.com/622ffa17c65cccc1601d8f5b5a2b28b3.png)

`Module ID`の箇所を任意の文字列に書き換えましょう。

![](https://i.gyazo.com/29173979eac31b196003f46bcc6aa096.png)

今回は`NefryBT-n0bisuke`に変更してみました。変更したら`Saveボタン`を押しましょう。

![](https://i.gyazo.com/11b0f67ae9ff5bed0d9e7e52d5923f63.png)

Nefry BTが再起動します。

![](https://i.gyazo.com/bd919aa1cbe8bd2f081fb6b5f8160645.png)

## 確認

無事に設定が完了するとディスプレイに表示されるSSIDの名前が変わります。

![](https://i.gyazo.com/daae4b53b74596e726e0cb59e1c3553e.png)

PCで表示されるSSIDも変更されています。

![](https://i.gyazo.com/3046c0fa6951446d4b1a6a1ca84c49e4.png)

## おまけ

SSIDを日本語にすることも可能です。

![](https://i.gyazo.com/0cd41c44fac4eb8515c44778b60065b5.png)