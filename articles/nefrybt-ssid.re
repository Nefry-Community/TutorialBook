

+++
author = "n0bisuke"
author@<b>{username = "のびすけ"
weight = 5
slug = "nefrybt-change-ssid"
title = "Nefry BTのSSIDを変更する"
title}eng = "How to Change the SSID"
description = "Nefry BTが発信するSSIDは任意の名前に変更することができます。その手順を紹介します。"
draft = false
doctype = ["nefrybt"]
date = "2017-09-19T01:02:41+09:00"
+++



このページでは、Nefry BTのSSIDを変更する方法を紹介します。



@<strong>{Nefry BTが複数台ある場合}やNefry BTを使っての@<strong>{ハンズオンイベントなどを行うときに役立つ項目です。}


== Nefry BTのSSID


Nefry BTを起動すると@<tt>{NefryBT-XXXX}というIDがディスプレイに表示されます。



//image[adae1fad9391ad899e193e97eb659c5a][]{
//}




ディスプレイがない場合は、PCなどで近くのSSIDを調べると、こちらでも表示が確認できます。



//image[9b2e2ee7f0e3a30625474095a39edf7d][]{
//}




このSSIDを変更することで自分のNefry BTを認識することができます。


== Nefry BTのWi-Fiセットアップ


先に@<href>{/docs/nefrybt-wifi-setup/,こちらのドキュメント}を見て、Nefry BTをWi-Fiに接続しておくか、Nefry BTのWi-Fiに接続して http://192.168.4.1 から管理画面を開きましょう。


== 変更の仕方


先ほど同様に@<href>{/docs/nefrybt-wifi-setup/,Nefry BTのWi-Fiセットアップドキュメント}を見つつNefry BTの管理画面で@<tt>{Module Config}を選択します。



//image[622ffa17c65cccc1601d8f5b5a2b28b3][]{
//}




@<tt>{Module ID}の箇所を任意の文字列に書き換えましょう。



//image[29173979eac31b196003f46bcc6aa096][]{
//}




今回は@<tt>{NefryBT-n0bisuke}に変更してみました。変更したら@<tt>{Saveボタン}を押しましょう。



//image[11b0f67ae9ff5bed0d9e7e52d5923f63][]{
//}




Nefry BTが再起動します。



//image[bd919aa1cbe8bd2f081fb6b5f8160645][]{
//}



== 確認


無事に設定が完了するとディスプレイに表示されるSSIDの名前が変わります。



//image[daae4b53b74596e726e0cb59e1c3553e][]{
//}




PCで表示されるSSIDも変更されています。



//image[3046c0fa6951446d4b1a6a1ca84c49e4][]{
//}



== おまけ


SSIDを日本語にすることも可能です。



//image[0cd41c44fac4eb8515c44778b60065b5][]{
//}


