vector<int> FT; //Fenwick-Tree
int n;

//Build an Fenwick-Tree over an array a. Time Complexity: O(n*log(n))
void buildFenwickTree(vector<int>& a) {
  n = a.size();
  FT.assign(n+1,0);
  for(int i = 0; i < n; i++)  updateFT(i,a[i]);
}

//Prefix-Sum of intervall [0..i]. Time Complexity: O(log(n))
int prefix_sum(int i) {
  int sum = 0; i++;
  while(i > 0) { sum += FT[i]; i -= (i & (-i)); }	
  return sum;
}

//Adds val to index i. Time Complexity O(log(n))
void updateFT(int i, int val) {
	i++; while(i <= n) { FT[i] += val; i += (i & (-i)); }
}
	
