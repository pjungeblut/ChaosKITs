// Laufzeit: O(sqrt(|V|)*|E|)
// Kanten von links nach rechts.
// 0: dummy Knoten, 1..n: linke Knoten, n+1..n+m: rechte Knoten
vector<vector<int>> adjlist;
vector<int> match, dist;

bool bfs(int n) {
  queue<int> q;
  dist[0] = INF;
  for(int i = 1; i <= n; i++) {
    if(match[i] == 0) { dist[i] = 0; q.push(i); }
    else dist[i] = INF;
  }
  while(!q.empty()) {
    int u = q.front(); q.pop();
    if(dist[u] < dist[0]) for (int v : adjlist[u])
      if(dist[match[v]] == INF) {
        dist[match[v]] = dist[u] + 1;
        q.push(match[v]);
      }
  }
  return dist[0] != INF;
}

bool dfs(int u) {
  if(u != 0) {
    for (int v : adjlist[u])
      if(dist[match[v]] == dist[u] + 1)
        if(dfs(match[v])) { match[v] = u; match[u] = v; return true; }
    dist[u] = INF;
    return false;
  }
  return true;
}

int hopcroft_karp(int n) { // n = #Knoten links
  int ans = 0;
  match.assign(adjlist.size(), 0);
  dist.resize(adjlist.size());
  // Greedy Matching, optionale Beschleunigung.
  for (int i = 1; i <= n; i++) for (int w : adjlist[i])
    if (match[w] == 0) { match[i] = w; match[w] = i; ans++; break; }
  while(bfs(n)) for(int i = 1; i <= n; i++)
    if(match[i] == 0 && dfs(i)) ans++;
  return ans;
}
