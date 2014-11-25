vector<int> res;
void bucketSort(vector<int> &a) { //stores result in global vector res
	int c[BUCKETS] = {0};
	for (int i = 0; i < (int)a.size(); i++) c[a[i]]++;
	int C = 0;
	for (int i = 0; i < BUCKETS; i++) {
		int tmp = C;
		C += c[i];
		c[i] = tmp;
	}
	res.resize(a.size());
	for (int i = 0; i < (int)a.size(); i++) {
		res[c[a[i]]] = a[i];
		c[a[i]]++;
	}
}