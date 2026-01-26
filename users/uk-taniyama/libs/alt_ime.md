# ALT_IME

`ALT_IME` は **Mod-Tap を使って `Alt` と `半角/全角` を兼用するキー**です。
英語配列（US）・日本語配列（JIS）環境でも、同じの入力で行えるようにしています。

## できること

- **ホールド**: `Alt` として動作
- **タップ**:
  - **英語配列** → `Alt + Grave`（`US_ZKHK` を定義）
  - **日本語配列** → `半角/全角`（`JP_ZKHK`）

## 使い方

### 1. インクルード

デフォルトでは **英語配列** で動作します。

``` c
#include "libs/alt_ime.h"
```

### 2. レイアウト判定の定義

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
