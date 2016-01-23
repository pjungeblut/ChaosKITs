// Laufzeit: O(n*log(n))
typedef pair<ll, ll> pt;

// >0 => PAB dreht gegen den Uhrzeigersinn.
// <0 => PAB dreht im Uhrzeigersinn.
// =0 => PAB sind kollinear.
ll cross(const pt p, const pt a, const pt b) {
  return (a.first - p.first) * (b.second - p.second) -
      (a.second - p.second) * (b.first - p.first);
}

// Punkte auf der konvexen Hülle, gegen den Uhrzeigersinn sortiert.
// Kollineare Punkte sind nicht enthalten. Entferne "=" im CCW-Test um sie aufzunehmen.
// Achtung: Der erste und letzte Punkt im Ergebnis sind gleich.
// Achtung: Alle Punkte müssen verschieden sein.
vector<pt> convexHull(vector<pt> p){
  int n = p.size(), k = 0;
  vector<pt> h(2 * n);
  sort(p.begin(), p.end());
  // Untere Hülle.
  for (int i = 0; i < n; i++) {
    while (k >= 2 && cross(h[k - 2], h[k - 1], p[i]) <= 0.0) k--;
    h[k++] = p[i];
  }
  // Obere Hülle.
  for (int i = n - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && cross(h[k - 2], h[k - 1], p[i]) <= 0.0) k--;
    h[k++] = p[i];
  }
  h.resize(k);
  return h;
}
