#include "./String.h"

namespace Slice{
    int8 String::Append(string value){
        string* newValuePtr = new string;
        *newValuePtr = value;
        this->AppendPtr(this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 String::Insert(uint64 index, string value){
        string* newValuePtr = new string;
        *newValuePtr = value;
        this->InsertPtr(index, this->CreateNewPtr(newValuePtr));

        return LIST_OK;
    }

    int8 String::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            std::cout << *(string*)(this->Get(i)) << " ";
        }
        std::cout << "\n";
        return LIST_OK;
    }
}