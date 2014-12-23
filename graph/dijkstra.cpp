priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<int> dist;
dist.assign(NUM_VERTICES, INF);
dist[START] = 0;
pq.push(ii(0, START));

while (!pq.empty()) {
	ii front = pq.top(); pq.pop();
	int curNode = front.second, curDist = front.first;
	
	if (curDist > dist[curNode]) continue;
	
	for (int i = 0; i < (int)adjlist[curNode].size(); i++) {
		int nextNode = adjlist[curNode][i].first, nextDist = curDist + adjlist[curNode][i].second;
		
		if (nextDist < dist[nextNode]) {
			dist[nextNode] = nextDist; pq.push(ii(nextDist, nextNode));
		}
	}
}
