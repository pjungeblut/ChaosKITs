//longest common substring.
struct lcse {
	int i = 0, s = 0;
};
string lcp(string s[2]) {
	if(s[0].length() == 0 || s[1].length() == 0) return "";
	vector<lcse> a(s[0].length()+s[1].length());
	for(int k = 0; k < a.size(); k++) a[k].i=(k < s[0].length() ? k : k - s[0].length()), a[k].s = (k < s[0].length() ? 0 : 1);
	sort(a.begin(), a.end(), [&] (const lcse &u, const lcse &l) {
		int ui = u.i, li = l.i;
		while(ui < s[u.s].length() && li < s[l.s].length()) {
			if(s[u.s][ui] < s[l.s][li]) return true;
			else if(s[u.s][ui] > s[l.s][li]) return false;
			ui++; li++;
		}
		return !(ui < s[u.s].length());
	});
	int r = 0, m=0, c=0;
	for(int i = 0; i < a.size() - 1; i++) { 
		if(a[i].s == a[i+1].s) continue;
		c = 0;
		while(a[i].i+c < s[a[i].s].length() && a[i+1].i+c < s[a[i+1].s].length() && s[a[i].s][a[i].i+c] == s[a[i+1].s][a[i+1].i+c]) c++;
		if(c > m) r=i, m=c;
	}
	return m == 0 ? "" : s[a[r].s].substr(a[r].i, m);
}
