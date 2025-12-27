build: build-mine

build-default:
	km=default sh ./scripts/build.sh

build-mine:
	km=mine sh ./scripts/build.sh

build-vial:
	km=vial sh ./scripts/build.sh

build-via:
	km=via sh ./scripts/build.sh

clean:
	sh ./scripts/clean.sh

rebuild: clean build

format:
	find keyboards -name "*.[ch]" | xargs clang-format -i
