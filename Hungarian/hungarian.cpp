#include <string>
#include <iostream>

#define MAXM 10000
#define MAXN 10000

int M, N;
int E;
int Map[MAXM][MAXN];
int p[MAXN];
bool vis[MAXN];

bool match(int i)
{
  for (int j = 1; j <= N; ++j)
  {

    if (Map[i][j] && !vis[j])
    {
      vis[j] = true;
      if (p[j] == 0 || match(p[j])) 
      {
        p[j] = i;
        return true;
      }

    }
  }
  return false;
}

int Hungarian() 
{
  int cnt = 0;
  for (int i = 1; i <= M; ++i)
  {
    memset(vis, 0, sizeof(vis));
    if (match(i)) cnt++;

  }
  return cnt;
}

int main()
{
  scanf("%d%d", &M, &N);
  scanf("%d", &E);

  for (int e = 1; e <= E; ++e)
  {
    int i, j;
    scanf("%d%d", &i, &j);
    Map[i][j] = 1;
  }

  std::cout << "The maximum match: " << Hungarian() << std::endl;
  return 0;
}
