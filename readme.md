# data_structure_for_c

## これなに
C言語用のデータ構造ライブラリです。  
主に自分が競プロとかで使う用です。[^1]  
多分車輪の再+発明です。

## 各種仕様
* C11を想定
	* 競プロならだいたいC11かな……？
* 構造体は全てtypedefしてあります
	* 競プロは少しでも記述量を削りたいので
* データの型は全てintです
	* 他の型(char\*やstruct foo\*など)を扱いたい場合はインクルードではなくコピペして書き換えて頂ければ
	* ユーザー定義型も包括的に扱えるジェネリクスが欲しい……
* 命名規則はJavaに近い感じです
	* 伝統的なC言語の記法からは外れていると思います
* 色々雑です
	* 特に分かりづらい部分あればIssue投げてください

## ファイル一覧
ファイル名がAPI仕様書にリンクする予定です。
(括弧はまだ実装すらしていないファイル)

* (linkedlist.h)
* [queue.h](doc/queue.md)
* (stack.h)

[^1]:なんでCで競プロやってるんだろう……
