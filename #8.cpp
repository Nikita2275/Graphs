#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<int> price;
long long total_cost = 0;

void dfs(int v, int& min_cost) {
    used[v] = true;

    if (price[v] < min_cost) {
        min_cost = price[v];
    }

    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, min_cost);
        }
    }
}

int main()
{
    cout << "=== World of Farcraft: Rumor Spreading ===\n\n";

    int n, m;
    cout << "Enter number of characters (n) and friendships (m): ";
    cin >> n >> m;

    g.resize(n);
    used.resize(n, false);
    price.resize(n);

    cout << "\nEnter " << n << " hiring costs (c" << 1 << " to c" << n << "):\n";
    cout << "------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << "Cost for character " << i + 1 << ": ";
        cin >> price[i];
    }

    cout << "\nEnter " << m << " friendships (x y):\n";
    cout << "------------------------\n";
    for (int i = 0; i < m; i++) {
        int x, y;
        cout << "Friendship " << i + 1 << ": ";
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << "\n--- Finding minimum hiring cost in each friend group ---\n";
    cout << "------------------------\n";


    for (int i = 0; i < n; i++) {
        if (!used[i]) {

            int min_cost = price[i];
            dfs(i, min_cost);
            cout << "Friend group (starting from character " << i + 1
                << "): minimum hiring cost = " << min_cost << " gold" << endl;
            total_cost += min_cost;
        }
    }

    cout << "------------------------\n";
    cout << "\n--- Result ---\n";
    cout << "Minimum total gold needed: " << total_cost << endl;
    cout << "------------------------\n";

    return 0;
}