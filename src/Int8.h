#include "./list.h"

namespace Slice {
class Int8:public List{
    public:
    Int8();
    ~Int8();
    int8 Append(int8);
    int8 Insert(uint64, int8);
    int8 Get   (uint64);
    int8 Set   (uint64, int8);
    int8 Print(uint64, uint64);
    private:
};
}