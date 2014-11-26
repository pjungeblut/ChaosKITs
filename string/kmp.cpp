//Preprocessing Substring sub for KMP-Search
vector<int> kmp_preprocessing(string& sub) {
	vector<int> b(sub.size() + 1);
	b[0] = -1;
	int i = 0, j = -1;
	while(i < sub.size()) {
		while(j >= 0 && sub[i] != sub[j])
			j = b[j];
		i++; j++;
		b[i] = j;
	}
	return b;
}

//Searching after Substring sub in s
vector<int> kmp_search(string& s, string& sub) {
	vector<int> pre = kmp_preprocessing(sub);
	vector<int> result;
	int i = 0, j = -1;
	while(i < s.size()) {
		while(j >= 0 && s[i] != sub[j])
			j = pre[j];
		i++; j++;
		if(j == sub.size()) {
			result.push_back(i-j);
			j = pre[j];
		}
	}
	return result;
}
