= LINE Notifyと連携しよう

この章ではNefryとLINE Notifyを連携する方法を紹介します。

プログラミング編などで、Nefry BTを購入後にプログラムを書き換えた場合は、@<chap>{10DefaultProgram}の手順でデフォルトプログラムの書き込みをしておいてください。

合わせて、Nefry BTの無線LANの設定をしていない場合は、@<chap>{11NefryWiFi}の手順で無線LANの設定をしておいてください。

== LINE Notifyとは

LINE Notifyは、色々なWebサービスからLINEにメッセージを送ることができるサービスです。

//image[line01][LINE Notifyとは][scale=0.8]{
//}
手軽に個人やグループにLINEメッセージを送れるこの仕組みを使って、@<strong>{Nefry BTのスイッチを押したらLINEに通知が来る仕組みを紹介}します。

== LINE Notifyと友達になる
LINE Notifyのサイト（@<href>{https://notify-bot.line.me/my/}）にアクセスし、@<img>{line01}部分のQRコードを読み取ってLINE Notifyアカウントと友達になりましょう。

連携後はLINE NotifyアカウントからLINEメッセージが届くようになります。

== LINE Notifyのトークンを取得する

//image[line02][LINEトークンを発行する][scale=0.8]{
//}
LINE Notify上でトークンを取得します。LINE Notifyのサイトにアクセスしたら、画面下部の「トークンを発行する」を選択します。

//image[line03][トークンの詳細を設定][scale=0.8]{
//}
「トークンを発行する」をクリックするとウィンドウが表示されます。
「トークン名を記入してください」と書いてあるフォームに、メッセージが届くときのタイトルを入力します。Nefry BTから来たことがわかる名前がオススメです。

タイトルを決めたら、メッセージを送信するトークルームを選択します。

1対１で受け取ることもできますし、既存のグループにメッセージを送ることもできます。これはお好みで選んでください。
特にこだわりがなければ「1:1でLINE Notifyから通知を受け取る」を選択しましょう。

選択したら「発行する」を選択します。

//image[line04][トークン取得][scale=0.8]{
//}
このトークンを使ってNefryからLINEにメッセージを送ります。
このタイミングで、LINEアプリ側にも「Personal Access Tokenを発行しました。」といった通知も来るはずです。

このトークンはLINE Notifyが設定したチャットグループや自分のアカウントに対して通知を行う認証キーなので、他の人には知られないようにしましょう。

@<strong>{再発行はできないので、トークンはコピーして控えておいてください。}


== LINE Notifyのトークンを設定する

//image[line05][NefrySettingPage][scale=0.8]{
//}
@<chap>{11NefryWiFi}を参考に、Nefry BTのWebコンソール画面を開き、「Data Store」を選択します。

//image[line06][DataStoreに登録します][scale=0.6]{
//}
ここで「LINE Auth」の項目に@<img>{line04}で取得したLINE Notifyのトークンを貼り付けましょう。
また、「LINE Message」の項目に通知させたいメッセージを入力します。

それぞれ入力を終えたら「Save」を選択して保存します。

データを保存するためにNefryが再起動します。

再起動が終れば、設定は完了です。

== LINE通知を試す

Nefry BTのスイッチ（ResetではなくSWと書いてある方）を押してみましょう。

//image[line08][LINEの通知画面][scale=0.4]{
//}

しばらくするとこのようにLINE Notify経由でLINEに通知がきます。

無事に届けばこの章は終了です。

もし届かない場合、次の点を確認してください。

 * ネットワークに繋がっているか
 * トークン情報が間違っていないか

環境によってはネットワークに接続するのに時間がかかる場合もあるので、Nefry BTが起動してから1分程待ってからスイッチを押してみることも試してみてください。
