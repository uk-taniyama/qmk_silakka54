cd $(dirname "$0")
cd ..

set -e -x

kb="${kb:-sillaka54}"
km="${km:-via}"

git submodule sync --recursive
git submodule update --init --recursive

rsync -a --delete keyboards/sillaka54/* qmk_firmware/keyboards/sillaka54

cd qmk_firmware
# patch docker_cmd.sh's docker image
# sed -i.bak 's|ghcr.io/qmk/qmk_cli[^ ]* |ghcr.io/qmk/qmk_cli@sha256:2dc05fc9f32efebd6b05c2b8676ee548358bc7e151e9dbf4dac6b6eed4513b07 |g' util/docker_cmd.sh
sh util/docker_build.sh "${kb}:${km}"
cd ..
find qmk_firmware -maxdepth 1 -type f -name '*.hex' -o -name '*.bin' -o -name '*.uf2' -exec mv {} . \;

echo "Generated firmware:"
find . -maxdepth 1 -type f -name '*.hex' -o -name '*.bin' -o -name '*.uf2'
