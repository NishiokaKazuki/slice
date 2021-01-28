#include "./list.h"

namespace Slice {
class UInt32:public List{
    public:
    UInt32();
    ~UInt32();
    int8 Append(uint32);
    int8 Insert(uint64, uint32);
    uint32 Get   (uint64);
    int8   Set   (uint64, uint32);
    int8 Print(uint64, uint64);
    private:

};
}