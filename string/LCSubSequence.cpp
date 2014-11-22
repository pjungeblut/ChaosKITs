string lcss(string &a, string &b) {
	int m[a.length() + 1][b.length() + 1], x=0, y=0;
	memset(m, 0, sizeof(m));
	for(int y = a.length() - 1; y >= 0; y--) {
		for(int x = b.length() - 1; x >= 0; x--) {
			if(a[y] == b[x]) m[y][x] = 1 + m[y+1][x+1];
			else m[y][x] = max(m[y+1][x], m[y][x+1]);
		}
	} //for length only: return m[0][0];
	string res;
	while(x < b.length() && y < a.length()) {
		if(a[y] == b[x]) res += a[y++], x++;
		else if(m[y][x+1] > m[y+1][x+1]) x++;
		else y++;
	}
	return res;
}
