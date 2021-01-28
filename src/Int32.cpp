#include "./Int32.h"

namespace Slice{
    Int32::Int32(){
        this->SetType(TYPE_INT32);
    }

    Int32::~Int32(){}

    int8 Int32::Append(int32 value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 Int32::Insert(uint64 index, int32 value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    int32 Int32::Get(uint64 index){
        return *(int32*)(this->GetPtr(index));
    }

    int8  Int32::Set(uint64 index, int32 value){
        return this->SetPtr(index, &value);
    }

    int8 Int32::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%d ", this->Get(i));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}