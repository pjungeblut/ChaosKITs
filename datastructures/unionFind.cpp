// Laufzeit: O(n*alpha(n))
// "height" ist obere Schranke für die Höhe der Bäume. Sobald
// Pfadkompression angewendet wurde, ist die genaue Höhe nicht mehr
// effizient berechenbar.
vector<int> parent // Initialisiere mit Index im Array.
vector<int> height; // Initialisiere mit 0.

int findSet(int n) { // Pfadkompression
	if (parent[n] != n) parent[n] = findSet(parent[n]);
	return parent[n];
}

void linkSets(int a, int b) { // Union by rank.
	if (height[a] < height[b]) parent[a] = b;
	else if (height[b] < height[a]) parent[b] = a;
	else {
		parent[a] = b;
		height[b]++;
}}

void unionSets(int a, int b) { // Diese Funktion aufrufen.
	if (findSet(a) != findSet(b)) linkSets(findSet(a), findSet(b));
}
