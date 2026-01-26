# alt_ime

`alt_ime` は`半角/全角` を英語配列（US）・日本語配列（JIS）環境にて同じキーで入力できる機能を提供しています。

## US_ZKHK

`US_ZKHK` は **単体の IME 変換キー** です。
`US_ZKHK_OFF` を定義により無効にできます。

- **US_ZKHK** が押された場合の動作:  
  - **英語配列 (US)** → `Alt + Grave`（`US_ZKHK`）  
  - **日本語配列 (JP)** → `半角/全角`（`JP_ZKHK`）  

## ALT_IME

`ALT_IME` は **Mod-Tap キー**で、以下のようになります。

- **ホールド**: `Alt` として動作  
- **タップ**: 配列に応じて IME 変換キーを送信  
  - **英語配列 (US)** → `Alt + Grave`（`US_ZKHK`）  
  - **日本語配列 (JP)** → `半角/全角`（`JP_ZKHK`）  

## 使い方

### インクルード

``` c
#include "libs/alt_ime.h"
```

デフォルトではつねに **英語配列** として動作します。

### レイアウト判定の定義

日本語配列レイアウトの判定は、`IS_JP_LAYOUT()` を定義してください。

```c
#define IS_JP_LAYOUT() (is_default_layer_alt())
```

### 3. `process_record_user` に組み込む

```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_alt_ime(keycode, record)) {
        return false;
    }
    return true;
}
```

## カスタマイズ

### US 側 ZKHK の挙動を変更する

`US_ZKHK` は上書き可能です。

```c
#define US_ZKHK A(KC_GRV)
```
