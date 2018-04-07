#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int64_t T, D;
    string program;
    cin >> T;
    for(int64_t i = 0; i < T; i++)
    {
	cin >> D >> program;
	
	int64_t dmg = 0;
	int64_t charge = 1;
	for(int k = 0; k < program.size(); k++)
	{
	    program[k] = tolower(program[k]);
	    char c = program[k];
	    if(c == 'c')
		charge *= 2;
	    if(c == 's')
		dmg += charge;
	}
	int result = 0;
	int64_t final_charge = charge;
	bool swap_happened = false;
	do
	{
	    swap_happened = false;
	    charge = final_charge;
	    for(int k = program.size() - 1; k > 0; k--)
	    {
		if(dmg <= D)
		    goto print;
		if(program[k] == 's' && program[k - 1] == 'c')
		{
		    program[k] = 'c';
		    program[k - 1] = 's';
		    dmg -= charge / 2;
		    charge /= 2;
		    result++;
		    swap_happened = true;
		}
		else if(program[k] == 'c')
		    charge /= 2;
	    }
	} while(swap_happened);
    print:
	cout << "Case #" << i + 1 << ": ";
	if(dmg > D)
	    cout << "IMPOSSIBLE" << endl;
	else
	    cout << result << endl;
    }
    return(0);
}
