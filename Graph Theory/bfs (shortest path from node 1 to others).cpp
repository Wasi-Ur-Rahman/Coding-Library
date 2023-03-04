#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N]; int dis[N], par[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<int> q;
  q.push(1); vis[1] = true; dis[1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v: g[u]) {
      if (!vis[v]) {
        q.push(v);
        par[v] = u;
        dis[v] = dis[u] + 1;
        vis[v] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
}
