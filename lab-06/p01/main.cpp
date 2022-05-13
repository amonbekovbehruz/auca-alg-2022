#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

enum class Color
{
    White,
    Red,
    Black
};

void dfs(int u, const vector<vector<int>> &adList, vector<Color> &colors, vector<int> &comp)
{
    colors[u] = Color::Red;
    comp.push_back(u);
    for (auto v : adList[u])
    {
        if (colors[v] == Color::White)
        {
            dfs(v, adList, colors, comp);
        }
    }

    colors[u] = Color::Black;
}

int main()
{
    iostream::sync_with_stdio(false);

    int nVertices;
    cin >> nVertices;

    vector<vector<int>> adLists(nVertices);
    for (int r = 0; r < nVertices; r++)
    {
        for (int c = 0; c < nVertices; c++)
        {
            char ch;
            cin >> ch;

            if (ch == '1')
            {
                adLists[r].push_back(c);
            }
        }
    }

    // int row = 0;
    // for (const auto &list : adLists)
    // {
    //     cout << row++ << ": ";
    //     for (auto v : list)
    //     {
    //         cout << " " << v;
    //     }
    //     cout << endl;
    // }

    vector<Color> colors(nVertices, Color::White);

    int nComponents = 0;
    for (int i = 0; i < nVertices; i++)
    {

        if (colors[i] == Color::White)
        {
            ++nComponents;
            vector<int> currComponent;
            // dfs(depth first search)
            dfs(i, adLists, colors, currComponent);
            cout << ++nComponents << ": ";

            for (auto u : currComponent)
            {
                cout << " " << u;
            }
            cout << endl;
        }
    }
}