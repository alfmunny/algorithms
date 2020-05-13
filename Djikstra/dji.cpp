#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 10000

struct Edge {
  int to, w;
};

vector<Edge> edges[MAXN];

int dist[MAXN];
int vis[MAXN];
int pre[MAXN];

inline void add(int from, int to, int w)
{
  Edge e = {to, w};
  edges[from].push_back(e);
}

struct Polar {
  int dist, id;
  Polar(int dist, int id) : dist(dist), id(id) {}
};

struct cmp {
  bool operator () (Polar a, Polar b) {
    return a.dist > b.dist;
  }
};

priority_queue<Polar, vector<Polar>, cmp> Q;

void dji(int s) {
  dist[s] = 0;
  Q.push(Polar(0, s));

  while (!Q.empty())
  {
    int p = Q.top().id;
    Q.pop();
    if (vis[p])
      continue;

    vis[p] = 1;
    for (Edge e : edges[p])
    {
      if (dist[p] + e.w < dist[e.to])
      {
        pre[e.to] = p;
        dist[e.to] = dist[p] + e.w;
        if (!vis[e.to]) {
          Q.push(Polar(dist[e.to], e.to));
        }
      }
    }
  }
}

int main() {
  memset(vis, 0, sizeof(vis));
  memset(dist, 63, sizeof(dist));
  int n, m, s, t; // number of points, number of edges, source, target.

  scanf("%d", &n);
  scanf("%d", &m);
  cout << n <<" poins, " << m << " edges read" << endl;

  for (int i = 1; i <= n; i++)
  {
    pre[i] = i;
  }

  for (int i = 1; i <= m; i++)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    cout << "edge: " << u << ", " << v << ", " << w << endl;
    add(u, v, w);
  }

  scanf("%d", &s);
  scanf("%d", &t);

  cout << "Find shortest path for source " << s << endl;

  dji(s);

  cout << "The shortest path from " << s << " to "  << t << ": ";

  while (t != s)
  {
    printf("%d<-", t);
    t = pre[t];
  }
  printf("%d\n", t);

  cout << "All shortest path length from s " << s << endl;

  for ( int i = 1; i <= n; i++)
  {
    cout << s << " to " << i << " is " << dist[i] << endl;
  }

  return 0;
}
