
#ifndef BUILD
#define BUILD

#include <vector>

#define WEST 0
#define EAST 1
#define TOLL 2


using std::vector;
using Bridge = vector<int>;

int build(int w, int e, const vector<Bridge> & bridges);


#endif /* BUILD */