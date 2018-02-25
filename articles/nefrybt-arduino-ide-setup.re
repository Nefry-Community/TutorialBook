

+++
author = "n0bisuke"
author@<b>{username = "のびすけ"
weight = 8
slug = "nefrybt-arduino-ide-setup"
title = "Nefry BT向けのArduino IDEセットアップ方法"
title}eng = "Arduino IDE Setup guide for Nefry BT"
description = "Nefry BTの開発をする際に行うArduino IDEのセットアップ方法を紹介します。"
draft = false
doctype = ["nefrybt"]
date = "2017-07-25T01:02:41+09:00"
+++



このページでは、Arduino IDEにNefry BTの開発環境をインストールする方法を紹介します。@<strong>{Arduino IDEでNefry BTの開発をする際に必須になる項目です。}



Arduino IDEのインストールは@<href>{/docs/arduinoide-setup/,こちらのドキュメント}を参照してください。


== ボードマネージャの追加


メニューの@<tt>{Arduino} > @<tt>{Preferences}を選択します。環境設定のダイアログが開きます。



@<tt>{追加のボードマネージャのURL}のフォームに以下のURLを追加しましょう。


//emlist{
http://nefry.studio/package_nefrybt_index.json
//}


//image[97340ffab8e27b01fcaab1b4a1a7b0fd][]{
//}




追加できたらOKを選択します。


== ボードマネージャを開く


メニューの@<tt>{ツール} > @<tt>{ボード} > @<tt>{ボードマネージャ}を選択します。



//image[7aec4d50fe882e6faec6009492b03eea][]{
//}




するとこのようなボードマネージャダイアログが表示されます。



//image[94270bbcce718a52061c544f39ea2c5e][]{
//}



== Nefry BT用の開発環境を追加する


フォームに@<tt>{Nefry}と入力して検索すると項目が表示されます。



//image[5232ee346a7232cdea75a96569333cc4][]{
//}




@<tt>{インストール}を押すとインストールが開始されます。



横のプルダウンメニューでバージョンを指定できますが、@<strong>{@<href>{/docs/nefrybt-library,Nefry BTのライブラリ\}を参考にバージョン選択}するようにしましょう。



//image[29a35f129c73926c160c1e948369308d][]{
//}




あとはインストールが完了するまで待つだけです。


== 確認


メニューの@<tt>{ツール} > @<tt>{ボード}を選択したときに@<tt>{Nefry BT}の項目が追加されていればOKです。



//image[0b6439948f14c13edf7b5af4254a7ab5][]{
//}




Nefry BT R2以降は@<href>{/docs/nefrybt-revision-check,Nefry BTのリビジョンのチェック}を参考にして、@<tt>{Nefry BT R2}を選択しましょう。



//image[effa26bf4877f9821ad2678cd49083ae][]{
//}




お疲れ様でした。



次は、はじめてのプログラム書き込みの例として@<href>{/docs/nefrybt-led/,Nefry BT付属のLEDでLチカ}を試してみてください。

