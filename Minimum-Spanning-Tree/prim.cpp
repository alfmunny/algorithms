#define MAXN 500000
#include <vector>
#include <iostream>
#include <queue>

struct Edge {
  int to, from, w;
};

std::vector<Edge> edges[MAXN];
std::vector<Edge> mst;
int vis[MAXN];
auto cmp = [](Edge a, Edge b) { return a.w > b.w; };
std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> Q;

void visit(int v) 
{
  vis[v] = true;
  for (auto e : edges[v]) {
    if(!vis[e.to]) Q.push(e);
  }
}

void prim() 
{
  visit(0);
  while (!Q.empty()) 
  {
    Edge e = Q.top();
    Q.pop();
    if (vis[e.to] && vis[e.from]) continue;
    mst.push_back(e);
    if(!vis[e.to]) visit(e.to);
    if(!vis[e.from]) visit(e.from);
  }
}

int main()
{
  return 0;
}

