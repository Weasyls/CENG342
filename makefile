CCompiler = mpicc
CurrentDirectory = -I.
Dependancy = hellomake.h
Object = 19050111065.o hellofunc.o

%.o: %.c $(Dependancy)
	$(CCompiler) -c -o $@ $< $(CurrentDirectory)

19050111065: $(Object)
	mkdir build
	$(CCompiler) -o $@ $^ $(CurrentDirectory)
	mv 19050111065.o build
	mv hellofunc.o build
	mv $@ build
	
clear:
	rm -r build
	rm output1.txt
	rm output2.txt
	rm output3.txt
	rm output4.txt
	rm output5.txt
	rm output6.txt

runLargeAll: 
	mpirun -n 1 ./build/19050111065 1065 1065 output1.txt
	mpirun -n 2 ./build/19050111065 1065 1065 output2.txt
	mpirun -n 3 ./build/19050111065 1065 1065 output3.txt
	mpirun -n 4 ./build/19050111065 1065 1065 output4.txt
	mpirun -n 5 ./build/19050111065 1065 1065 output5.txt
	mpirun -n 6 ./build/19050111065 1065 1065 output6.txt

runSmallAll: 
	mpirun -n 1 ./build/19050111065 165 165 output1.txt
	mpirun -n 2 ./build/19050111065 165 165 output2.txt
	mpirun -n 3 ./build/19050111065 165 165 output3.txt
	mpirun -n 4 ./build/19050111065 165 165 output4.txt
	mpirun -n 5 ./build/19050111065 165 165 output5.txt
	mpirun -n 6 ./build/19050111065 165 165 output6.txt

output:
	cat output1.txt
	cat output2.txt
	cat output3.txt
	cat output4.txt
	cat output5.txt
	cat output6.txt