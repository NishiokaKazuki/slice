#include "./UInt8.h"

namespace Slice{
    UInt8::UInt8(){
        this->SetType(TYPE_UINT8);
    }

    UInt8::~UInt8(){}

    int8 UInt8::Append(uint8 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 UInt8::Insert(uint64 index, uint8 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    uint8 UInt8::Get(uint64 index){
        return *(uint8*)(this->GetPtr(index));
    }

    int8 UInt8::Set(uint64 index, uint8 value){
        return this->SetPtr(index, &value);
    }

    int8 UInt8::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hhu ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}