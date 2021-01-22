#include "./UInt32.h"

namespace Slice{
    int8 UInt32::Append(uint32 value){
        uint32* newValuePtr = new uint32;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 UInt32::Insert(uint64 index, uint32 value){
        uint32* newValuePtr = new uint32;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 UInt32::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%d ", *(uint32*)(this->Get(i)));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}