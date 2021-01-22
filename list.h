#pragma once
#define  _CRT_NO_SECURE_WARNINGS
#define  _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

// integer 8bit
using int8 = int8_t;

// integer 16bit
using int16 = int16_t;

// integer 32bit
using int32 = int32_t;

// integer 64bit
using int64 = int64_t;

// unsigned integer 8bit
using uint8 = u_int8_t;

// unsigned integer 16bit
using uint16 = u_int16_t;

// unsigned integer 32bit
using uint32 = u_int32_t;

// unsigned integer 64bit
using uint64 = u_int64_t;

using string = std::string;

#define LIST_OK     0
#define LIST_ERROR -1

typedef struct _Node {
    void* valuePtr;
    _Node* prevPtr;
    _Node* nextPtr;
}Node;

class List {
    public:
    List();
    ~List();
    void* Get   (uint64);
    int8  AppendPtr(Node*);
    int8  InsertPtr(uint64, Node*);
    int8  Remove(uint64);
    uint64 Length();
    Node* CreateNewPtr(void*);

    private:
    Node* move(uint64);
    int8  setPtr(Node*, Node*);
    Node* firstPtr;
    Node* endPtr;
    uint64 listSize;
};