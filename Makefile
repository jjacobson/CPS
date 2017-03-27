#to run this file run in command line make
# example: ....$ make

# use here any compiler you want, for example g++
CC=clang++-3.8
# specify the compiler flags here
# I added the c++14 standard
CFLAGS=--std=c++14
#specify ALL of your header files
DEPS = cps.h
#specify ALL of your source files here with a .o ending
OBJ = cps_test.o cps.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#specify your executable's name, here it is "cps"
cps: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	#cleans directory -> removes all .o files
	rm -f *.o 

#congrats!! now you should be able to run your executable as follows on the command line
# ....$ ./$(name) in this case it is ---> ....$ ./cps