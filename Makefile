.PHONY: build
build:
	sh ./scripts/build.sh

.PHONY: build-default
build-default:
	km=default sh ./scripts/build.sh

.PHONY: build-mine
build-mine:
	km=mine sh ./scripts/build.sh

.PHONY: clean
clean:
	sh ./scripts/clean.sh

.PHONY: rebuild
rebuild: clean build

.PHONY: format
format:
	find keyboards -name "*.[ch]" | xargs clang-format -i
