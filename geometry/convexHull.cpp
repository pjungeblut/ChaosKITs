// Laufzeit: O(n*log(n))
ll cross(const pt p, const pt a, const pt b) {
  return (a.x - p.x) * (b.y - p.y) - (a.y - p.y) * (b.x - p.x);
}

// Punkte auf der konvexen Hülle, gegen den Uhrzeigersinn sortiert.
// Kollineare Punkte nicht enthalten, entferne dafür "=" im CCW-Test.
// Achtung: Der erste und letzte Punkt im Ergebnis sind gleich.
// Achtung: Alle Punkte müssen verschieden sein.
vector<pt> convexHull(vector<pt> p){
  int n = p.size(), k = 0;
  vector<pt> h(2 * n);
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) { // Untere Hülle.
    while (k >= 2 && cross(h[k - 2], h[k - 1], p[i]) <= 0.0) k--;
    h[k++] = p[i];
  }
  for (int i = n - 2, t = k + 1; i >= 0; i--) { // Obere Hülle.
    while (k >= t && cross(h[k - 2], h[k - 1], p[i]) <= 0.0) k--;
    h[k++] = p[i];
  }
  h.resize(k);
  return h;
}
