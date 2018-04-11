= IFTTTと連携しよう

この章ではNefryとIFTTTを連携する方法を紹介します。

プログラミング編などで、Nefry BTを購入後にプログラムを書き換えた場合は、@<chap>{10DefaultProgram}の手順でデフォルトプログラムの書き込みをしておいてください。

合わせて、Nefry BTの無線LANの設定をしていない場合は、@<chap>{11NefryWiFi}の手順で無線LANの設定をしておいてください。

== IFTTTとは

IFTTTはLINE、Twitter、GMailなどを始めとしたさまざまなWebサービス同士を、ノンプログラミングで簡単に連携できるサービスです。
連携したものは「レシピ」と呼ばれ、誰かが作ったレシピを使ったり、自分で新しいレシピを作成したりできます。

//image[ifttt_action20][IFTTT公式ページ][scale=0.8]{
//}

IFTTT公式ページ（@<href>{https://ifttt.com/}）

Nefry BTとIFTTTの連携は、次の手順で進めていきます。

 1. IFTTTでレシピを作成します。今回は「WebhooksとTwitterを連携」するレシピです。
 2. Nefry BTとIFTTTが通信するために必要な、IFTTTの「Secret Key」を取得します。
 3. Nefry BTの設定ページから、Secret Keyとレシピ情報を登録します。
 4. Nefryのスイッチを押してTwitterにメッセージを送ります！

== IFTTTにレシピを作成する
まずはIFTTTにレシピを作成します。
IFTTTのアカウントを持っていない場合はサイト上部の「Sing up」のリンクからアカウントを取得して進めてください。

IFTTTのレシピは「〇〇したら△△する」というようにトリガー（〇〇）とアクション（△△）に分けられます。

今回はトリガーとして、自作のWebhook@<fn>{Webhook}を利用できる「Webhooks」を使います。
Nefry BTからWebhooksにリクエストを送ると、指定したアクションが発動するようになります。

Nefry BT側のデフォルトプログラムには「スイッチを押すとIFTTTのWebhooksにリクエストを送る」という処理が書かれています。

=== トリガー（〇〇したら）の作成

IFTTTのサイト上部の「My Applet」をクリックし、「New Applet」をクリックするとレシピ作成ページ（@<href>{https://ifttt.com/create}）が開かれます。

//image[ifttt_trigger1][トリガーを作成します][scale=0.6]{
//}
そこから「@<strong>{+this}」部分をクリックし、トリガーの作成をします。

//image[ifttt_trigger2][Webhooks追加][scale=0.6]{
//}
IFTTTに多数あるサービスから目的のものを探すのは大変なので、検索欄から「Webhooks」を検索しましょう。

見つかったら「Webhooks」をクリックします。

//image[ifttt_trigger3][イベント名指定][scale=0.6]{
//}
任意のイベント名をつけます。後ほどNefry BTにも登録するので覚えておきましょう（@<strong>{大文字小文字の区別があるので注意！}）。
特にこだわりがなければ「Nefry_IFTTT」と入力しましょう。

入力が終わったら「Create trigger」をクリックして次に進みます。

=== アクション（△△する）の作成

//image[ifttt_action1][アクション作成][scale=0.6]{
//}
「@<strong>{+that}」からアクションを作成します。
Nefry BTのスイッチを押したら実行したいWebサービスを自由に選びます。

//image[ifttt_action2][サービス選択][scale=0.6]{
//}
今回はチュートリアルとしてTwitterを連携してみましょう
（連携するWebサービスのアカウント情報が登録されてない場合登録画面がでるのでそこで登録する必要があります）。

Twitterのアイコンをクリックして次に進みます。

//image[ifttt_action3][Tweetするようにします][scale=0.6]{
//}
Twitter上で起こしたいアクションを選びましょう。
選択したサービスによってできることはさまざまです。

Twitterだと、写真を付けたTweetをすることやDMを送ることができますが、今回はシンプルに「Post a tweet（Tweetする）」をクリックします。

//image[ifttt_action4][アクションを作成します][scale=0.6]{
//}
Tweetする内容を入力し、「Create action」をクリックします。

===[column] IFTTTでTwitter連携するときの注意ポイント！

Twitterでは同じ文字列を連続して投稿することができません。

それでは困ることもあると思います。
オススメは投稿時間をつけてTweetすることです。

//image[ifttt_tips][投稿時間を追加する][scale=0.4]{
//}
方法は「Add　ingredient」をクリックし、「OccurredAt」をクリックすると投稿時間をつけて一緒にTweetしてくれます。
うまく活用して上手なTwitter連携をしてみてください！

===[/column]

新しいレシピができました！

//image[ifttt_action5][作成完了][scale=0.6]{
//}
「Webhooksを受け取ったらTweetする」というレシピです。
「Finish」で完了します。

== WebhooksのSecret Keyを取得

NefryとWebhooksと紐付けるための「Secret Key」を取得します。

//image[ifttt_discover1][検索][scale=0.6]{
//}
IFTTTサイト上部のSearch（@<href>{https://ifttt.com/discover}）からWebhooksを検索しましょう。

//image[ifttt_discover2][Settings選択][scale=0.6]{
//}
Webhooksのページに移動します（初回は認証画面が表示されるので「Connect」で開始しましょう）。

右上の「Setting」に移動します。

//image[ifttt_discover3][SecretKey取得][scale=0.6]{
//}
「URL」の末尾（…/use/の後ろ）に自身のSecret Keyが記載されているのでコピーしましょう！

== Nefry BTにSecret Keyを登録する
あらかじめ@<chap>{11NefryWiFi}で無線LANの設定を済ませておいてください。

//image[ifttt_setup1][WebコンソールでData Storeを開く][scale=0.6]{
//}
@<chap>{11NefryWiFi}の方法でNefry BTのWebコンソールを開き、「Data Store」を選択します。

//image[ifttt_setup2][保存][scale=0.6]{
//}
先ほど取得したWebhooksの「Secret Key」と「Event Name」をそれぞれ入力を終えたら「Save」を選択して保存します。

データを保存するためにNefryが再起動します。

再起動が終れば、設定は完了です。

//image[nefry_ifttt][実行してみよう][scale=0.8]{
//}
Nefry BTのスイッチ（ResetではなくSWと書いてある方）を押してみましょう。

スイッチを押すとTweetできました（IFTTTのサーバ状況により最大15分ほどタイムラグがある場合があります）！

無事にTweetされればこの章は終了です。

もし届かない場合、次の点を確認してください。

 * ネットワークに繋がっているか
 * Eventの名前が間違っていないか（大文字小文字の区別があります）
 * トークン情報が間違っていないか

環境によってはネットワークに接続するのに時間がかかる場合もあるので、Nefry BTが起動してから1分程待ってからスイッチを押してみることも試してみてください。


===[column] IFTTT応用話

IFTTTには数多くのサービスがあり、選択するだけでごく簡単に連携することができます。
何をどう連携させるか、自分好みに実際にいろいろ試してみると大変面白いと思います。

今回の説明では、Nefry BTの動作をきっかけにTwitterにメッセージを送りましたが、逆にTwitterの投稿をきっかけにNefry BTにアクションを起こしたい！ということもあると思います。

この本では詳しくは解説しませんが、Nefryクラウドというサービスを使うと、他をトリガーにしてNefry BTを動かすことができます。
興味がある方はQiitaで「Nefryクラウド（仮）をつくってみた」という記事を参照して試してみてください。

===[/column]

//footnote[Webhook][任意のイベント（今回はNefry BTのボタン押下）が発生した時、指定したURLにリクエストを送る仕組み]
