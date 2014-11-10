vector<int> parent, rank2; //manche compiler verbieten Variable mit Namen rank

int findSet(int n) { //Pfadkompression
	if (parent[n] != n) parent[n] = findSet(parent[n]);
	return parent[n];
}

void linkSets(int a, int b) { //union by rank
	if (rank2[a] < rank2[b]) parent[a] = b;
	else if (rank2[b] < rank2[a]) parent[b] = a;
	else {
		parent[a] = b;
		rank2[b]++;
	}
}

void unionSets(int a, int b) {
	if (findSet(a) != findSet(b)) linkSets(findSet(a), findSet(b));
}
