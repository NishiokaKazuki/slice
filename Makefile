OUT = lib/slice.a
CC = g++
SDIR = src
ODIR = obj
INC = -Iinc
CFLAGS = -Wall -O2

# CPP_FILES = ./list.cpp \
# 		./Int8.cpp \
# 		./Int16.cpp \
# 		./Int32.cpp \
# 		./Int64.cpp \
# 		./UInt8.cpp \
# 		./UInt16.cpp \
# 		./UInt32.cpp \
# 		./UInt64.cpp \
# 		./String.cpp

_OBJS = list.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
	ar rvs $(OUT) $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT)

build:
	g++ -o main main.cpp src/list.cpp