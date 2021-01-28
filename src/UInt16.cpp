#include "./UInt16.h"

namespace Slice{
    UInt16::UInt16(){
        this->SetType(TYPE_UINT16);
    }

    UInt16::~UInt16(){}

    int8 UInt16::Append(uint16 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 UInt16::Insert(uint64 index, uint16 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    uint16 UInt16::Get(uint64 index){
        return *(uint32*)(this->GetPtr(index));
    }

    int8 UInt16::Set(uint64 index, uint16 value){
        return this->SetPtr(index, &value);
    }

    int8 UInt16::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hu ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}