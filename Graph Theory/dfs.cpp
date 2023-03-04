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
