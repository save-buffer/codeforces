#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int h, m;
    cin >> h >> m;

    int H, D, C, N;
    cin >> H >> D >> C >> N;

    int cur_min = h * 60 + m;
    int store = 20 * 60;

    int min_to_discount = max(store - cur_min, 0);

    float with_discount = 0.8f * ceil((((float)H + (float)D * min_to_discount) / (float)N)) * C;
    float without_discount = ceil((float)H / (float)N) * C;

    cout << min(with_discount, without_discount) << endl;
    
    return(0);
}
