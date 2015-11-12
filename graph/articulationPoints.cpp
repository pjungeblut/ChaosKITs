vector< vector<int> > adjlist;
vector<int> low;
vector<int> d;
vector<bool> isArtPoint;
vector< vector<int> > bridges; //nur fuer Bruecken
int counter = 0;

void visit(int v, int parent) {
	d[v] = low[v] = ++counter;
	int numVisits = 0, maxlow = 0;
	
	for (vector<int>::iterator vit = adjlist[v].begin(); vit != adjlist[v].end(); vit++) {
		if (d[*vit] == 0) {
			numVisits++;
			visit(*vit, v);
			if (low[*vit] > maxlow) {
				maxlow = low[*vit];
			}
			
			if (low[*vit] > d[v]) { //nur fuer Bruecken, evtl. parent betrachten!
				bridges[v].push_back(*vit);
				bridges[*vit].push_back(v);
			}
			
			low[v] = min(low[v], low[*vit]);
		} else {
			if (d[*vit] < low[v]) {
				low[v] = d[*vit];
			}
		}
	}
	
	if (parent == -1) {
		if (numVisits > 1) isArtPoint[v] = true;
	} else {
		if (maxlow >= d[v]) isArtPoint[v] = true;
	}
}

void findArticulationPoints() {
	low.clear(); low.resize(adjlist.size());
	d.clear(); d.assign(adjlist.size(), 0);
	isArtPoint.clear(); isArtPoint.assign(adjlist.size(), false);
	bridges.clear(); isBridge.resize(adjlist.size()); //nur fuer Bruecken
	for (int v = 0; v < (int)adjlist.size(); v++) {
		if (d[v] == 0) visit(v, -1);
	}
}