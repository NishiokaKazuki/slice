#pragma once
#define  _CRT_NO_SECURE_WARNINGS
#define  _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

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

#define SLICE_OK     0
#define SLICE_ERROR -1

template <class T>
struct _Node {
    T      value;
    _Node<T>* prevPtr;
    _Node<T>* nextPtr;
};
template <class T>
using Node = _Node<T>;
template <class Type>
class Slice {
    public:
    explicit Slice();
    ~Slice();
    Type   Get     (uint64);
    int8   Set     (uint64, Type);
    int8   Append  (Type);
    int8   Append  (Slice<Type>*);
    int8   Insert  (uint64, Type);
    int8   Remove  (uint64);
    uint64 Length  ( );
    bool   Contain (Type, Slice<uint64>*);
    bool   Contain (bool(Type, Type), Type, Slice<uint64>*);
    int8   Sort    (bool(Type, Type));
    int8   Swap    (uint64, uint64);
    void   Release ( );
    int8   Print   (uint64, uint64);

    private:
    int8   sort    (bool(Type, Type), uint64, uint64);
    Node<Type>* createNewNode(Type);
    Node<Type>* move(Node<Type>*, int64);
    Node<Type>* move(uint64);
    int8  swapPtr  (Node<Type>*, Node<Type>*);
    int8  setPtr(Node<Type>*, Node<Type>*);
    Node<Type>* firstPtr;
    Node<Type>* endPtr;
    uint64 sliceSize;
};

template <class Type>
Slice<Type>::Slice(){
    firstPtr   = NULL;
    endPtr     = NULL;
    this->sliceSize = 0;
}

template <class Type>
Slice<Type>::~Slice(){
    this->Release();
}

template <class Type>
Type Slice<Type>::Get(uint64 index){
    if (index >= this->sliceSize) {return 0;}

    Node<Type>* node = move(index);
    if (node == NULL) {return 0;}
    return node->value;
}


template <class Type>
int8 Slice<Type>::Set(uint64 index, Type value){
    if (index >= this->sliceSize) {return SLICE_ERROR;}

    Node<Type>* node = move(index);
    if (node == NULL) {return SLICE_ERROR;}

    node->value = value ;

    return SLICE_OK;
}

template <class Type>
int8 Slice<Type>::Append(Type value){
    Node<Type>* newPtr = this->createNewNode(value);
    if (this->sliceSize == 0){
        firstPtr = newPtr;
        endPtr = newPtr;
    }else{
        endPtr->nextPtr = newPtr;
        newPtr->prevPtr = endPtr;
        endPtr = newPtr;
    }
    this->sliceSize++;

    return SLICE_OK;
}

template <class Type>
int8 Slice<Type>::Append(Slice<Type>* slice){
    for (uint64 i = 0; i< slice->Length(); i++) {
        this->Append(slice->Get(i));
    }

    return SLICE_OK;
}

template <class Type>
int8 Slice<Type>::Insert(uint64 index, Type value){
    if (index > this->sliceSize){
        return SLICE_ERROR;
    }
    if (index == this->sliceSize){
        return this->Append(value);
    }
    Node<Type>* newPtr = this->createNewNode(value);
    if (this->sliceSize == 0){
        firstPtr = newPtr;
        endPtr = newPtr;
    }else
    if (index == 0){
        firstPtr->prevPtr = newPtr;
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
    }else{
        Node<Type>* prevPtr = this->move(index-1);
        Node<Type>* nextPtr = this->move(index);
        this->setPtr(prevPtr, newPtr);
        this->setPtr(newPtr, nextPtr);
    }

    this->sliceSize++;

    return SLICE_OK;
}

template <class Type>
int8 Slice<Type>::Remove(uint64 index){
    if (index >= this->sliceSize) {return SLICE_ERROR;}

    Node<Type>* current = move(index);
    if (current == NULL) {return SLICE_ERROR;}
    Node<Type>* prevPtr = current->prevPtr;
    Node<Type>* nextPtr = current->nextPtr;

    if (index == 0){
        if (nextPtr != NULL){
            nextPtr->prevPtr = NULL;
            firstPtr = nextPtr;
        }
    }else
    if (index == (this->sliceSize - 1)){
        prevPtr->nextPtr = NULL;
        endPtr = prevPtr;
    }else
    {
        this->setPtr(prevPtr, nextPtr);
    }

    this->sliceSize--;
    delete current;

    return SLICE_OK;
}

template <class Type>
int8 Slice<Type>::Print(uint64 leftIndex, uint64 rightIndex){
    if (leftIndex >=this->sliceSize ||
        rightIndex>=this->sliceSize ) { return SLICE_ERROR; }

    Node<Type>* currentPtr = this->move(leftIndex);
    for (uint64 i = leftIndex; i <= rightIndex; i++){
        if ( currentPtr == NULL ) {return SLICE_ERROR;}
        cout << currentPtr->value;
        currentPtr = this->move(currentPtr, 1);
        if ( i != rightIndex ) { cout << ", "; }
    }
    cout << "\n";
    return SLICE_OK;
}

template <class Type>
uint64 Slice<Type>::Length(){
    return this->sliceSize;
}

template <class Type>
bool Slice<Type>::Contain(Type value, Slice<uint64>* slice){
    Node<Type>* currentPtr = this->move(0);
    for ( uint64 i = 0; i < this->sliceSize; i++ ) {
        if ( currentPtr == NULL ) { return NULL; }
        if ( currentPtr->value == value ) {
            slice->Append(i);
        }
        currentPtr = move(currentPtr, 1);
    }
    return slice->sliceSize > 0;
}

