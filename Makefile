compile:
	make generate; cd build; make
generate:
	cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
run:
	./build/bin/dtd

clean:
	rm -r build && mkdir build