+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 7
slug = "nefrybt-line-notify"
title = "Nefry BTからLINE通知をする"
title_eng = "about Nefry BT"
description = "Nefry BTからLINEに通知する仕組みを紹介します。"
draft = false
doctype = ["nefrybt"]
date = "2017-07-25T01:02:41+09:00"
+++

このページではNefry BTにデフォルトで書き込まれているプログラムを利用して、LINEに通知する仕組みを紹介します。

**プログラミング不要でLINE通知までできます。**

## LINE Notifyとは

![](https://i.gyazo.com/109f4aa667871bcdb82342d6e2ac3233.png)

色々なサービスからのLINEに通知する仕組みです。
今回はこの仕組みを使って**Nefry BTのスイッチを押したらLINEに通知が来る仕組みを紹介**します。

## LINE Notifyと友達になる

↑の画面キャプチャにあるQRコードを読み取って**LINE Notifyアカウントと友達になりましょう。**

## LINE Notifyのトークンを取得する

[こちら](https://notify-bot.line.me/my/)からトークンを取得できます。

URLにアクセスしたら、画面下部の`トークンを発行する`を選択します。

![](https://i.gyazo.com/2ebc6d9f716ba319bcf8322d44d095d0.png)

以下のようなモーダルウィンドウが表示されます。

![](https://i.gyazo.com/c74fe282bae7c550afd842f4912a838c.png)

`トークン名を記入してください`と書いてあるフォームに`任意の文字列`を入力し、通知を送信するトークルームを選択します。とりあえず今回は`1:1でLINE Notifyから通知を受け取る`を選択しましょう。

ちなみに、グループチャットを選択すればグループチャットに通知させることもできます。

選択したら`発行する`を選択します。

次の画面でトークンが表示されます。

![](https://i.gyazo.com/ae9a2dcdd6c1ba9d5b30d31d9b1a0ff3.png)

このタイミングで、LINEアプリ側にも`Personal Access Tokenを発行しました。`などの通知も来るはずです。

このトークンはLINE Notifyが設定したチャットグループや自分のアカウントに対して通知を行う認証キーなので、他の人には知られないようにしましょう。

**トークンはコピーして控えておいてください。**


## Nefry BTをWi-Fiに接続する

[こちらの記事](/blog/nefry-ifttt-push-line/)などを参考にNefry BTをWi-Fiに接続してください。
接続できたらIPアドレスを確認しましょう。
ディスプレイを接続している場合はディスプレイにIPアドレスが表示されます。

## 設定画面にアクセスする

筆者がの環境ではIPアドレスが`192.168.43.44`でした。
同じWi-Fiに接続しているPCやスマートフォンなどのブラウザから`http://192.168.43.44`にアクセスします。（各自の環境によって読み替えてください。）

![](https://i.gyazo.com/64288e03650616dfa32b1ee32fb080d5.png)

このような設定画面が表示されます。

## LINE Notifyのトークンを設定する

設定画面から`Data Store`を選択します。

すると次のような設定画面になります。

![](https://i.gyazo.com/295505fd7f4eb5a65988eb6ed3385a03.png)

ここで`LINE Auth`の項目に**先ほどのLINE Notifyのトークン**を貼り付けましょう。
また、`LINE Message`の項目に通知させたいメッセージを入力して`Save`を選択して保存します。

![](https://i.gyazo.com/3b659226685adad768214ba700d21819.png)

このような画面に切り替わり、Nefry BTが再起動します。

これで設定は完了です。

## LINE通知を試す

Nefry BTのスイッチ（ResetではなくSWと書いてある方）を押してみましょう。
このとき、1秒程度の長押しの方が良いかもしれません。

![](https://i.gyazo.com/1a1e9a4a9c93e3e2b233fbc6f510cdb0.png)

するとこのようにLINE Notify経由でLINEに通知がきます。

お疲れ様でした。