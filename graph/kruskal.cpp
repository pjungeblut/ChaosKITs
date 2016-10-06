// Union-Find Implementierung von oben. Laufzeit: O(|E|*log(|E|))
sort(edges.begin(), edges.end());
vector<ii> mst; int cost = 0;
for (auto &e : edges) {
  if (findSet(e.from) != findSet(e.to)) {
    unionSets(e.from, e.to);
    mst.push_back(ii(e.from, e.to));
    cost += e.cost;
}}
