#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, int> map;
    
    int t;
    int beg = 1;
    cin >> t;

    int answer = 0;
    for (int i = 0; i < t; ++i)
    {
        int temp; 
        cin >> temp;

        for(int j = 1; j <= temp; ++j)
        {
            int n;
            cin >> n;
            if(map[n] >= beg)
            {
                if(j - beg > answer)
                {
                    answer = j - beg;
                    beg = map[n] + 1;
                }
            }
             map[n] = j;

        }

        if(t + 1 - beg > answer)
        {
            answer = t + 1 - beg;
        }
        cout << answer << endl;       
    }
}