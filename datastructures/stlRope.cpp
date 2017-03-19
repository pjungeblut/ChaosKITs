#include <ext/rope>
using namespace __gnu_cxx;
rope<int> v; // Wie normaler Container.
v.push_back(num); // O(log(n))
rope<int> sub = v.substr(start, length); // O(log(n))
v.erase(start, length); // O(log(n))
v.insert(v.mutable_begin() + offset, sub); // O(log(n))
for(auto it = v.mutable_begin(); it != v.mutable_end(); it++) {...}
