Target := main
BD := build
all: clean_cache configure build run

clean_cache:
	@echo "cleaning the cache"
	@rm -rf build/CMakeCache.txt build/CMakeFiles build/cmake_install.cmake build/Makefile

configure:
	@echo "configuring with cmake"
	@cmake -S . -B $(BD)

build:
	@echo "Building"
	@./$(BD)/$(Target)
run:
	@echo "Running"
	@./$(BD)/$(Target)

.PHONY: all clean_cache configure build run
