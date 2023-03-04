const int N = 3e5 + 9;
int par[N],sz[N];

void make(int v) {
  par[v] = v;
  sz[v] = 1;
}
int find(int i) {
  return (par[i] == i ? i : (par[i] = find(par[i])));
}
int get_size(int i) {
  return sz[find(i)];
}
int merge(int i, int j) {
  i = find(i);
  j = find(j);
  
  if (i != j) {
    if (sz[i] < sz[j]) swap(i,j);
    par[j] = a;
    sz[a] += sz[b];
  }
}
