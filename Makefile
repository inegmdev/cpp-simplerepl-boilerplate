SHELL:=/bin/bash
rebuild?=0

all: build run
.PHONY: all

build:
ifeq ($(rebuild),1)
	if [[ -d ./build ]]; then cmake --clean ./build; fi
else ifeq ($(rebuild),f)
	if [[ -d ./build ]]; then rm -rf ./build; fi
endif
	cmake -S . -B ./build
	cmake --build ./build
.PHONY: build

run:
	./build/simplecli
.PHONY: run
