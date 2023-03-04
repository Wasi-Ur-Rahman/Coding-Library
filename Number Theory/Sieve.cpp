const int N = 1e7 + 9;
bool f[N];
vector<int> primes;

void sieve() {
  f[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!f[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= n; j += i) {
        f[j] = true;
      }
    }
  }
}
