vector<int> longestIncreasingSubsequence(vector<int> &seq) {
  int n = seq.size(), lisLength = 0, lisEnd = 0;
  vector<int> L(n), L_id(n), parents(n);
  for (int i = 0; i < n; i++) {
    int pos =
      lower_bound(L.begin(), L.begin() + lisLength, seq[i]) - L.begin();
    L[pos] = seq[i];
    L_id[pos] = i;
    parents[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 > lisLength) {
      lisLength = pos + 1;
      lisEnd = i;
  }}
  // Ab hier Rekonstruktion der Sequenz.
  vector<int> result(lisLength);
  int pos = lisLength - 1, x = lisEnd;
  while (parents[x] >= 0) {
    result[pos--] = x;
    x = parents[x];
  }
  result[0] = x;
  return result; // Liste mit Indizes einer LIS.
}
