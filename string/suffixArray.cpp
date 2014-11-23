//longest common substring in one string (overlapping not excluded)
//contains suffix array:--------------------------------------------------------------------
int cmp(string &s,vector<vector<int>> &v, int i, int vi, int u, int l) {
	int vi2 = (vi + 1) % 2, u2 = u + i / 2, l2 = l + i / 2; 
	if(i == 1) return s[u] - s[l];
	else if (v[vi2][u] != v[vi2][l]) return (v[vi2][u] - v[vi2][l]);
	else { //beide groesser tifft nicht mehr ein, da ansonsten vorher schon unterschied in Laenge
		if(u2 >= s.length()) return -1;
		else if(l2 >= s.length()) return 1;
		else return v[vi2][u2] - v[vi2][l2];
	}
}

string lcsub(string s) {
	if(s.length() == 0) return "";
	vector<int> a(s.length());
	vector<vector<int>> v(2, vector<int>(s.length(), 0));
	int vi = 0;
	for(int k = 0; k < a.size(); k++) a[k] = k;	
	for(int i = 1; i <= s.length(); i *= 2, vi = (vi + 1) % 2) {
		sort(a.begin(), a.end(), [&] (const int &u, const int &l) {
			return cmp(s, v, i, vi, u, l) < 0;
		});
		v[vi][a[0]] = 0;
		for(int z = 1; z < a.size(); z++) v[vi][a[z]] = v[vi][a[z-1]] + (cmp(s, v, i, vi, a[z], a[z-1]) == 0 ? 0 : 1);
	}
//-------------------------------------------------------------------------------------------
	int r = 0, m=0, c=0;
	for(int i = 0; i < a.size() - 1; i++) {
		c = 0;
		while(a[i]+c < s.length() && a[i+1]+c < s.length() && s[a[i]+c] == s[a[i+1]+c]) c++;
		if(c > m) r=i, m=c;
	}
	return m == 0 ? "" : s.substr(a[r], m);
}

