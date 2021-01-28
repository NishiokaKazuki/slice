#include "./Int64.h"

namespace Slice{
    Int64::Int64(){
        this->SetType(TYPE_INT64);
    }

    Int64::~Int64(){}

    int8 Int64::Append(int64 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 Int64::Insert(uint64 index, int64 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    int64 Int64::Get(uint64 index){
        return *(int64*)(this->GetPtr(index));
    }

    int8 Int64::Set(uint64 index, int64 value){
        return this->SetPtr(index, &value);
    }

    int8 Int64::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%ld ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}