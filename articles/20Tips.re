
= Tips


この章では、Nefry BTに関するTipsを幾つか挙げてみます。


== Nefry BTについて


@<strong>{Nefry BTを初期状態に戻したい}


//quote{
こちらのデフォルトプログラム（https://dotstud.io/docs/nefrybt-default/）を書き込んで下さい。

//}


@<strong>{PCがNefry BTを認識できない}


//quote{
Nefry BTのUSBシリアル変換チップ（FTDI）のドライバーがPCにインストールされていない場合は、FTDIのページ（http://www.ftdichip.com/Drivers/VCP.htm）からドライバーをダウンロードしてインストールしてみて下さい。



それでもNefry BTを認識できなかったり、何らかの理由でPCに接続できない場合は、Nefry BTのWebコンソールからプログラムを書き込んだり、シリアルモニタを確認できたりしますので、そちらもご利用下さい。

//}


@<strong>{ディスプレイがつかない}


//quote{
ディスプレイピンがずれていないでしょうか？

//}


@<strong>{Nefry用の関数が動かない}


//quote{
@<tt>{#include <Nefry.h>}を書くのを忘れていませんか？また、必要なライブラリの記載はしてありますか？

//}


@<strong>{UART Groveが動かない}


//quote{
Nefry BTではGroveポートでUARTはできない仕様になっています。

//}


@<strong>{ボタンが反応しない！なぜか再起動してしまう}


//quote{
リセットボタンを押していませんか？

//}


@<strong>{困ったときは}


//quote{
Facebookのコミュニティ「Nefryユーザーグループ」（https://www.facebook.com/groups/nefry/）に参加して、質問をしてみましょう。

//}

== 開発に関して


@<strong>{本体（コア）のリポジトリ}


//quote{
コアのソースコードはGitHubリポジトリ（https://github.com/Nefry-Community/arduino-esp32/）で管理されています。
プルリクエストやIssueの追加などはどなたでも行えますので是非投稿して下さい。

//}


@<strong>{コアへのコミット}


//quote{
Gitter（https://gitter.im/Nefry-Community/）でディスカッションが行われています。
興味のある方はジョインしてみましょう！

//}
