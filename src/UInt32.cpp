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

    uint32 UInt32::Get(uint64 index){
        return *(uint32*)(this->GetPtr(index));
    }

    int8 UInt32::Set(uint64 index, uint32 value){
        uint32* newValuePtr = new uint32;
        *newValuePtr = value;
        return this->SetPtr(index, newValuePtr);
    }

    int8 UInt32::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%u ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}