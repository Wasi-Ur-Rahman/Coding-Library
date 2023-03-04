#include <bits/stdc++.h>
// #ifndef ONLINE_JUDGE
//  #include "dbg.h"
// #endif
#define int int64_t
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;



const int N = 2e6 + 10;
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

struct Hashing{
  int n;
    string s;
    vector<pair<int, int>> hs;
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for(int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % mod1) % mod1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % mod2) % mod2;
            hs.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) {
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + mod1) * 1LL * ipw[l - 1].first % mod1;
        ans.second = (hs[r].second - hs[l - 1].second + mod2) * 1LL * ipw[l - 1].second % mod2;
        return ans;
    }
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};

// checking if a palindrome exist of length l
bool ache(Hashing& ha, Hashing& hb, int l) {
    for(int i = 1; i + l - 1 <= ha.n; i++) {
        int j = i + l - 1;
        if(ha.get_hash(i, j) == hb.get_hash(ha.n - j + 1, ha.n - i + 1)) return true;
    }
    return false;
}

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);

  

  string s;
  cin >> s;
  prec();
  string rs = s;
  reverse(all(rs));

  Hashing a(s),b(rs);

  int l = 1,r = (s.size() + 1)/2,ans1 = 0;

  while (l <= r) {
    int mid = l + r >> 1;

    if (ache(a,b,2*mid)) {
      ans1 = mid;
      l = mid + 1;
    }else r = mid - 1;
  }
  l = 1,r = (s.size() + 1)/2;
  int ans2 = 1;

  while (l <= r) {
    int mid = l + r >> 1;

    if (ache(a,b,2*mid - 1)) {
      ans2 = mid;
      l = mid + 1;
    }else r = mid - 1;
  }
  int mx = max(2*ans1,2*ans2 - 1);

  for (int i = 1;i + mx - 1 <= a.n;i++) {
    int j = i + mx - 1;

    if (a.get_hash(i,j) == b.get_hash(a.n - j + 1,a.n - i + 1)) {
      cout << s.substr(i-1,mx);
      break;
    }
  }
}
