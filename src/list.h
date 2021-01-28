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

#define TYPE_OTHER  -1
#define TYPE_INT8    0
#define TYPE_INT16   1
#define TYPE_INT32   2
#define TYPE_INT64   3
#define TYPE_UINT8   4
#define TYPE_UINT16  5
#define TYPE_UINT32  6
#define TYPE_UINT64  7
#define TYPE_STRING  8

typedef struct _Node {
    void* valuePtr;
    _Node* prevPtr;
    _Node* nextPtr;
}Node;

class List {
    public:
    List();
    ~List();
    int8  SetType   (int8);
    void* GetPtr    (uint64);
    int8  SetPtr    (uint64, void*);
    int8  AppendPtr (Node*);
    int8  InsertPtr (uint64, Node*);
    int8  Remove    (uint64);
    uint64 Length();
    Node* CreateNewPtr(void*);

    private:
    Node* move(uint64);
    int8  setPtr(Node*, Node*);
    void* createValuePtr(void*);
    int8  deleteValuePtr(void*);
    Node* firstPtr;
    Node* endPtr;
    uint64 listSize;
    int8 listType;
};