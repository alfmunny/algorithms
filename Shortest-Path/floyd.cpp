#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int dist[400][400];

void Floyd(int n)
{
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

int main() {
  memset(dist, 63, sizeof(dist));
  int n;
  int m;

  scanf("%d", &n);
  scanf("%d", &m);

  for (int i = 1; i <=n; i++)
    dist[i][i] = 0;

  for (int i = 0; i < m; ++i)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    dist[u][v] = w;
  }

  Floyd(n);

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cout << "Shortest Path from " << i << " to "  << j  << ": " << dist[i][j] << endl;

  return 0;
}
