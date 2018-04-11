# Tips

この章では、Nefry BTに関するTipsを幾つか挙げてみます。


## Nefry BTについて

**Nefry BTを初期状態に戻したい**

> こちらのデフォルトプログラム（https://dotstud.io/docs/nefrybt-default/）を書き込んで下さい。


**PCがNefry BTを認識できない**

> Nefry BTのUSBシリアル変換チップ（FTDI）のドライバーがPCにインストールされていない場合は、FTDIのページ（http://www.ftdichip.com/Drivers/VCP.htm）からドライバーをダウンロードしてインストールしてみて下さい。
>
> それでもNefry BTを認識できなかったり、何らかの理由でPCに接続できない場合は、Nefry BTのWebコンソールからプログラムを書き込んだり、シリアルモニタを確認できたりしますので、そちらもご利用下さい。


**ディスプレイがつかない**

> ディスプレイピンがずれていないでしょうか？


**Nefry用の関数が動かない**

> `#include <Nefry.h>`を書くのを忘れていませんか？また、必要なライブラリの記載はしてありますか？


**UART Groveが動かない**

> Nefry BTではGroveポートでUARTはできない仕様になっています。


**ボタンが反応しない！なぜか再起動してしまう**

> リセットボタンを押していませんか？


**困ったときは**

> Facebookのコミュニティ「Nefryユーザーグループ」（https://www.facebook.com/groups/nefry/）に参加して、質問をしてみましょう。


## 開発に関して

**本体（コア）のリポジトリ**

> コアのソースコードはGitHubリポジトリ（https://github.com/Nefry-Community/arduino-esp32/）で管理されています。
プルリクエストやIssueの追加などはどなたでも行えますので是非投稿して下さい。

**コアへのコミット**

>Gitter（https://gitter.im/Nefry-Community/）でディスカッションが行われています。
興味のある方はジョインしてみましょう！
