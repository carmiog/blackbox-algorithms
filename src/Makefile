CXX=g++-5
AR=ar rcs
CXXFLAGS=-Wall -Wextra -std=c++11
LDFLAGS=-larmadillo
OBJS=affine_trusted_region.o directional_search.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

lib: $(OBJS)
	$(AR) libblackbox.a $(OBJS)
	rm -f $(OBJS)

all: lib
	rm -f *.o	
	
clean:
	rm -f $(OBJS)
	rm -f *.a
