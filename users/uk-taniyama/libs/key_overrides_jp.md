## KEY_OVERRIDE_JP について

日本語配列（JIS）環境向けに、英語配列のまま入力できるように変換します。

この機能は **QMK の Key Overrides 機能**を使って実現されています。  
そのため、**`rules.mk` で以下を有効にしてください。**

```make
KEY_OVERRIDE_ENABLE = yes
```

Key Overrides の基本的な挙動や詳細な仕様については、公式ドキュメントを参照してください。

- [QMK Key Overrides(公式ドキュメント)](https://docs.qmk.fm/features/key_overrides)

---

## 使い方（デフォルト）

以下のように include すると、  **定義されている日本語配列変換がすべて有効**になります。

```c
#include "libs/key_overrides_jp.c"
```

---

## 変換条件のカスタマイズ

`KEY_OVERRIDE_JP` マクロを **include 前に定義**して、  **変換条件（レイヤー・修飾キーなど）を制御**してください。

### 例：レイヤーで日本語配列変換を有効にする


`_JP` レイヤーを作成し、日本語配列変換したいキーを `_JP` レイヤー上に配置して、 以下のように定義してください。

※`_JP` レイヤーに `KC_TRANS` を置いても、下位レイヤーで定義されているキーは変換されません。

```c
const layer_state_t jp_layer = (1U << _JP);

#define KEY_OVERRIDE_JP(mods, key, jp_key) \
    ko_make_with_layers(mods, key, jp_key, jp_layer)

#include "libs/key_overrides_jp.c"
```

---

## Key Overrides を追加したいとき

`KEY_OVERRIDES_OFF` を定義すると、`key_overrides`が定義されなくなります。
日本語配列変換リスト`KEY_OVERRIDE_JP_LIST`を使って`key_overrides`を定義してください。

```c
#define KEY_OVERRIDES_OFF
#include "libs/key_overrides_jp.c"
```
