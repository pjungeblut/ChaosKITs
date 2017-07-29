// Laufzeit: O(n^2)
vector<vector<double>> dist; // Initialisiere mit Entfernungen zwischen Punkten.
vector<vector<double>> dp;
vector<vector<bool>> choice;

double get(int p1, int p2) {
    int v = max(p1, p2) + 1;
    if (v == dist.size()) return dist[p1][v - 1] + dist[p2][v - 1];
    if (dp[p1][p2] >= 0.0) return dp[p1][p2];
    double tryLR = dist[p1][v] + get(v, p2), tryRL = dist[p2][v] + get(p1, v);
	choice[p1][p2] = tryLR < tryRL;
	return dp[p1][p2] = min(tryLR, tryRL);
}

void bitonicTour() {
    dp = vector<vector<double>>(dist.size(), vector<double>(dist.size(), -1));
    choice = vector<vector<bool>>(dist.size(), vector<bool>(dist.size()));
    get(0, 0);
    // return dp[0][0]; // Länger der Tour
    vector<int> lr = {0}, rl = {0};
    for (int p1 = 0, p2 = 0, v; (v = max(p1, p2) + 1) < dist.size();) {
        if (choice[p1][p2]) {
            lr.push_back(v); p1 = v;
        } else {
            rl.push_back(v); p2 = v;
	}}
    lr.insert(lr.end(), rl.rbegin(), rl.rend());
    // return lr; // Enthält Knoten 0 zweimal. An erster und letzter Position.
}