template <class Type>
bool Slice<Type>::Contain(bool (*compare)(Type, Type), Type value, Slice<uint64>* slice){
    Node<Type>* currentPtr = this->move(0);
    for ( uint64 i = 0; i < this->sliceSize; i++ ) {
        if ( currentPtr == NULL ) { return NULL; }
        if ( compare(currentPtr->value, value) ) {
            slice->Append(i);
        }
        currentPtr = move(currentPtr, 1);
    }
    return slice->sliceSize > 0;
}

template <class Type>
int8 Slice<Type>::Sort(bool (*compare)(Type, Type)) {
    return this->sort(compare, 0, this->sliceSize-1);
}

template <class Type>
int8 Slice<Type>::sort(bool (*compare)(Type, Type), uint64 leftIndex, uint64 rightIndex) {
    Type pivot = leftIndex;
    uint64 leftHold = leftIndex;
    uint64 rightHold = rightIndex;
    Node<Type>* leftNodePtr = this->move(++leftIndex);
    Node<Type>* rightNodePtr = this->move(rightIndex);

    while (leftIndex < rightIndex)
    {
        while (!compare(this->move(rightIndex)->value, this->move(pivot)->value) && (leftIndex < rightIndex)) {
            rightIndex--;
        }
        while (compare(this->move(leftIndex)->value, this->move(pivot)->value) && (leftIndex < rightIndex)) {
            leftIndex++;
        }
        if (leftIndex >= rightIndex){ break; }
        this->swapPtr(this->move(leftIndex), this->move(rightIndex));
        rightIndex--;
        leftIndex++;
    }

    int8 err;
    if (compare(this->move(leftIndex)->value, this->move(pivot)->value)){
        this->Insert(leftIndex + 1, this->move(pivot)->value);
    }else{
        this->Insert(leftIndex, this->move(pivot)->value);
    }
    this->Remove(leftHold);

    if (int64(leftHold) < int64(leftIndex) - 1) {
        err = sort(compare, leftHold, leftIndex - 1);
        if ( SLICE_OK != err ) { return err; }
    }
    if (int64(rightHold) > int64(leftIndex) + 1) {
        err = sort(compare, leftIndex + 1, rightHold);
        if ( SLICE_OK != err ) { return err; }
    }

    return SLICE_OK;
}

template <class Type>
int8 Slice<Type>::Swap(uint64 leftIndex, uint64 rightIndex){
    return this->swapPtr(this->move(leftIndex), this->move(rightIndex));
}

template <class Type>
void Slice<Type>::Release() {
    while(this->sliceSize){
        this->Remove(0);
    }
    firstPtr   = NULL;
    endPtr     = NULL;
    this->sliceSize = 0;
}

template <class Type>
Node<Type>* Slice<Type>::createNewNode(Type value){
    Node<Type>* newPtr = new Node<Type>;
    newPtr->value = value;
    return newPtr;
}

template <class Type>
Node<Type>* Slice<Type>::move(Node<Type>* currentPtr, int64 index){
    if (index > 0) {
        for (int64 i = 0; i < index; i++){
            if ( currentPtr->nextPtr == NULL ) { return NULL; }
            currentPtr = currentPtr->nextPtr;
        }
    }else{
        for (int64 i = 0; i < this->sliceSize-index-1; i++){
            if ( currentPtr->prevPtr == NULL ) { return NULL; }
            currentPtr = currentPtr->prevPtr;
        }
    }

    return currentPtr;
}

template <class Type>
Node<Type>* Slice<Type>::move(uint64 index){
    if (index >= this->sliceSize) {return NULL;}

    Node<Type>* retPtr = NULL;
    if (this->sliceSize / 2 >= index) {
        retPtr = firstPtr;
        for (uint64 i = 0; i < index; i++){
            retPtr = retPtr->nextPtr;
        }
    }else{
        retPtr = endPtr;
        for (uint64 i = 0; i < this->sliceSize-index-1; i++){
            retPtr = retPtr->prevPtr;
        }
    }

    return retPtr;
}

template <class Type>
int8 Slice<Type>::swapPtr(Node<Type>* nodePtr1, Node<Type>* nodePtr2){
    if (nodePtr1 == NULL ||
        nodePtr2 == NULL ) { return SLICE_ERROR; }

    if ( this->firstPtr == nodePtr1 ) { this->firstPtr = nodePtr2; }
    else
    if ( this->firstPtr == nodePtr2 ) { this->firstPtr = nodePtr1; }
    if ( this->endPtr   == nodePtr1 ) { this->endPtr   = nodePtr2; }
    else
    if ( this->endPtr   == nodePtr2 ) { this->endPtr   = nodePtr1; }

    Node<Type>* prevPtr1 = nodePtr1->prevPtr;
    Node<Type>* nextPtr1 = nodePtr1->nextPtr;
    Node<Type>* prevPtr2 = nodePtr2->prevPtr;
    Node<Type>* nextPtr2 = nodePtr2->nextPtr;

    this->setPtr( prevPtr2, nodePtr1 );
    this->setPtr( nodePtr1, nextPtr2 );
    this->setPtr( prevPtr1, nodePtr2 );
    this->setPtr( nodePtr2, nextPtr1 );

    return SLICE_OK;
}

template <class Type>
int8 Slice<Type>::setPtr(Node<Type>* prevPtr, Node<Type>* nextPtr){
    if ( prevPtr == NULL && nextPtr == NULL ) { return SLICE_ERROR; }
    if ( prevPtr == NULL ) {
        nextPtr->prevPtr = NULL;
    }else
    if ( nextPtr == NULL ) {
        prevPtr->nextPtr = NULL;
    }else
    {
        nextPtr->prevPtr = prevPtr;
        prevPtr->nextPtr = nextPtr;
    }
    return SLICE_OK;
}
