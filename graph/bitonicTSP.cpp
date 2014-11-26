vector< vector<double> > dp; //initialize with -1
vector< vector<double> > dist; //initialize with all dists between points
vector<int> lr, rl; //left-to-right and right-to-left paths
int n; //number of points
double get(int p1, int p2) { //call get(0, 0) to get length of shortest bitonic route
	int v = max(p1, p2) + 1;
	if (v == n - 1) return dist[p1][v] + dist[v][p2];
	if (dp[p1][p2] > -0.5) return dp[p1][p2];
	double tryLR = dist[p1][v] + get(v, p2), tryRl = dist[v][p2] + get(p1, v);
	if (tryLR < tryRL) lr.push_back(v); //reconstructs the path, pushes v to rl if the choice does not matter
	else rl.push_back(v); //change this if needed
	return min(tryLR, tryRL);
}