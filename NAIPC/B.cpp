#include <bits/stdc++.h>

using namespace std;

int64_t n, m;

vector<set<int64_t> > graph;
vector<set<int64_t> > complement;

vector<set<int64_t> > cliques;

void compute_complement()
{
    complement.resize(n + 1);
    for(int i = 1; i <= n - 1; i++)
	for(int j = i + 1; j <= n; j++)
	{
	    complement[i].erase(j);
	    complement[j].erase(i);
	}

    for(int i = 1; i <= n; i++)
    {
	for(int64_t e : graph[i])
	{
	    complement[i].erase(e);
	    complement[e].erase(i);
	}
    }
}

void bronkerbosch(vector<set<int64_t> > &g, set<int64_t> r, set<int64_t> p, set<int64_t> x)
{
    if(p.empty() && x.empty())
	cliques.push_back(r);
    for(auto itr = p.begin(); itr != p.end();)
    {
	const int64_t v = *itr;
	auto new_r = r;
	new_r.insert(v);
	set<int64_t> new_p;
	set_intersection(p.begin(), p.end(), g[v].begin(), g[v].end(), inserter(new_p, new_p.begin()));

	set<int64_t> new_x;
	set_intersection(x.begin(), x.end(), g[v].begin(), g[v].end(), inserter(new_x, new_x.begin()));
	bronkerbosch(g, new_r, new_p, new_x);
	p.erase(itr);
	x.insert(v);
    }
}

int main(void)
{
    cin >> n >> m;
    graph.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
	uint64_t a, b;
	cin >> a >> b;
	
	graph[a].insert(b);
	graph[b].insert(a);
    }
    compute_complement();
    
    bronkerbosch(graph, set<int64_t>(), set<int64_t>(), set<int64_t>());
    bronkerbosch(complement, set<int64_t>(), set<int64_t>(), set<int64_t>());
    cout << cliques.size() << endl;
    return(0);
}
