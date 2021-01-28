#include "./list.h"

namespace Slice {
class String:public List{
    public:
    int8 Append(string);
    int8 Insert(uint64, string);
    string Get   (uint64);
    int8   Set   (uint64, string);
    int8 Print(uint64, uint64);
    private:

};
}