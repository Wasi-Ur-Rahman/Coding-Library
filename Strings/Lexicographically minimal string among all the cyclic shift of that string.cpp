// LCP using Hash Function, Lexicographically minimal string among all the cyclic shift of that string
const int N = 2e5 + 10;
const int mod1 = 1e9 + 7,p1 = 137,mod2 = 1e9 + 9,p2 = 227;

pair<int,int> pw[N],ipw[N];

int power(int n,int k,int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;

  while (k) {
    if (k & 1) {
      ans = (ans * n) % mod;
    }
    n = n * n % mod;
    k >>= 1;
  }
  return ans;
}

void prec() {
  pw[0] = {1,1};
  for (int i = 1;i < N;i++) {
    pw[i].F = pw[i - 1].F * p1 % mod1;
    pw[i].S = pw[i - 1].S * p2 % mod2;
  }
  
  int ip1 = power(p1,mod1 - 2,mod1);
  int ip2 = power(p2,mod2 - 2,mod2);
  ipw[0] = {1,1};

  for (int i = 1;i < N;i++) {
    ipw[i].F = ipw[i - 1].F * ip1 % mod1;
    ipw[i].S = ipw[i - 1].S * ip2 % mod2;
  }
}
// dual hash
struct Hashing{
  vector<pair<int,int>> pf;
  Hashing() {

  }
  void build(string s) {
    int n = s.size();
    int p = s[0] * pw[0].F % mod1;
    int q = s[0] * pw[0].S % mod2;
    pf.pb({p,q});
    for (int i = 1;i < n;i++) {
      p = (pf[i - 1].F + s[i] * pw[i].F % mod1) % mod1;
      q = (pf[i - 1].S + s[i] * pw[i].S % mod2) % mod2;
      pf.pb({p,q});
    }
  }
  pair<int,int> gethash(int i,int j) {
    assert(i <= j);
    pair<int,int> hs({0,0});
    hs.F = pf[j].F;
    if (i) hs.F = (hs.F - pf[i - 1].F + mod1) % mod1;
    hs.F = hs.F * ipw[i].F % mod1;

    hs.S = pf[j].S;
    if (i) hs.S = (hs.S - pf[i - 1].S + mod2) % mod2;
    hs.S = hs.S * ipw[i].S % mod2;

    return hs;
  }
};
// Longest common prefix
int lcp(int i,int j,int x,int y) { // logn
  int l = 1,r = min(j - i + 1,y - x + 1),ans = 0;

  while (l <= r) {
    int mid = l + r >> 1;

    if (a.gethash(i,i + mid - 1) == a.gethash(x,x + mid - 1)) {
      ans = mid;
      l = mid + 1;
    }else r = mid - 1;
  }

  return ans;
}
string s;
// comparing two substrings which is lexicographically smaller
char ok(int &l,int &r,int &x,int &y) { // logn
  if (s[l] < s[x]) return '<';
  if (s[l] > s[x]) return '>';

  int ans = lcp(l,r,x,y);
  if (ans == r - l + 1) return '<';
  if (ans == y - x + 1) return '>';

  int mn = min(r - l + 1,y - x + 1);
  if (ans == mn) return '=';
  else {
    if (s[l + ans] > s[x + ans]) return '>';
    return '<';
  }
}
// cmp function for sorting
bool cmp(pair<int,int>& l,pair<int,int>& r) {
  if (ok(l.F,l.S,r.F,r.S) == '<') return 1;
  return 0;
}
