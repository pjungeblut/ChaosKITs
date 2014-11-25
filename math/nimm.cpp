#Most important function!!
bool WinNimm(vector<int> game) {
	int result = 0;
	for(int s: game) result ^= s;
	return s > 0;
}
