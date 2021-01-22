CPP_FILES := ./list.cpp \
			 Int8/Int8.cpp \
			 Int16/Int16.cpp \
			 Int32/Int32.cpp \
			 Int64/Int64.cpp \
			 UInt8/UInt8.cpp \
			 UInt16/UInt16.cpp \
			 UInt32/UInt32.cpp \
			 UInt64/UInt64.cpp \
			 String/String.cpp

build:
	g++ -o out main.cpp $(CPP_FILES)