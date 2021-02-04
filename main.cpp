#include "slice.h"

int main(){
    Slice<uint64> slice;
    Slice<uint64> sl;
    std::cout << "start\n";
    slice.Append(200);
    slice.Append(100);
    slice.Append(300);
    slice.Append(500);
    slice.Append(450);
    slice.Append(400);
    slice.Append(250);
    slice.Append(150);
    slice.Append(350);
    slice.Append(550);
    slice.Append(450);
    sl.Append(1);
    sl.Append(2);
    sl.Append(3);
    sl.Append(4);
    slice.Print(0, slice.Length()-1);

    bool (*fn)(uint64, uint64) = [](uint64 v1, uint64 v2){
        // cout << v1 << ", " << v2 << ", " << (v1 > v2) << endl;
        return (v1 > v2);
    };
    slice.Append(&sl);
    slice.Sort(fn);
    slice.Print(0, slice.Length()-1);

    return 0;
}

