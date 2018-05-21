#include <ext/pb_ds/priority_queue.hpp>
template<typename T>
using priorityQueue = __gnu_pbds::priority_queue<T, less<T>>; // greater<T> für Min-Queue

int main() {
	priorityQueue<int> pq;
	auto it = pq.push(5); // O(1)
	pq.push(7);
	pq.pop(); // O(log n) amortisiert
	pq.modify(it, 6); // O(log n) amortisiert
	pq.erase(it); // O(log n) amortisiert
	priorityQueue<int> pq2;
	pq.join(pq2); // O(1)
}
