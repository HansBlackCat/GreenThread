PROJECT_NAME = Greeter
CMAKE_OPTIONS = -DUSE_SANITIZER=Address -DUSE_STATIC_ANALYZER=clang-tidy

.PHONY: test

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
	CTEST_OUTPUT_ON_FAILURE=1 cmake --build build/test --target test