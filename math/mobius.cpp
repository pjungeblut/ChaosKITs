// Laufzeit: O(N*log(log(N)))
int mu[N+1]; mu[1] = 1;
for (int i = 1; i <= N; i++) {
  for (int j = 2 * i; j <= N; j += i) mu[j] -= mu[i];
