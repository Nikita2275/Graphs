#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "=== Graph Adjacency Matrix ===\n\n";

    int n, m;
    cout << "Enter number of vertices (n) and edges (m): ";
    cin >> n >> m;

    // Создаем матрицу смежности размером (n+1) x (n+1), заполненную нулями
    vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));

    cout << "\nEnter " << m << " edges (u v):\n";
    cout << "------------------------\n";

    for (int i = 1; i <= m; i++) {
        int u, v;
        cout << "Edge " << i << ": ";
        cin >> u >> v;

        // Неориентированный граф - ставим 1 в обе стороны
        g[u][v] = 1;
        g[v][u] = 1;
    }

    cout << "\nAdjacency Matrix (" << n << "x" << n << "):\n";
    cout << "------------------------\n";

    // Выводим номера вершин (заголовки столбцов)
    cout << "   ";
    for (int j = 1; j <= n; j++) {
        cout << " " << j;
    }
    cout << endl;

    cout << "   ";
    for (int j = 1; j <= n; j++) {
        cout << "--";
    }
    cout << endl;

    // Выводим матрицу
    for (int i = 1; i <= n; i++) {
        cout << i << " |";
        for (int j = 1; j <= n; j++) {
            cout << " " << g[i][j];
        }
        cout << endl;
    }

    cout << "------------------------\n";
    cout << "\nProgram finished.\n";

    return 0;
}