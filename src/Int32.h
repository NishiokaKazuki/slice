#include "./list.h"

namespace Slice {
class Int32:public List{
    public:
    int8 Append(int32);
    int8 Insert(uint64, int32);
    int32 Get   (uint64);
    int8  Set   (uint64, int32);
    int8 Print(uint64, uint64);
    private:

};
}