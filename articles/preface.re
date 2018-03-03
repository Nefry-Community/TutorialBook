= はじめに

今回はNefryのチュートリアル本を手に取っていただきありがとうございます。

この本ではNefryを始めるために必要な情報をギュギュっと濃縮してお伝えいたします！

ハードウエアとネットワークを使って新しい物語を生み出しましょう！

== 対象読者

 *  Arduino@<fn>{arduino}やRaspberry Pi@<fn>{raspberry}を使ったことのある方
 *  Webエンジニアなどのプログラミングはやったことのある方（ハードウエアは初心者）

 基本的にはこちらの対象に説明していこうと思っています。


 なるべくわかりやすいように書くようにしていますが、コードの書き方までは紹介しないのであらかじめご了承ください。

== 本書でできるようになること

 * Nefryのプログラムを書けるような環境を構築します
 * Nefryのサンプルプログラムを動かせるようになります
 * IFTTT@<fn>{ifttt}を用いて簡単なIoTを体験します
 * LINE Notifyを使ってLINEにメッセージを送ります

自分でプログラムを書き始めるにあたって必要な知識から紹介し、ハードウエアのプログラミングについて紹介します。

その後、IFTTTやLINE Notifyを使ってIoTがどんなものなのか紹介する手順で本書は進んでいきます。

時間がない場合はIoTを体験できる後半のみでも楽しめるようになっているのでぜひあきらめずにNefryで遊んでみてください。

== サンプルプログラムについて

本書で記載されているコードはすべてGitHubからダウンロードすることができます。

ダウンロードリンク : @<href>{https://github.com/Nefry-Community/TutorialExample}

ダウンロード先にインストール方法など記載されているので詳しくはそちらをご覧ください。
サンプルプログラムをダウンロードしなくても本書の内容を進めることは可能です。


//footnote[arduino][イタリア生まれのハードウエアをソウトウエアとセットで簡単に触れるようにしたボード]
//footnote[raspberry][イギリス生まれの小型PC、Linuxが動きハードウエアの制御もできるボード]
//footnote[ifttt][たとえば、「もし金曜日ならゴミ捨てするようにメールを送る」といった指定の条件が起きた時に別のものを動かすことが簡単にできるWebサービス]
