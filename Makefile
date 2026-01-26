.PHONY: build
build:
	sh ./scripts/build.sh

.PHONY: build-default
build-default:
	km=default sh ./scripts/build.sh

.PHONY: build-mine
build-mine:
	km=mine sh ./scripts/build.sh

.PHONY: build-vial
build-vial:
	km=vial sh ./scripts/build.sh

.PHONY: build-via
build-via:
	km=via sh ./scripts/build.sh

.PHONY: clean
clean:
	sh ./scripts/clean.sh

.PHONY: rebuild
rebuild: clean build

.PHONY: format
format:
	find keyboards users -name "*.[ch]" | xargs clang-format -i

.PHONE: gen-props
gen-props:
	npx qmk-via-utils gen-vscode-props qmk_firmware/.build/obj_silakka54led_mine/cflags.txt
