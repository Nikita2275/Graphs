#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    cout << "=== Shortest Path in Unweighted Graph (BFS) ===\n\n";

    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Ввод матрицы смежности
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "\nEnter the adjacency matrix (" << n << "x" << n << "):\n";
    cout << "(enter 0 or 1 for each cell)\n";
    cout << "------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Ввод начальной и конечной вершин
    int start, finish;
    cout << "\nEnter start vertex and finish vertex: ";
    cin >> start >> finish;

    // Переход к 0-индексации
    start--;
    finish--;

    cout << "\n--- Searching for shortest path ---\n";
    cout << "Start vertex: " << start + 1 << endl;
    cout << "Finish vertex: " << finish + 1 << endl;
    cout << "------------------------\n";

    // Проверка: если начальная и конечная вершины совпадают
    if (start == finish) {
        cout << "\nResult: " << 0 << " (start and finish are the same vertex)" << endl;
        cout << "------------------------\n";
        cout << "\nProgram finished.\n";
        return 0;
    }

    // BFS для поиска кратчайшего пути
    vector<int> dist(n, -1);  // -1 означает, что вершина еще не посещена
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // Проверяем всех соседей вершины v
        for (int to = 0; to < n; to++) {
            if (graph[v][to] == 1 && dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);

                // Опционально: выводим информацию о найденных путях
                cout << "Distance to vertex " << to + 1 << " = " << dist[to] << endl;
            }
        }
    }

    // Вывод результата
    cout << "\n------------------------\n";
    cout << "Result:\n";
    if (dist[finish] == -1) {
        cout << "No path found from vertex " << start + 1
            << " to vertex " << finish + 1 << endl;
    }
    else {
        cout << "Shortest path length from " << start + 1
            << " to " << finish + 1 << " = " << dist[finish] << endl;
    }
    cout << "------------------------\n";

    cout << "\nProgram finished.\n";

    return 0;
}