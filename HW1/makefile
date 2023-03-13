CCompiler = gcc
CurrentDirectory = -I.
Dependancy = hellomake.h
Object = 19050111065.o hellofunc.o

%.o: %.c $(Dependancy)
	$(CCompiler) -c -o $@ $< $(CurrentDirectory)

hellomake: $(Object)
	mkdir build
	$(CCompiler) -o $@ $^ $(CurrentDirectory)
	mv hellomake build
	mv 19050111065.o build
	mv hellofunc.o build

deletehellomake:
	rm -r build

runhellomake:
	./build/hellomake
