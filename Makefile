generate:
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build

compile:
	make generate; cd build; make

run:
	./build/bin/dtd

clean:
	rm -r build && mkdir build