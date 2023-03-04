const int p = 137, mod = 1e9 + 7;

const int N = 1e5 + 9;

int pw[N];
void prec() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = 1LL * pw[i - 1] * p % mod;
  }
}
int get_hash(string s) {
  int n = s.size();
  int hs = 0;
  for (int i = 0; i < n; i++) {
    hs += 1LL * s[i] * pw[i] % mod;
    hs %= mod;
  }
  return hs;
}
