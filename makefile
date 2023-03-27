CCompiler = gcc
CurrentDirectory = -I.
Dependancy = hellomake.h
Object = 19050111065.o hellofunc.o

%.o: %.c $(Dependancy)
	$(CCompiler) -c -o $@ $< $(CurrentDirectory)

19050111065: $(Object)
	mkdir build
	$(CCompiler) -o $@ $^ $(CurrentDirectory)
	mv $@ build
	mv 19050111065.o build
	mv hellofunc.o build

clear:
	rm -r build
	rm output.txt

run: 
	./build/19050111065 5 6 output.txt

output:
	cat output.txt
