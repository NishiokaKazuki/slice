#include "./Int64.h"

namespace Slice{
    int8 Int64::Append(int64 value){
        int64* newValuePtr = new int64;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 Int64::Insert(uint64 index, int64 value){
        int64* newValuePtr = new int64;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int64 Int64::Get(uint64 index){
        return *(int64*)(this->GetPtr(index));
    }

    int8 Int64::Set(uint64 index, int64 value){
        int64* newValuePtr = new int64;
        *newValuePtr = value;
        return this->SetPtr(index, newValuePtr);
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