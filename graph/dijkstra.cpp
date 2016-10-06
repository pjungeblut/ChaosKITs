// Laufzeit: O((|E|+|V|)*log |V|) 
void dijkstra(int start) {
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	vector<int> dist(NUM_VERTICES, INF), parent(NUM_VERTICES, -1);
	dist[start] = 0; pq.push(ii(0, start));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int curNode = front.second, curDist = front.first;
		if (curDist > dist[curNode]) continue; // WICHTIG!
		
		for (auto n : adjlist[curNode]) {
			int nextNode = n.first, nextDist = curDist + n.second;
			if (nextDist < dist[nextNode]) {
				dist[nextNode] = nextDist; parent[nextNode] = curNode;
				pq.push(ii(nextDist, nextNode));
}}}}
