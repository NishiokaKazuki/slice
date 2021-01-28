#include "./UInt32.h"

namespace Slice{
    UInt32::UInt32(){
        this->SetType(TYPE_UINT32);
    }

    UInt32::~UInt32(){}

    int8 UInt32::Append(uint32 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 UInt32::Insert(uint64 index, uint32 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    uint32 UInt32::Get(uint64 index){
        return *(uint32*)(this->GetPtr(index));
    }

    int8 UInt32::Set(uint64 index, uint32 value){
        return this->SetPtr(index, &value);
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