cd $(dirname "$0")
cd ..

set -e -x

make build-default build-via build-mine build-vial

mkdir ../dist
for f in *.hex *.bin *.uf2; do
  [ -f "$f" ] || continue
  mv "$f" ../dist/
done
ls ../dist/
