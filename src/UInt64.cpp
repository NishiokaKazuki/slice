#include "./UInt64.h"

namespace Slice{
    UInt64::UInt64(){
        this->SetType(TYPE_UINT64);
    }

    UInt64::~UInt64(){}

    int8 UInt64::Append(uint64 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 UInt64::Insert(uint64 index, uint64 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    uint64 UInt64::Get(uint64 index){
        return *(uint64*)(this->GetPtr(index));
    }

    int8 UInt64::Set(uint64 index, uint64 value){
        return this->SetPtr(index, &value);
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