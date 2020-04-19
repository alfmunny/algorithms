#include <cstdio>
#include <cstring>
#define MAXN 1005
typedef long long ll;

int fa[MAXN], rank[MAXN];
ll X[MAXN], Y[MAXN], Z[MAXN];

inline bool next_to (ll x1, ll y1, ll z1, ll x2, ll y2, ll z2, ll r) 
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= 4 * r * r;
}

inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j)
{
    int x = find(i); int y = find(j);

    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;

    if (rank[x] == rank[y])
        rank[y]++;
}

int main()
{
    int T, n, h;
    ll r;
    scanf("%d", &T);

    for (int t = 0; t < T; ++t)
    {
        scanf("%d%d%lld", &n, &h, &r);

        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(Z, 0, sizeof(Z));

        init(n);
        fa[1001] = 1001;
        fa[1002] = 1002;

        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld%lld%lld", X+i, Y+i, Z+i);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (Z[i] <= r)
                merge(i, 1001);
            if (Z[i] + r >= h)
                merge(i, 1002);
        }

        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (next_to(X[i], Y[i], Z[i], X[j], Y[j], Z[j], r))
                    merge(i, j);

        printf("%s\n", find(1001) == find(1002) ? "Yes" : "No");
    }
}
