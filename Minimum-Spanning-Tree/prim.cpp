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

struct cmp {
  bool operator () (Edge a, Edge b) {
    return a.w > b.w;
  }
};

std::priority_queue<Edge, std::vector<Edge>, cmp> Q;

void add(int from, int to, int w) {
  edges[from].push_back((Edge) {to, from, w});
  edges[to].push_back((Edge) {from, to, w});
}

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

int mst_weight() 
{
  int sum = 0;
  for (auto e : mst)
    sum += e.w;
  return sum;
}

void print_edge(Edge e) {
    std::cout << "Edge: " << e.from << "<->" << e.to << " with " << e.w << std::endl;
}

int main()
{
  memset(vis, 0, sizeof(vis));
  int n, m;

  scanf("%d", &n);
  scanf("%d", &m);
  std::cout << n << " points, " << m << " edges" << std::endl;

  for (int i = 0; i < m; ++i) {
    int from, to, w;
    scanf("%d%d%d", &from, &to, &w);
    print_edge(Edge { from, to, w });
    add(from, to, w);
  }

  prim();
  std::cout << "MST:" << "with total weight " << mst_weight() << std::endl;
  for (auto e : mst) print_edge(e);

  return 0;
}
