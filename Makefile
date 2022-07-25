PROJECT_NAME = GreenThread
CMAKE_OPTIONS = -DUSE_SANITIZER=Address -DUSE_STATIC_ANALYZER=clang-tidy

.PHONY: all

standalone:
	cmake -S standalone -B build/standalone ${CMAKE_OPTIONS}

build_standalone: standalone
	cmake --build build/standalone

test:
	cmake -S test -B build/test ${CMAKE_OPTIONS}

build_test: test
	cmake --build build/test

run_standalone: build_standalone
	./build/standalone/${PROJECT_NAME}

run_test: build_test
	./build/test/${PROJECT_NAME}Tests