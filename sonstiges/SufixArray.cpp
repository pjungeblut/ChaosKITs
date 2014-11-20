//longest common substring in one string (overlapping not excluded)
string lsubs(string s) {
	if(s.length() == 0) return "";
	vector<int> a(s.length());
	for(int k = 0; k < a.size(); k++) a[k] = k;
	sort(a.begin(), a.end(), [&] (const int &u, const int &l) {
		int ui = u, li = l;
		while(ui < s.length() && li < s.length()) {
			if(s[ui] < s[li]) return true;
			else if(s[ui] > s[li]) return false;
			ui++; li++;
		}
		return !(ui < s.length());
	});
	int r = 0, m=0, c=0;
	for(int i = 0; i < a.size() - 1; i++) {
		c = 0;
		while(a[i]+c < s.length() && a[i+1]+c < s.length() && s[a[i]+c] == s[a[i+1]+c]) c++;
		if(c > m) r=i, m=c;
	}
	return m == 0 ? "" : s.substr(a[r], m);
}
