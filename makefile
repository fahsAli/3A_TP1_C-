compiler        = g++
files       = date.cpp author.cpp reader.cpp borrow.cpp book.cpp library.cpp main.cpp

all: compile

compile: $(files)
	$(compiler) $(files) 

clean:
	rm -f a.out

exe:
	./a.out

