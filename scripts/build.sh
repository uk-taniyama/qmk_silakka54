cd $(dirname "$0")
cd ..

set -e -u -x

kb="${kb:-silakka54led}"
km="${km:-default}"
name=$(echo "${kb}/${km}" | tr "/" "_")

if [ "${km#vial}" != "$km" ]; then
  fw="vial-qmk"
else
  fw="qmk_firmware"
fi

echo "==> build $kb:$km ($name) by $fw"

echo "==> init submodule: $fw"
git submodule sync -- "$fw"
git submodule update --init --recursive "$fw"

echo "==> copy keyboards"
rsync -a --delete keyboards/silakka54led/* ${fw}/keyboards/silakka54led
rsync -a --delete keyboards/uk-taniyama/* ${fw}/keyboards/uk-taniyama

cd ${fw}
# patch docker_cmd.sh's docker image
# sed -i.bak 's|ghcr.io/qmk/qmk_cli[^ ]* |ghcr.io/qmk/qmk_cli@sha256:2dc05fc9f32efebd6b05c2b8676ee548358bc7e151e9dbf4dac6b6eed4513b07 |g' util/docker_cmd.sh
sh util/docker_build.sh "${kb}:${km}"
mv silakka54led_*.??? ..

cd ..
echo "Generated firmware:"
ls silakka54led_*.???

mv $name.* ..
