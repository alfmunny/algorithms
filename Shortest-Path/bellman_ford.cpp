#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct edge
{
  int from;
  int to;
  int w;
};

int dist[400];
edge edges[160000];

void Bellman_Ford(int n, int m)
{
  for (int i = 0; i < n - 1; ++i)
    for (int j = 1; j <= m; ++j)
      dist[edges[j].to] = min(dist[edges[j].to], dist[edges[j].from] + edges[j].w);
}

int main() {
  memset(dist, 63, sizeof(dist));
  int n;
  int m;

  scanf("%d", &n);
  scanf("%d", &m);

  for (int i = 1; i <=n; i++)
    dist[i] = 0x3f3f3f3f;

  dist[1] = 0;

  for (int i = 1; i <= m; ++i)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edge e = {u, v, w};
    edges[i] = e;
  }

  Bellman_Ford(n, m);

  int ans = 0x3f3f3f3f;
  int to = 0;
  for (int i = 2; i <= n; i++) 
  { 
    cout << "Shortest Path from " << 1 << " to "  <<  i << ": " << dist[i] << endl;
  }

  return 0;
}
