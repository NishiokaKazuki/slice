#include "./list.h"

namespace Slice {
class UInt16:public List{
    public:
    UInt16();
    ~UInt16();
    int8 Append(uint16);
    int8 Insert(uint64, uint16);
    uint16 Get   (uint64);
    int8   Set   (uint64, uint16);
    int8 Print(uint64, uint64);
    private:

};
}