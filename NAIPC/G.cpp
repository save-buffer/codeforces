#include <bits/stdc++.h>

using namespace std;

int n, m;

//to, weight, color
vector<vector<tuple<int, int, char> > > rg;
vector<vector<tuple<int, int, char> > > bg;

auto cmp = [](const tuple<int, int, int, char> &a, const tuple<int, int, int, char> &b)
{    
    return(get<2>(a) < get<2>(b));
};

vector<tuple<int, int, char> > prim(vector<vector<tuple<int, int, char> > > &g)
{
    auto cmp = [&](const tuple<int, int, char> l, const tuple<int, int, char> r) { return(get<1>(l) < get<1>(r)); };
    priority_queue<tuple<int, int, char>, vector<tuple<int, int, char> >, decltype(cmp) > pq(cmp);

    vector<bool> in_mst(n + 1, false);
    vector<int> key(n + 1, INT_MAX);
    vector<tuple<int, int, char> > parent(n + 1, make_tuple(-1, -1, '\0'));
    parent[1] = make_tuple(1, 0, '\0');
    key[1] = 0;

    pq.push(parent[1]);
    while(!pq.empty())
    {
	int u = get<0>(pq.top());
	pq.pop();
	in_mst[u] = true;
	for(auto i : g[u])
	{
	    int v = get<0>(i);
	    int w = get<1>(i);
	    char c = get<2>(i);
	    if(!in_mst[v] && key[v] > w)
	    {
		key[v] = w;
		pq.push(make_tuple(v, key[v], c));
		parent[v] = make_tuple(u, w, c);
	    }
	}
    }
    return(parent);
}

set<tuple<int, int, int, char>, decltype(cmp)> setify_mst(vector<tuple<int, int, char> > mst)
{
    set<tuple<int, int, int, char>, decltype(cmp)> result(cmp);
    for(int i = 1; i <= n; i++)
    {
	result.insert(make_tuple(i, get<0>(mst[i]), get<1>(mst[i]), get<2>(mst[i])));
    }
    return(result);
}

set<tuple<int, int, int, char>, decltype(cmp)> setify_graph(vector<vector<tuple<int, int, char> > > &g)
{
    set<tuple<int, int, int, char>, decltype(cmp)> result(cmp);
    for(int i = 1; i <= n; i++)
    {
	for(auto e : g[i])
	{
	    result.insert(make_tuple(i, get<0>(e), get<1>(e), get<2>(e)));
	}
    }
    return(result);
}

int count_weight(set<tuple<int, int, int, char>, decltype(cmp) > mst)
{
    int sum = 0;
    for(auto i : mst)	
    {
	sum += get<2>(i);
    }
    return(sum);
}

int main(void)
{
    cin >> n >> m;
    rg.resize(n + 1);
    bg.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
	int a, b, w;
	char c;
	cin >> a >> b >> w >> c;
	if(c == 'R' || c == 'G')
	{
	    rg[a].push_back(make_tuple(b, w, c));
	    rg[b].push_back(make_tuple(a, w, c));
	}
	if(c == 'B' || c == 'G')
	{
	    bg[a].push_back(make_tuple(b, w, c));
	    bg[b].push_back(make_tuple(a, w, c));
	}	
    }
    auto rmst = prim(rg);
    auto bmst = prim(bg);

    auto rset = setify_mst(rmst);
    auto bset = setify_mst(bmst);

    set<tuple<int, int, int, char>, decltype(cmp) > total_mst(cmp);
    auto it = set_union(rset.begin(), rset.end(), bset.begin(), bset.end(), inserter(total_mst, total_mst.begin()));
    cout << "total mst size: " << total_mst.size() << endl;
    for_each(total_mst.begin(), total_mst.end(), [&](auto &e) { cout << get<0>(e) << "->" << get<1>(e) << " w: " << get<2>(e) << " c: " << get<3>(e) << endl; });

    auto rgset = setify_graph(rg);
    auto bgset = setify_graph(bg);
    set<tuple<int, int, int, char> > all_edges;
    set_union(rgset.begin(), rgset.end(), bgset.begin(), bgset.end(), inserter(all_edges, all_edges.begin()));


    set<tuple<int, int, int, char>, decltype(cmp)> remaining_edges(cmp);
    set_difference(all_edges.begin(), all_edges.end(), total_mst.begin(), total_mst.end(), inserter(remaining_edges, remaining_edges.begin()));
    
    int total_weight =  count_weight(total_mst);

    auto set_iter = remaining_edges.begin();
    cout << remaining_edges.size() + total_mst.size() << endl;
    for(int i = 1; i <= m; i++)
    {
	if(i < n)
	{
	    cout << "-1" << endl;
	    continue;
	}
	else if(i == total_mst.size() - 1)
	{
	    cout << total_weight << endl;
	}
	else
	{
	    total_weight += get<2>(*set_iter++);
	    cout << total_weight << endl;
	}
	
    }
    return(0);
}
