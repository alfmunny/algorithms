#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define MAXN 500000
using namespace std;

struct Edge { int to, cap, rev; };
vector<Edge> G[MAXN];
bool vis[MAXN];


void add(int from, int to, int cap) {
  G[from].push_back((Edge) {to, cap, (int) G[to].size()} );
  G[to].push_back((Edge) {from, cap, (int) (G[from].size() - 1)});
}

int dfs(int v, int t, int f) {
  if (v==t) return f;
  vis[v] = true;
  for (auto e : G[v]) {
    if (!vis[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[v][e.rev].cap += d;
        return d;
      }

    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int ret = 0;
  for (;;) {
    memset(vis, 0, sizeof(vis));
    int f = dfs(s, t, std::numeric_limits<int>::max());
    if (f==0) return ret;
    ret += f;
  }
}

int main() {
  return 0;
}

