#include <bits/stdc++.h>

using namespace std;

int64_t n, q;
vector<pair<int64_t, int64_t> > houses;

int main(void)
{
    cin >> n >> q;
    houses.push_back(make_pair(0, 0));
    for(int64_t i = 1; i <= n; i++)
    {
	int64_t x, y;
	cin >> x >> y;
	houses.push_back(make_pair(x, y));
    }
    
    for(int64_t i = 1; i <= q; i++)
    {
	vector<pair<int64_t, int64_t> > zone;
	int64_t a, b;
	cin >> a >> b;
	zone.resize(b - a + 1);
	copy(houses.begin() + a, houses.begin() + b + 1, zone.begin());
	sort(zone.begin(), zone.end(), [&](const pair<int64_t, int64_t> &l, const pair<int64_t, int64_t> &r) { return(l.first < r.first); });
	int64_t x_range = zone.back().first - zone.front().first;
	int64_t xa = zone.back().first - zone[1].first;
	int64_t xb = zone[zone.size() - 2].first - zone.front().first;
	x_range = min(xa, min(xb, x_range));
	
	sort(zone.begin(), zone.end(), [&](const pair<int64_t, int64_t> &l, const pair<int64_t, int64_t> &r) { return(l.second < r.second); });
	int64_t y_range = zone.back().second - zone.front().second;
	int64_t ya = zone.back().second - zone[1].second;
	int64_t yb = zone[zone.size() - 2].second - zone.front().second;
	y_range = min(ya, min(yb, y_range));
	cout << max(x_range, y_range) << endl;
    }
    
    return(0);
}
