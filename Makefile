OUT = lib/alib.a
CC = g++
SDIR = src
ODIR = obj
INC = -Iinc
CFLAGS = -Wall -O2

CPP_FILES = ./list.cpp \
		./Int8.cpp \
		./Int16.cpp \
		./Int32.cpp \
		./Int64.cpp \
		./UInt8.cpp \
		./UInt16.cpp \
		./UInt32.cpp \
		./UInt64.cpp \
		./String.cpp

_OBJS = list.o \
		Int8.o \
		Int16.o \
		Int32.o \
		Int64.o \
		UInt8.o \
		UInt16.o \
		UInt32.o \
		UInt64.o \
		String.o

OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS)

$(OUT): $(OBJS)
	ar rvs $(OUT) $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT)
