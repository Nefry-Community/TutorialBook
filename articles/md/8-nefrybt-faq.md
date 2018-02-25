+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 100
slug = "nefrybt-faq"
title = "よくある質問と回答"
title_eng = "Frequently Asked Questions"
description = "Nefry BTを利用していてよくある質問と回答をまとめていきます。"
draft = false
doctype = ["nefrybt"]
date = "2017-10-30T01:02:41+09:00"
+++

## Nefry BTを初期状態に戻したい

[こちらのデフォルトプログラム](/docs/nefrybt-line-notify/#付録-デフォルトプログラム)を書き込んで下さい。

## Arduino IDEでNefry BTの開発環境が追加できない

### プロキシ......

[こちらのやりとり](https://www.facebook.com/groups/nefry/permalink/1506737526047045/)をもとにプロキシ設定などを見直して下さい。

**会社や大学内など制限のかかっている環境で失敗する可能性があります。**
ネットワークを変えて試してみましょう

## Arduino IDEでのコンパイルに失敗する

### MATLAB......

MATLABが入っているPCでコンパイルが失敗するという報告を受けています。

```
In file included from
C:\ProgramData\MATLAB\SupportPackages\R2017a
\3P.instrset\arduinoideinstrset\idepkgs\packages
\Nefry(ESP32)\hardware\esp32\1.0.6\cores\esp32\Esp.cpp:25:0:

c:\programdata\matlab\supportpackages\r2017a\3p.instrset
\arduinoide.instrset\idepkgs\packages\nefry(esp32)\tools\xtensa-esp32-elf-gcc\1.22.0-61-gab8375a-5.2.0
\xtensa-esp32-elf\include\c++\5.2.0\memory:62:31:

fatal error: bits/stl_algobase.h: No such file or directory
 
compilation terminated.
 
exit status 1
ボードNefry BTに対するコンパイル時にエラーが発生しました。
```

報告を受けた事象では、MATLABの入っているPCの`C:\ProgramData\MATLAB\...`などのパスのものを一時的にゴミ箱などにいれて再起動、Arduino IDEの再インストールを行い、その後MATLABをもとの場所に戻すことで解決したとのことです。


## Nefry BTが動かなくなってしまった

[こちらのやりとり](https://www.facebook.com/groups/nefry/permalink/1490278071026324/)をもとに空のプログラムを書き込んでみて下さい。

## その他

随時更新してきます！！！