# icpc_env

競技プログラミング用の作業環境。よく使う補助スクリプトの簡単な使い方をまとめる。

共通のコンパイルオプションは以下（`cmp -t` のみ `-DDEBUG` 付き）。

```
g++ <file> -std=c++20 -I. -O2 -D_GLIBCXX_DEBUG -Wall -Wextra -DTDY -o a
```

## cmp — コンパイル

C++ ファイルを `a` という実行ファイルにコンパイルする。

```bash
./cmp <file>      # 例: ./cmp a / ./cmp a.cpp（.cpp は省略可）
./cmp <file> t    # -DDEBUG を付けてコンパイル（デバッグ出力用）
```

- `<file>` は `.cpp` を付けても付けなくてもよい。
- 第 2 引数に `t` を渡すと `-DDEBUG` 付きでコンパイルする。

## rand — ランダムテスト（出力比較）

`generate` が作った入力を `solve` と `naive` に与え、出力が一致するか比較する。
不一致が見つかるまでループし続ける（WA 発見用）。

```bash
./rand <solve> <naive> <generate>
# 例: ./rand a naive gen
```

- 一致している間は `Case <n> OK!` を上書き表示。
- 不一致が出たら、入力・naive の出力・solve の出力を表示して停止する。
- 各引数とも `.cpp` は省略可。

## check — ランダムテスト（RE 発見）

`rand` の簡易版。`generate` が作った入力を `solve` に与え、異常終了
（非ゼロ終了 / シグナル）するまでループする（RE 発見用）。

```bash
./check <solve> <generate>
# 例: ./check a gen
```

- 正常終了の間は `Case <n> OK!` を上書き表示。
- 異常終了したら、終了理由（SIGABRT / SIGFPE / SIGSEGV など）と入力・エラー出力を
  表示して停止する。`-D_GLIBCXX_DEBUG` によるアサート検出にも対応。

## copy — 提出用ファイルの生成とアーカイブ

`kyopro_library/exp.py` でライブラリを展開（必要なら ACL も展開）し、
`esc/` 以下に連番付きでコピーして保存する。

```bash
./copy <file>      # 例: ./copy a  /  ./copy a.cpp
./copy <file> -t   # ACL（atcoder library）も expander.py で展開する
```

- `a`〜`h` のショートカット（`a` → `a.cpp` など）が使える。
- `esc/<basename><連番>.cpp`（例: `a01.cpp`, `a02.cpp` …）として保存される。

## contest — 環境のリセット

次のコンテストに向けて手元のファイルを整理する。

```bash
./contest
```

- 残す: 補助スクリプト・各種設定、`kp` 関連、`code` / `z` で始まるファイル
  （`code.cpp`, `z.cpp`, `z01.cpp` など）。
- 消す: それ以外の解答ファイル・生成物、`samples/` ディレクトリ、`esc/` 内の
  アーカイブ（`code*` / `z*` を除く）。
- 実行後に画面をクリアする。
