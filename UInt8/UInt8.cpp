#include "./UInt8.h"

namespace Slice{
    int8 UInt8::Append(uint8 value){
        uint8* newValuePtr = new uint8;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 UInt8::Insert(uint64 index, uint8 value){
        uint8* newValuePtr = new uint8;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 UInt8::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hhu ", *(uint8*)(this->Get(i)));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}