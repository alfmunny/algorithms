# MST

## Prim

The idea can be summarized in one sentence:

Keep adding new edges with smallest weight while visiting the vertices of the edges.

Notes: 

1. Use a priority queue two keep all the seen edges and find the new smallest one at ease.
2. Keep a `visited` to mark the vertices, and skip them if the edges you are seeing go back.

Complexity: |E|log|V| using indexed priority queue

Template:

```c++

void visit(int v) 
{
  vis[v] = true;
  for (auto e : edges[v]) {
    if(!vis[e.to]) Q.push(e); // push all reachable edges into PQ
  }
}

void prim() 
{
  visit(0);
  while (!Q.empty()) 
  {
    Edge e = Q.top(); // next smallest edge
    Q.pop();
    if (vis[e.to] && vis[e.from]) continue;
    mst.push_back(e);
    if(!vis[e.to]) visit(e.to); // find the edges of unvisited vertices
    if(!vis[e.from]) visit(e.from);
  }
}
```

## Kruskal

Works better if we know E is smaller than V

Use UnionFind to do find and unite operation.

1. sort all edges (ElogE), or push them into priority queue.
2. take the smallest edge, add two vertices to one union if they are not in one union. 

```c++
int kruskal() {
	sort(edges, edges+R, cmp); // sort all edges
	init(N+M); // initialize the union find
	int ret;
	for (int i = 0; i < R; ++i)
	{
		edge e = edges[i]; // next smallest edge
		if (find(e.from) != find(e.to)) // check if two vertices are in the same union
		{
			unite(e.from, e.to); // if not, connect them
			ret += e.d; // update the total weight
		}
	}
	return ret;
}
```

Application:

[POJ3727](http://poj.org/problem?id=3723): [code](poj3723.cpp), Hints: Kruskal
