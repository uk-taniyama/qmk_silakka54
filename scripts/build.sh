cd $(dirname "$0")
cd ..

set -e -x

kb="${kb:-silakka54x}"
km="${km:-via}"

git submodule sync --recursive
git submodule update --init --recursive

rsync -a --delete keyboards/silakka54/* qmk_firmware/keyboards/silakka54x

cd qmk_firmware
# patch docker_cmd.sh's docker image
# sed -i.bak 's|ghcr.io/qmk/qmk_cli[^ ]* |ghcr.io/qmk/qmk_cli@sha256:2dc05fc9f32efebd6b05c2b8676ee548358bc7e151e9dbf4dac6b6eed4513b07 |g' util/docker_cmd.sh
sh util/docker_build.sh "${kb}:${km}"
mv silakka54x_*.??? ..

cd ..
echo "Generated firmware:"
ls silakka54x_*.???

