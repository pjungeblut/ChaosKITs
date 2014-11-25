const int p[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int getLongestNumber(vector<int> &a) {
	int res = 0;
	for (int i = 0; i < (int)a.size(); i++) res = max(res, (int)ceil(log10(a[i]) + 1));
	return res;
}

int getIthDigit(int digit, int i) {
	return (digit / p[i]) % 10;
}

void radixSort(vector<int> &a) {
	int digits = getLongestNumber(a);
	for (int d = 0; d < digits; d++) {
		vector<int> bucket[10];
		for(int i = 0; i < (int)a.size(); i++)
			bucket[getIthDigit(a[i],d)].push_back(a[i]);
		a.clear();
		for(int i = 0; i < 10; i++)
			copy(bucket[i].begin(), bucket[i].end(), back_inserter(a));
	}
}