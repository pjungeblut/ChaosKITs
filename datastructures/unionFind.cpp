// Laufzeit: O(n*alpha(n))
// "size" ist obere Schranke für die Höhe der Bäume.
vector<int> parent, size;

int findSet(int n) { // Pfadkompression
	if (parent[n] != n) parent[n] = findSet(parent[n]);
	return parent[n];
}

void linkSets(int a, int b) { // Union by rank.
	if (size[a] < size[b]) parent[a] = b;
	else if (size[b] < size[a]) parent[b] = a;
	else {
		parent[a] = b;
		size[b]++;
	}
}

void unionSets(int a, int b) { // Diese Funktion aufrufen.
	if (findSet(a) != findSet(b)) linkSets(findSet(a), findSet(b));
}
