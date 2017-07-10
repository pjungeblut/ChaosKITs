// Laufzeit: O(n*log(n))
ll merge(vector<ll> &v, vector<ll> &left, vector<ll> &right) {
  int a = 0, b = 0, i = 0;
  ll inv = 0;
  while (a < (int)left.size() && b < (int)right.size()) {
    if (left[a] < right[b]) v[i++] = left[a++];
    else {
      inv += left.size() - a;
      v[i++] = right[b++];
    }
  }
  while (a < (int)left.size()) v[i++] = left[a++];
  while (b < (int)right.size()) v[i++] = right[b++];
  return inv;
}

ll mergeSort(vector<ll> &v) { // Sortiert v und gibt Inversionszahl zurück.
  int n = v.size();
  vector<ll> left(n / 2), right((n + 1) / 2);
  for (int i = 0; i < n / 2; i++) left[i] = v[i];
  for (int i = n / 2; i < n; i++) right[i - n / 2] = v[i];

  ll result = 0;
  if (left.size() > 1) result += mergeSort(left);
  if (right.size() > 1) result += mergeSort(right);
  return result + merge(v, left, right);
}
