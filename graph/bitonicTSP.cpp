// Laufzeit: O(n^2)
vector<vector<double>> dist; // Initialisiere mit Entfernungen zwischen Punkten.

void bitonicTSP() {
    vector<double> dp(dist.size(), HUGE_VAL);
    vector<int> pre(dist.size()); // nur für Tour
    dp[0] = 0, dp[1] = 2 * dist[0][1], pre[1] = 0;
    for (unsigned int i = 2; i < dist.size(); i++) {
        double link = 0;
        for (int j = i - 2; j >= 0; j--) {
            link += dist[j + 1][j + 2];
            double opt = link + dist[j][i] + dp[j + 1] - dist[j][j + 1];
            if (opt < dp[i]) {
                dp[i] = opt;
                pre[i] = j;
    }}}
    // return dp[dist.size() - 1]; // Länger der Tour

    int n = dist.size() - 1;
    vector<int> lt, ut;
    lt.push_back(n), lt.push_back(n - 1);
    int j;
    do {
        j = pre[n];
        (lt.back() == n ? lt : ut).push_back(j);
        for (int i = n - 1; i > j + 1; i--) {
            (lt.back() == i ? lt : ut).push_back(i - 1);
        }
        n = j + 1;
    } while(j != 0);
    (lt.back() == 1 ? lt : ut).push_back(0);
    reverse(lt.begin(), lt.end());
    lt.insert(lt.end(), ut.begin(), ut.end());
    //return lt;// Enthält Knoten 0 zweimal. An erster und letzter Position.
}
