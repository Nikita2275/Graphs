#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<int> used;
bool Cycle = false;

void dfs(int v, int p) {
    used[v] = true;

    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, v);
        }
        else if (to != p) {
            Cycle = true;
        }
    }
}

int main()
{
    cout << "=== Cycle Detection in Undirected Graph ===\n\n";

    int n, m;
    cout << "Enter number of vertices (n) and edges (m): ";
    cin >> n >> m;

    g.resize(n);
    used.resize(n, false);

    cout << "\nEnter " << m << " edges (u v):\n";
    cout << "------------------------\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        u--; v--;  // Переход к 0-индексации
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << "\n--- Running DFS to detect cycle ---\n";

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cout << "Starting DFS from vertex " << i + 1 << endl;
            dfs(i, -1);
        }
    }

    cout << "\n--- Result ---\n";
    cout << "------------------------\n";

    if (Cycle) {
        cout << "YES - Graph contains a cycle!\n";
    }
    else {
        cout << "NO - Graph is acyclic (it's a tree or forest)\n";
    }

    cout << "------------------------\n";
    cout << "\nProgram finished.\n";

    return 0;
}