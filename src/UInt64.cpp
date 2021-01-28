#include "./UInt64.h"

namespace Slice{
    int8 UInt64::Append(uint64 value){
        uint64* newValuePtr = new uint64;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 UInt64::Insert(uint64 index, uint64 value){
        uint64* newValuePtr = new uint64;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    uint64 UInt64::Get(uint64 index){
        return *(uint64*)(this->GetPtr(index));
    }

    int8 UInt64::Set(uint64 index, uint64 value){
        uint64* newValuePtr = new uint64;
        *newValuePtr = value;
        return this->SetPtr(index, newValuePtr);
    }

    int8 UInt64::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%lu ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}