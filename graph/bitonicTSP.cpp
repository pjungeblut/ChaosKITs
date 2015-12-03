// Laufzeit: O(|V|^2)
vector< vector<double> > dp; // Initialisiere mit -1
vector< vector<double> > dist; // Initialisiere mit Entfernungen zwischen Punkten.
vector<int> lr, rl; // Links-nach-rechts und rechts-nach-links Pfade.
int n; // #Knoten

// get(0, 0) gibt die Länge der kürzesten bitonischen Route.
double get(int p1, int p2) {
	int v = max(p1, p2) + 1;
	if (v == n - 1) return dist[p1][v] + dist[v][p2];
	if (dp[p1][p2] > -0.5) return dp[p1][p2];
	double tryLR = dist[p1][v] + get(v, p2), tryRl = dist[v][p2] + get(p1, v);
	if (tryLR < tryRL) lr.push_back(v); // Baut die Pfade auf. Fügt v zu rl hinzu, falls beide gleich teuer.
	else rl.push_back(v); // Änder das, falls nötig.
	return min(tryLR, tryRL);
}
