#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  vector<int> v;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        v.push_back(i);
        n /= i;
      }
    }
  }
  if (n > 1) v.push_back(n);
  for (auto x: v) cout << x << ' ';
  return 0;
}
