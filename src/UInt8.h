#include "./list.h"

namespace Slice {
class UInt8:public List{
    public:
    UInt8();
    ~UInt8();
    int8 Append(uint8);
    int8 Insert(uint64, uint8);
    uint8  Get   (uint64);
    int8   Set   (uint64, uint8);
    int8 Print(uint64, uint64);
    private:

};
}