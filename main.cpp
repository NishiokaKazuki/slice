#include "./slice.h"

int main(){
    Slice::UInt32 slice;
    slice.Append(100);
    slice.Append(200);
    slice.Append(300);
    slice.Append(400);
    slice.Append(500);
    slice.Insert(2, 250);
    slice.Print(0, slice.Length()-1);
    printf("%ld\n", slice.Length());

    Slice::String strSlice;

    string a;
    while(true){
        std::cin >> a;
        if(a.compare("end")==0){
            break;
        }
        strSlice.Append(a);
    }
    strSlice.Print(0, strSlice.Length()-1);

    return 0;
}