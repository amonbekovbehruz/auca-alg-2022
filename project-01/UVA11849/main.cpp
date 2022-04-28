#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    int m;
    int x;
    cin >> num;
    cin >> m;

    unordered_set<int> set;
    unordered_set<int> set2;

    while (num != 0)
    {
        for (int i = 0; i < num; ++i)
        {
            cin >> x;
            set.insert(x);
        }

        for (int i = 0; i < m; ++i)
        {
            cin >> x;
            set2.insert(x);
        }

        int ans = 0;

        for (auto i : set)
        {
            if (set2.find(i) != set2.end())
            {
                ans++;
            }
        }
        cout << ans << endl;
        set.clear();
        set2.clear();
        cin >> num >> m;
    }
    return 0;
}