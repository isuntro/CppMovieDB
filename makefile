CC= g++
CXXFLAGS= -std=c++1y #-Wall
DEPS = Movie.h MovieDB.h TimeCode.h Rating.h Ratings.h
OBJ = main.o Movie.o MovieDB.o TimeCode.o Rating.o Ratings.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)
clean:
	rm -f *.o main
