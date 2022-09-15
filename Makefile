generate:
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build

compile:
	cd build; make

run:
	./build/bin/dtd

clean:
	rm -r build && mkdir build