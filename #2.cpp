#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "=== Matrix to Adjacency List Converter ===\n\n";

    int N;
    cout << "Enter the number of vertices: ";
    cin >> N;

    vector<vector<int>> adj(N);

    cout << "\nEnter the adjacency matrix (" << N << "x" << N << "):\n";
    cout << "(enter 0 or 1 for each cell)\n";
    cout << "------------------------\n";

    for (int i = 0; i < N; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                adj[i].push_back(j + 1);
            }
        }
    }

    cout << "\nAdjacency List (neighbors of each vertex):\n";
    cout << "------------------------\n";

    for (int i = 0; i < N; ++i) {
        cout << "Vertex " << i + 1 << " -> ";
        if (adj[i].empty()) {
            cout << "(no neighbors)";
        }
        else {
            for (int v : adj[i]) {
                cout << v << " ";
            }
        }
        cout << endl;
    }

    cout << "------------------------\n";
    cout << "\nProgram finished.\n";

    return 0;
}