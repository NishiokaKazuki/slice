#include "./Int16.h"

namespace Slice{
    int8 Int16::Append(int16 value){
        int16* newValuePtr = new int16;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 Int16::Insert(uint64 index, int16 value){
        int16* newValuePtr = new int16;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int16 Int16::Get(uint64 index){
        return *(int16*)(this->GetPtr(index));
    }

    int8  Int16::Set(uint64 index, int16 value){
        int16* newValuePtr = new int16;
        *newValuePtr = value;
        return this->SetPtr(index, newValuePtr);
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