//initialize adjmat, adjmat[i][i] = 0, adjmat[i][j] = INF if no edge is between i and j, length otherwise
for (k = 0; k < MAX_V; k++) {
	for (i = 0; i < MAX_V; i++) {
		for (j = 0; j < MAX_V; j++) {
			if (adjmat[i][k] + adjmat[k][j] < adjmat[i][j]) adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
		}
	}
}