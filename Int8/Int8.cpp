#include "./Int8.h"

namespace Slice{
    int8 Int8::Append(int8 value){
        int8* newValuePtr = new int8;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 Int8::Insert(uint64 index, int8 value){
        int8* newValuePtr = new int8;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 Int8::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hhd ", *(int8*)(this->Get(i)));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}