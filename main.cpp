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

    Slice::UInt8 u8slice;
    u8slice.Append(100);
    u8slice.Append(200);
    u8slice.Append(300);
    u8slice.Append(400);
    u8slice.Append(500);
    u8slice.Insert(2, 250);
    u8slice.Print(0, u8slice.Length()-1);
    printf("%ld\n", u8slice.Length());

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