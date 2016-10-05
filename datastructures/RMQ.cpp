vector<int> data(RMQ_SIZE);
vector<vector<int>> rmq(floor(log2(RMQ_SIZE))+1, vector<int>(RMQ_SIZE));

// Baut Struktur auf. O(n*log(n))
void initRMQ() {
	for(int i = 0, s = 1, ss = 1; s <= RMQ_SIZE; ss=s, s*=2, i++) {
		for(int l = 0; l + s <= RMQ_SIZE; l++) {
			if(i == 0) rmq[0][l] = l;
			else {
				int r = l + ss;
				rmq[i][l] = (data[rmq[i-1][l]] <= data[rmq[i-1][r]]) ?
						rmq[i-1][l] : rmq[i-1][r];
}}}}

// Gibt den Index des Minimums im Intervall [l,r) zurück. O(1).
int queryRMQ(int l, int r) {
	if(l >= r) return l;
	int s = floor(log2(r-l)); r = r - (1 << s);
	return (data[rmq[s][l]] <= data[rmq[s][r]] ? rmq[s][l] : rmq[s][r]);
}
