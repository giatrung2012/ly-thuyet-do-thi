#include<bits/stdc++.h>
using namespace std;

struct canh {
    int x, y, w;
};

//dinh, canh, dinh bat dau
int n, m, s;
vector<pair<int, int>> adj[100];
bool used[100];
ifstream ifs("input.txt");
ofstream ofs("output.txt");

void init() {
    ifs >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        ifs >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    ifs >> s;
    memset(used, false, sizeof(used));
}

void prim(int u) {
    vector<canh> MST;
    int d = 0;
    used[u] = true;

    while (MST.size() < n - 1) {
        int min_w = INT_MAX;
        int X, Y;
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                for (pair<int, int> it : adj[i]) {
                    int j = it.first, trongso = it.second;
                    if (!used[j] && trongso < min_w) {
                        min_w = trongso;
                        X = j;
                        Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true;
    }
    if (MST.size() != n - 1) {
        ofs << "Do thi khong lien thong" << endl;
    } else {
        ofs << "Tong trong so cay khung nho nhat: " << d << endl;
        for (canh e : MST) {
            ofs << e.x << " " << e.y << " " << e.w << endl;
        }
    }
    cout << "Da xuat ket qua ra file output.txt" << endl;
}

int main() {
    init();
    prim(s);

    ifs.close();
    ofs.close();
    return 0;
}
