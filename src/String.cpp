#include "./String.h"

namespace Slice{
    String::String(){
        this->SetType(TYPE_STRING);
    }

    String::~String(){}

    int8 String::Append(string value){
        return this->AppendPtr(this->CreateNewPtr(&value));
    }

    int8 String::Insert(uint64 index, string value){
        return this->InsertPtr(index, this->CreateNewPtr(&value));
    }

    string String::Get(uint64 index){
        return *(string*)(this->GetPtr(index));
    }

    int8 String::Set(uint64 index, string value){
        return this->SetPtr(index, &value);
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