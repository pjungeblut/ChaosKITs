// Laufzeit: O(|V|^3)
// Initialize adjmat: adjmat[i][i] = 0, adjmat[i][j] = INF if no edge is between i and j, length otherwise.
void floydWarshall() {
	for (k = 0; k < NUM_VERTICES; k++) {
		for (i = 0; i < NUM_VERTICES; i++) {
			for (j = 0; j < NUM_VERTICES; j++) {
				if (adjmat[i][k] + adjmat[k][j] < adjmat[i][j]) adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
			}
		}
	}
}
