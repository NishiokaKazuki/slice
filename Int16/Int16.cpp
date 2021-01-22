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

    int8 Int16::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            printf("%hd ", *(int16*)(this->Get(i)));
        }
        std::cout << "\n";
        return LIST_OK;
    }
}