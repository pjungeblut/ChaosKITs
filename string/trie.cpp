// Zahlenwerte müssen bei 0 beginnen und zusammenhängend sein.
struct node {
  int children[ALPHABET_SIZE], c; // c = #Wörter, die hier enden.
  node () {
    idx = -1;
    for (int i = 0; i < ALPHABET_SIZE; i++) children[i] = -1;
  }
};
vector<node> trie; // Anlegen mit trie.push_back(node());

void insert(int vert, vector<int> &txt, int s) { // Laufzeit: O(|txt|)
  if (s == (int)txt.size()) { trie[vert].c++; return; }
  if (trie[vert].children[txt[s]] == -1) {
    trie[vert].children[txt[s]] = trie.size();
    trie.push_back(node());
  }
  insert(trie[vert].children[txt[s]], txt, s + 1);
}

int contains(int vert, vector<int> &txt, int s) { // Laufzeit: O(|txt|)
  if (s == (int)txt.size()) return trie[vert].c;
  if (trie[vert].children[txt[s]] != -1) {
    return contains(trie[vert].children[txt[s]], txt, s + 1);
  } else return 0;
}
