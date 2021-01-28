#include "list.h"

List::List(){
    firstPtr   = NULL;
    endPtr     = NULL;
    listSize = 0;
    listType = TYPE_OTHER;
}

List::~List(){
    while(listSize){
        this->Remove(0);
    }
}

int8 List::SetType(int8 type){
    listType = type;
    return LIST_OK;
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

    deleteValuePtr(node->valuePtr);
    node->valuePtr = createValuePtr(valuePtr);

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
    deleteValuePtr(current->valuePtr);
    delete current;

    return LIST_OK;
}

uint64 List::Length(){
    return listSize;
}

Node* List::CreateNewPtr(void* valuePtr){
    Node* newPtr = new Node;
    newPtr->valuePtr = createValuePtr(valuePtr);
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

void* List::createValuePtr(void* valuePtr){
    switch(listType){
        case TYPE_INT8:{
            int8* newValuePtr = new int8;
            *newValuePtr = *((int8*)valuePtr);
            return newValuePtr;
        }
        case TYPE_INT16:{
            int16* newValuePtr = new int16;
            *newValuePtr = *((int16*)valuePtr);
            return newValuePtr;
        }
        case TYPE_INT32:{
            int32* newValuePtr = new int32;
            *newValuePtr = *((int32*)valuePtr);
            return newValuePtr;
        }
        case TYPE_INT64:{
            int64* newValuePtr = new int64;
            *newValuePtr = *((int64*)valuePtr);
            return newValuePtr;
        }
        case TYPE_UINT8:{
            uint8* newValuePtr = new uint8;
            *newValuePtr = *((uint8*)valuePtr);
            return newValuePtr;
        }
        case TYPE_UINT16:{
            uint16* newValuePtr = new uint16;
            *newValuePtr = *((uint16*)valuePtr);
            return newValuePtr;
        }
        case TYPE_UINT32:{
            uint32* newValuePtr = new uint32;
            *newValuePtr = *((uint32*)valuePtr);
            return newValuePtr;
        }
        case TYPE_UINT64:{
            uint64* newValuePtr = new uint64;
            *newValuePtr = *((uint64*)valuePtr);
            return newValuePtr;
        }
        case TYPE_STRING:{
            string* newValuePtr = new string;
            *newValuePtr = *(string*)valuePtr;
            return newValuePtr;
        }
    }
    return NULL;
}

int8 List::deleteValuePtr(void* valuePtr){
    switch(listType){
        case TYPE_INT8:
            delete (int8*)valuePtr;
            break;
        case TYPE_INT16:
            delete (int16*)valuePtr;
            break;
        case TYPE_INT32:
            delete (int32*)valuePtr;
            break;
        case TYPE_INT64:
            delete (int64*)valuePtr;
            break;
        case TYPE_UINT8:
            delete (uint8*)valuePtr;
            break;
        case TYPE_UINT16:
            delete (uint16*)valuePtr;
            break;
        case TYPE_UINT32:
            delete (uint32*)valuePtr;
            break;
        case TYPE_UINT64:
            delete (uint64*)valuePtr;
            break;
        case TYPE_STRING:
            delete (string*)valuePtr;
            break;
    }
    return LIST_OK;
}