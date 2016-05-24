// Laufzeit: O(nm), Speicher: O(m), n = #s1, m = #s2
int levenshtein(string& s1, string& s2) {
	int len1 = s1.size(), len2 = s2.size();
	vector<int> col(len2 + 1), prevCol(len2 + 1);
	for (int i = 0; i < len2 + 1; i++) prevCol[i] = i;
	for (int i = 0; i < len1; i++) {
		col[0] = i + 1;
		for (int j = 0; j < len2; j++)
			col[j+1] = min(min(prevCol[j+1] + 1, col[j] + 1), prevCol[j] + (s1[i]==s2[j] ? 0 : 1));
		col.swap(prevCol);
	}
	return prevCol[len2];
}
