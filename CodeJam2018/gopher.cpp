#include <bits/stdc++.h>

using namespace std;

bool check_3x3(int cx, int cy, const vector<vector<bool> > &land)
{
    for(int i = cx - 1; i <= cx + 1; i++)
	for(int j = cy - 1; j <= cy + 1; j++)
	    if(!land[i][j])
		return(false);
    return(true);
}

int main(void)
{
    int T;
    cin >> T;
    for(int z = 0; z < T; z++)
    {
	int64_t A;
	cin >> A;
	vector<vector<bool> > land(1000);
	for_each(land.begin(), land.end(), [&](auto &i) { i.resize(1000, false); });

	int tx = 2;
	int ty = 2;
	for(;;)
	{
	    cout << tx << ' ' << ty << endl;
	    int i, j;
	    cin >> i >> j;
	    land[i][j] = true;
	    if(i == 0 && j == 0)
		break;
	    else if(i == -1 && j == -1)
		return(0);

	    if(check_3x3(tx, ty, land))
		tx += 2;
	}
    }
    return(0);
}
