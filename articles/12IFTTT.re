= IFTTTと連携しよう

この章ではNefryとIFTTTを連携するパターンを紹介します。

前もって、プログラムの書き換えを行った場合は@<chap>{10DefaultProgram}でプログラムの書き込みをしておいてください。

あわせて、無線LANの設定をしていない場合は@<chap>{11NefryWiFi}で無線LANの設定をしておいてください。

== IFTTTとは

//image[ifttt_action20][IFTTT公式ページ]{
//}

@<href>{https://ifttt.com/,IFTTT公式ページ}（@<href>{https://ifttt.com/}）

IFTTTはLINE, Twitter, Slackを始めとしたさまざまなWebサービス同士を簡単に連携できるサービスです。
連携したものは「レシピ」と呼ばれ、自分で新しいレシピを作成することもできます。

NefryとIFTTT連携の手順は次のとおり進めていきます。

 1.IFTTTでレシピを作成します。今回の場合はTwitterと連携するレシピを作成します。
 2.NefryとIFTTTが通信するために必要な「Secret Key」を取得します。
 3.Nefryの設定ページから上で取得したSecret Keyとレシピ情報を登録します。
 4.Nefryのスイッチを押してTwitterにメッセージを送ります！

== IFTTTにレシピを作成する

まずはIFTTTにレシピを作成します。
IFTTTのアカウントを持っていない場合はサイト上部の「Sing up」のリンクからアカウント取得から進めてください。

IFTTTのレシピは「〇〇が起きたら△△する」というようにトリガー（〇〇）とアクション（△△）に分けられます。

今回はトリガーとして自作のWebサービスを利用できる「Webhooks」を使います。
Webhooksにアクセスがあったら発動するようになっており、Nefry BT側には「スイッチを押すとIFTTTのWebhooksにアクセスする」という初期プログラムが書かれています。

=== トリガーの作成

IFTTTのサイト上部の「My Applet」をクリックし、「New Applet」をクリックすると@<href>{https://ifttt.com/create,レシピ作成ページ}が開かれます。

そこから「@<strong>{+this}」部分をクリックし、トリガーの作成をします。
//image[ifttt_trigger1][トリガーを作成します]{
//}

IFTTTに多数あるサービスから目的のものを探すのは大変ですので検索欄から「Webhooks」を検索しましょう。

見つかったら「Webhooks」をクリックしましょう。
//image[ifttt_trigger2][Webhooks追加]{
//}

任意のイベント名をつけます。

後ほどNefry BTにも登録するので覚えておきましょう。

特にこだわりがなければ「Nefry_IFTTT」と入力しましょう。
入力が終わったら「Create trigger」をクリックして次に進みます。

//image[ifttt_trigger3][イベント名指定]{
//}

=== アクションの作成

続いてアクションを作成します。

「@<strong>{+that}」から進めましょう。

//image[ifttt_action1][アクション作成]{
//}

Nefryのスイッチを押したら実行したいWebサービスを自由に選びます。

今回はチュートリアルとしてTwitterを連携してみましょう。

（連携するWebサービスのアカウント情報は登録されてない場合登録画面がでるのでそこで登録する必要があります。）

Twitterのアイコンをクリックして次に進みます。

//image[ifttt_action2][サービス選択]{
//}

起こしたいアクションを選びましょう。

選択したサービスによってできることはさまざまです。

Twitterだと、写真を付けたTweetすることやDMを送ることができますが、今回はシンプルに「Post a tweet（Tweetする）」を選んでクリックします。

//image[ifttt_action3][Tweetするようにします]{
//}

Tweetする内容を入力し、「Create action」をクリックします。

//image[ifttt_action4][アクションを作成します]{
//}

新しいレシピができました！

「Webhooksを受け取ったらTweetする」というレシピです。
「Finish」で完了します。
//image[ifttt_action5][作成完了]{
//}

== WebhooksのSecret Keyを取得

NefryとWebhooksと紐付けるための「Secret Key」を取得します。

@<href>{https://ifttt.com/discover,IFTTTサイト上部のSearch}からWebhooksを検索しましょう。
//image[ifttt_discover1][検索]{
//}

Webhooksのページに移動します。（初回は認証画面が表示されるので「Connect」で開始しましょう。）

右上の「Setting」に移動します。
//image[ifttt_discover2][Webhooks選択]{
//}

「URL」の末尾に自身のSecret Keyが記載されているのでコピーしましょう！
//image[ifttt_discover3][SecretKey取得]{
//}

== Nefry BTにSecret Keyを登録する
あらかじめ@<chap>{11NefryWiFi}で無線LANの設定を済ませておいてください。

@<chap>{11NefryWiFi}でNefryの設定画面にはいった方法で設定画面を開きます。
//image[ifttt_setup1][セットアップ]{
//}

先ほど取得したWebhooksの「Secret Key」と「Event Name」をそれぞれ入力し保存します。
//image[ifttt_setup2][保存]{
//}
Nefry BTのスイッチ（ResetではなくSWと書いてある方）を押してみましょう。

//image[nefry_ifttt][実行してみよう]{
//}

スイッチを押すとTweetする連携ができました！（IFTTTのサーバ状況により送信に時間がかかる場合があります。）

無事にメッセージが届けばこの章は終了です。

もし届かない場合Nefryがネットワークにつながっているかの確認やトークン情報が間違っていないかの確認をしましょう！

環境によってはネットワークに接続するのに時間のかかる場合もあるので起動完了の1分程度後にスイッチを押すのもよいかもしれません。
