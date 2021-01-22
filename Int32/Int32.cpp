#include "./Int32.h"

namespace Slice{
    int8 Int32::Append(int32 value){
        int32* newValuePtr = new int32;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 Int32::Insert(uint64 index, int32 value){
        int32* newValuePtr = new int32;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 Int32::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%d ", *(int32*)(this->Get(i)));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}