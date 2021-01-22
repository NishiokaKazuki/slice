#include "../list.h"

namespace Slice {
class UInt64:public List{
    public:
    int8 Append(uint64);
    int8 Insert(uint64, uint64);
    int8 Print(uint64, uint64);
    private:
};
}