#define MAXN 50001

#include <iostream>
#include <vector>

using namespace std;

int r[MAXN]; //rank
int p[MAXN]; //parent


void init(int n) 
{
	for (int i = 0; i < n; ++i)
	{
		r[i] = 1;
		p[i] = i;
	}

}

int find(int v)
{
	if (p[v] == v)
		return v;
	else
		return p[v] = find(p[v]);
}


void unite(int v, int w)
{
	v = find(v);
	w = find(w);

	if (r[v] < r[w])
		p[v] = w;
	else {
		p[w] = v;
		if (r[v] == r[w]) r[v]++;
	}
}

struct edge { int from; int to; int d; };

int T, N, M, R;
int x[MAXN], y[MAXN], d[MAXN];
edge edges[MAXN];

bool cmp(const edge &a, const edge &b) { return a.d < b.d; }

int kruskal() {
	sort(edges, edges+R, cmp);
	init(N+M);
	int ret;
	for (int i = 0; i < R; ++i)
	{
		edge e = edges[i];
		if (find(e.from) != find(e.to))
		{
			unite(e.from, e.to);
			ret += e.d;
		}
	}
	return ret;
}


int main()
{
	scanf("%d", &T);
	while (T--) 
	{
		scanf("%d%d%d", &N, &M, &R);

		for (int i = 0; i < R; ++i) 
		{
			scanf("%d%d%d", &x[i], &y[i], &d[i]);
		}

		for (int i = 0; i < R; ++i)
		{
			edge e = {x[i], y[i]+N, -d[i]};
			edges[i] = e;
		}

		cout << 10000*(N+M) + kruskal() << endl;
	}
}
