#include <cstdio>
#include <cstring>
#define MAXN 50005
#define lowbit(x) ((x) & (-x))

int tree[MAXN];

inline void update(int i, int x)
{
    for (int pos = i; pos < MAXN; pos += lowbit(pos))
        tree[pos] += x;
}

inline int query(int n)
{
    int ans = 0;
    for (int i = n; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}

inline int query(int a, int b)
{
    return query(b) - query(a - 1);

}

int main()
{
    int cases;

    scanf("%d", &cases);
    for (int I = 1; I <= cases; ++I)
    {
        memset(tree, 0, sizeof(tree));
        int n, x, a, b;
        char opr[10];
        printf("Case %d:\n", I);

        scanf("%d", &n);

        for (int i = 1; i <=n; ++i)
        {
            scanf("%d", &x);
            update(i, x);
        }

        while (scanf("%s", opr), opr[0] != 'E')
        {
            switch (opr[0])
            {
                case 'A':
                    scanf("%d%d", &a, &b);
                    update(a, b);
                    break;
                case 'S':
                    scanf("%d%d", &a, &b);
                    update(a, -b);
                    break;
                case 'Q':
                    scanf("%d%d", &a, &b);
                    printf("%d\n", query(a, b));
            }
        }

    }
    return 0;
}
