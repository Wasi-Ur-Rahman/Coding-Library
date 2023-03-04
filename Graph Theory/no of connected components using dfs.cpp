#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v); 
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  // dfs(1);
  // for (int i = 1; i <= n; i++) {
  //   if (!vis[i]) {
  //     cout << "Disconnected Graph\n";
  //     return 0;
  //   }
  // }
  // cout << "Connected Graph\n";
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      ++ans;
    }
  }
  cout << "Connected Components = " << ans << '\n';
  return 0;
}
