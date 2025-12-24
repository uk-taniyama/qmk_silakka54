cd $(dirname "$0")
cd ..

set -e -x

cd qmk_firmware
rm -rf keyboards/silakka54
rm -rf .build
