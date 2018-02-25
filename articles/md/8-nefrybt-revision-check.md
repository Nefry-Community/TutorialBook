+++
author = "n0bisuke"
author_username = "のびすけ"
weight = 3
slug = "nefrybt-revision-check"
title = "Nefry BTのバージョン（リビジョン）をチェック"
title_eng = "about Check Nefry BT revision"
description = "Nefry BTのバージョンをチェックしましょう"
draft = false
doctype = ["nefrybt"]
date = "2018-01-04T01:02:41+09:00"
+++

Nefry BTがお手元に届いたら、まずはバージョンを確認しましょう！

現在（2018年1月）Nefry BTは無印のもの(R1)とR2が存在します。

ちなみに、[Nefry v2](/docs/nefry/)が存在するので区別するために、VersionではなくRivisionとしました。

![](https://i.gyazo.com/257b27625fce42629cd52e8e56792dd1.jpg)

背面に**R2**の文字があればR2で無ければ無印となります。

2018年1月以降に出荷しているものは基本的にR2となっています。

基本的な使い方に代わりはないですが、 [Arduino IDEでの書き込み](/docs/nefrybt-arduino-ide-setup/)の際の指定の仕方が少し変わります。

![](https://i.gyazo.com/effa26bf4877f9821ad2678cd49083ae.png)

書き込み時のボード選択でR2の場合は`Nefry BT R2`を選択し、無印の場合は`Nefry BT`を選択して書き込みをして下さい。