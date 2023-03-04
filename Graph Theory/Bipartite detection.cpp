const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N]; int col[N];
bool ok;

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      col[v] = col[u] ^ 1;
      dfs(v); 
    }
    else {
      if (col[u] == col[v]) {
        ok = false;
      }
    }
  }
}
