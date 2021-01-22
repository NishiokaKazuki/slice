#include "./UInt16.h"

namespace Slice{
    int8 UInt16::Append(uint16 value){
        uint16* newValuePtr = new uint16;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 UInt16::Insert(uint64 index, uint16 value){
        uint16* newValuePtr = new uint16;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 UInt16::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hd ", *(uint16*)(this->Get(i)));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}