// Laufzeit: O(n + m), n = #Text, m = #Pattern
vector<int> kmp_preprocessing(string &sub) {
  vector<int> b(sub.length() + 1);
  b[0] = -1;
  int i = 0, j = -1;
  while (i < (int)sub.length()) {
    while (j >= 0 && sub[i] != sub[j]) j = b[j];
    i++; j++;
    b[i] = j;
  }
  return b;
}

vector<int> kmp_search(string &s, string &sub) {
  vector<int> pre = kmp_preprocessing(sub);
  vector<int> result;
  int i = 0, j = 0;
  while (i < (int)s.length()) {
    while (j >= 0 && s[i] != sub[j]) j = pre[j];
    i++; j++;
    if (j == (int)sub.length()) {
      result.push_back(i - j);
      j = pre[j];
    }
  }
  return result;
}
