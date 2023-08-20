compile:
	make generate; cd build; make -j4
generate:
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
run:
	./build/bin/dtd

clean:
	rm -r build && mkdir build