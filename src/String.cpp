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

    string String::Get(uint64 index){
        return *(string*)(this->GetPtr(index));
    }

    int8 String::Set(uint64 index, string value){
        string* newValuePtr = new string;
        *newValuePtr = value;
        return this->SetPtr(index, newValuePtr);
    }

    int8 String::Print(uint64 leftIdx, uint64 rightIdx){
        if (this->Length() <= rightIdx) {return LIST_ERROR;}

        for(uint64 i = leftIdx; i<=rightIdx; i++){
            std::cout << this->Get(i) << " ";
        }
        std::cout << "\n";
        return LIST_OK;
    }
}