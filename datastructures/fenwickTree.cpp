vector<int> FT; // Fenwick-Tree
int n;

// Addiert val zum Element an Index i. O(log(n)).
void updateFT(int i, int val) {
	i++; while(i <= n) { FT[i] += val; i += (i & (-i)); }
}

// Baut Baum auf. O(n*log(n)).
void buildFenwickTree(vector<int>& a) {
  n = a.size();
  FT.assign(n+1,0);
  for(int i = 0; i < n; i++)  updateFT(i,a[i]);
}

// Präfix-Summe über das Intervall [0..i]. O(log(n)).
int prefix_sum(int i) {
  int sum = 0; i++;
  while(i > 0) { sum += FT[i]; i -= (i & (-i)); }	
  return sum;
}
