

+++
author = "chantoku"
author@<b>{username = "ちゃんとく"
weight = 7
slug = "nefrybt-ifttt"
title = "Nefry BTとIFTTTを連携する"
title}eng = "connect with IFTTT"
description = "Nefry BTとIFTTTを連携する仕組みを紹介します。"
draft = false
doctype = ["nefrybt"]
date = "2017-07-26T01:02:41+09:00"
+++



Nefry BTにはデフォルトで、Nerfy BTのボタンを押すと連携したIFTTTにデータを送信するプログラムが書かれています。@<strong>{プログラミング不要でIFTTTの様々なウェブサービスと連携することができます。}



始める前に、@<href>{/docs/nefrybt-wifi-setup/,Nefry BTのWi-Fiセットアップ}を参考に、Wi-Fi情報を設定しNefry BTのIPアドレスを取得しておきましょう。


== IFTTTとは


<center>
//image[ifttt_action2][]{
//}

@<href>{https://ifttt.com/,IFTTT公式ページ}
</center>



IFTTTはLINE, Twitter, Slackを始めとした様々なWebサービス同士を簡単に連携できるサービスです。連携したものは「レシピ」と呼ばれ、自分で新しいレシピを作成することもできます。



Nefry BTとIFTTT連携の手順は、IFTTTにレシピを作成して「Secret Key」を取得し、Nefry BTの設定ページからキーを登録する流れになります。


== IFTTTにレシピを作成する


まずはIFTTTにレシピを作成します。IFTTTのアカウントを持っていない場合はアカウント取得から進めてください。



IFTTTのレシピは「〇〇が起きたら△△する」というようにトリガー（〇〇）とアクション（△△）に分けられます。



今回はトリガーとして自作のWebサービスを利用できる「Webhooks」を使います。Webhooksにアクセスがあったら発動するようになっており、Nefry BT側には「ボタンを押すとIFTTTのWebhooksにアクセスする」という初期プログラムが書かれています。


=== トリガーの作成


@<href>{https://ifttt.com/create,IFTTTのレシピ作成ページ}から「@<strong>{+this}」部分をクリックし、トリガーの作成をします。
//image[ifttt_trigger1][]{
//}




「Webhooks」を検索しましょう。
//image[ifttt_trigger2][]{
//}




任意のイベント名をつけます。後ほどNefry BTにも登録するので覚えておきましょう。
//image[ifttt_trigger3][]{
//}



=== アクションの作成


続いてアクションを作成します。「@<strong>{+that}」から進めましょう。
//image[ifttt_action1][]{
//}




Nefry BTのボタンを押したら実行したいWebサービスを自由に選びます。今回はサンプルとしてTwitterを連携してみます。
//image[ifttt_action2][]{
//}




起こしたいアクションを選びましょう。今回は「Post a tweet（Tweetする）」を選んでみます。
//image[ifttt_action3][]{
//}




Tweetする内容を入力し、「Create action」をクリックします。
//image[ifttt_action4][]{
//}




新しいレシピができました！「Webhooksを受け取ったらTweetする」というレシピです。「Finish」で完了します。
//image[ifttt_action5][]{
//}

（連携するWebサービスのアカウント情報は登録する必要があります。）


=== WebhooksのSecret Keyを取得


Nefry BTとWebhooksと紐付けるための「Secret Key」を取得します。@<href>{https://ifttt.com/discover,IFTTTのTOPページ}からWebhooksを検索しましょう。
//image[ifttt_discover1][]{
//}




Webhooksのページに移動します。（初回は認証画面が表示されるので「Connect」で開始しましょう。）右上の「Setting」に移動します。
//image[ifttt_discover2][]{
//}




「URL」の末尾に自身のSecret Keyが記載されているのでコピーしましょう！
//image[ifttt_discover3][]{
//}



== Nefry BTにSecret Keyを登録する


Nefry BTを起動し、IPに繋いで設定ページを開きます。（IPがわからない方は@<href>{/docs/nefrybt-wifi-setup/,Nefry BTのWi-Fiセットアップ}を参考にしてください。）「Data Store」に移動します。
//image[ifttt_setup1][]{
//}




先ほど取得したWebhooksの「Secret Key」と「Event Name」をそれぞれ入力し保存します。
//image[ifttt_setup2][]{
//}




Nefry BTのボタンを押して試してみましょう！
//image[nefry_ifttt][]{
//}

ボタンを押すとTweetする連携ができました！（IFTTTのサーバ状況により送信に時間がかかる場合があります。）

