#include "./Int8.h"

namespace Slice{
    Int8::Int8(){
        this->SetType(TYPE_INT8);
    }

    Int8::~Int8(){}

    int8 Int8::Append(int8 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 Int8::Insert(uint64 index, int8 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    int8 Int8::Get(uint64 index){
        return *(int8*)(this->GetPtr(index));
    }

    int8 Int8::Set(uint64 index, int8 value){
        return this->SetPtr(index, &value);
    }

    int8 Int8::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hhd ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}