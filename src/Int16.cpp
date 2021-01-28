#include "./Int16.h"

namespace Slice{
    Int16::Int16(){
        this->SetType(TYPE_INT16);
    }

    Int16::~Int16(){}

    int8 Int16::Append(int16 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 Int16::Insert(uint64 index, int16 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    int16 Int16::Get(uint64 index){
        return *(int16*)(this->GetPtr(index));
    }

    int8  Int16::Set(uint64 index, int16 value){
        return this->SetPtr(index, &value);
    }

    int8 Int16::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hd ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}