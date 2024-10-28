#include "Queue.h"
#include "Vector.h"
#include <bits/stdc++.h>

using namespace std;

class DoThi {
    int n, m; // n là số đỉnh, m là số cạnh
    Vector<Vector<int>> matrix; // Ma trận kề (chỉ lưu thông tin kết nối giữa các đỉnh)

public:
    DoThi() {
        n = 0;
        m = 0;
    }
    
    DoThi(int n, int m) {
        this->n = n;
        this->m = m;
        matrix.resize(n, Vector<int>(n, 0)); // Khởi tạo ma trận kề với giá trị 0
    }

    void nhap_file() {
        freopen("input.txt", "r", stdin);
        cin >> n >> m;
        matrix.resize(n, Vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            matrix[u][v] = 1;
            matrix[v][u] = 1;
        }
        // fclose(stdin);
    }

    void xuat_file() {
        freopen("output.txt", "w", stdout);
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        // fclose(stdout);
    }

    void BFS(int u, int v) {
        // Kiểm tra nếu đỉnh u hoặc v không hợp lệ
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Mot trong cac dinh " << u << " hoac " << v << " khong ton tai trong do thi." << endl;
            return;
        }

        Vector<int> distance(n, INT_MAX);  // Khoảng cách từ u đến các đỉnh
        Vector<int> parent(n, -1);         // Đỉnh cha trong đường đi ngắn nhất
        Vector<bool> visited(n, false);    // Mảng đánh dấu đã thăm
        
        Queue<int> q;  // Hàng đợi chỉ chứa đỉnh
        distance[u] = 0;
        q.push(u);
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            if (visited[current]) continue;
            visited[current] = true;
            
            // Duyệt các đỉnh kề
            for (int i = 0; i < n; i++) {
                if (matrix[current][i] == 1 && !visited[i]) { // Chỉ xét đỉnh kề
                    if (distance[current] + 1 < distance[i]) {
                        distance[i] = distance[current] + 1;
                        parent[i] = current;
                        q.push(i);
                    }
                }
            }
        }

        // In kết quả
        if (distance[v] == INT_MAX) {
            cout << "Khong co duong di tu " << u << " den " << v << endl;
        } else {
            cout << "Duong di ngan nhat tu " << u << " den " << v << " co do dai: " << distance[v] << endl;
            cout << "Cac dinh tren duong di: ";
            Vector<int> path;
            for (int i = v; i != -1; i = parent[i]) {
                path.push_back(i);
            }
            
            // In đường đi
            for (int i = path.get_size() - 1; i >= 0; i--) {
                cout << path[i];
                if (i > 0) cout << " -> ";
            }
            cout << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    DoThi G;
    G.nhap_file();
    G.xuat_file();
    int u, v; cin >> u >> v;
    G.BFS(u, v);
    return 0;
}
