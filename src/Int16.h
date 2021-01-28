#include "./list.h"

namespace Slice {
class Int16:public List{
    public:
    Int16();
    ~Int16();
    int8 Append(int16);
    int8 Insert(uint64, int16);
    int16 Get   (uint64);
    int8  Set   (uint64, int16);
    int8 Print(uint64, uint64);
    private:

};
}