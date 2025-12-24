cd $(dirname "$0")
cd ..

set -e -x

rsync -a --delete keyboards/sillaka54/* qmk_firmware/keyboards/sillaka54

cd qmk_firmware
# patch docker_cmd.sh's docker image
# sed -i.bak 's|ghcr.io/qmk/qmk_cli[^ ]* |ghcr.io/qmk/qmk_cli@sha256:2dc05fc9f32efebd6b05c2b8676ee548358bc7e151e9dbf4dac6b6eed4513b07 |g' util/docker_cmd.sh
bash util/docker_build.sh "sillaka54:default"
bash util/docker_build.sh "sillaka54:via"
bash util/docker_build.sh "sillaka54:mine"

mkdir ../dist
mv *.hex *.bin *.uf2 ../dist/
ls ../dist/