#include "list.h"

List::List(){
    firstPtr   = NULL;
    endPtr     = NULL;
    listSize = 0;
}

List::~List(){
    while(listSize){
        this->Remove(0);
    }
}

void* List::GetPtr(uint64 index){
    if (index >= listSize) {return NULL;}

    Node* node = move(index);
    if (node == NULL) {return NULL;}
    return node->valuePtr;
}

int8 List::SetPtr(uint64 index, void* valuePtr){
    if (index >= listSize) {return LIST_ERROR;}

    Node* node = move(index);
    if (node == NULL) {return LIST_ERROR;}

    delete node->valuePtr;
    node->valuePtr = valuePtr;

    return LIST_OK;
}

int8 List::AppendPtr(Node* newPtr){
    if (listSize == 0){
        firstPtr = newPtr;
        endPtr = newPtr;
    }else{
        endPtr->nextPtr = newPtr;
        newPtr->prevPtr = endPtr;
        endPtr = newPtr;
    }
    listSize++;

    return LIST_OK;
}

int8 List::InsertPtr(uint64 index, Node* newPtr){
    if (index == listSize - 1){
        return this->AppendPtr(newPtr);
    }
    if (listSize == 0){
        firstPtr = newPtr;
        endPtr = newPtr;
    }else
    if (index == 0){
        firstPtr->prevPtr = newPtr;
        newPtr->nextPtr = firstPtr;
        firstPtr = newPtr;
    }else{
        Node* prevPtr = this->move(index-1);
        Node* nextPtr = this->move(index);
        this->setPtr(prevPtr, newPtr);
        this->setPtr(newPtr, nextPtr);
    }

    listSize++;

    return LIST_OK;
}

int8 List::Remove(uint64 index){
    if (index >= listSize) {return LIST_ERROR;}

    Node* current = move(index);
    if (current == NULL) {return LIST_ERROR;}
    Node* prevPtr = current->prevPtr;
    Node* nextPtr = current->nextPtr;

    if (index == 0){
        if (nextPtr != NULL){
            nextPtr->prevPtr = NULL;
            firstPtr = nextPtr;
        }
    }else
    if (index == (listSize - 1)){
        prevPtr->nextPtr = NULL;
        endPtr = prevPtr;
    }else
    {
        this->setPtr(prevPtr, nextPtr);
    }

    listSize--;
    delete current->valuePtr;
    delete current;

    return LIST_OK;
}

uint64 List::Length(){
    return listSize;
}

Node* List::CreateNewPtr(void* valuePtr){
    Node* newPtr = new Node;
    newPtr->valuePtr = valuePtr;
    return newPtr;
}

Node* List::move(uint64 index){
    if (index >= listSize) {return NULL;}

    Node* retPtr = NULL;
    if (listSize / 2 >= index) {
        retPtr = firstPtr;
        for (uint64 i = 0; i < index; i++){
            retPtr = retPtr->nextPtr;
        }
    }else{
        retPtr = endPtr;
        for (uint64 i = 0; i < listSize-index-1; i++){
            retPtr = retPtr->prevPtr;
        }
    }

    return retPtr;
}

int8 List::setPtr(Node* prevPtr, Node* nextPtr){
    nextPtr->prevPtr = prevPtr;
    prevPtr->nextPtr = nextPtr;
    return LIST_OK;
}