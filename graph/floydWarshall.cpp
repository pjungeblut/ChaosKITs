// Laufzeit: O(|V|^3)
// Initialisiere mat: mat[i][i] = 0, mat[i][j] = INF falls i & j nicht adjazent, Länge sonst.
void floydWarshall() {
	for (k = 0; k < MAX_V; k++) {
		for (i = 0; i < MAX_V; i++) {
			for (j = 0; j < MAX_V; j++) {
				if (mat[i][k] != INF && mat[k][j] != INF && mat[i][k] + mat[k][j] < mat[i][j]) {
					mat[i][j] = mat[i][k] + mat[k][j];
				}
			}
		}
	}
}
