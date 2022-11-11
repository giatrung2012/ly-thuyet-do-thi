#include<bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

//so may, so duong noi
int n, m;
int parent[100], sz[100];
vector<edge> canh;
ifstream ifs("input.txt");
ofstream ofs("output.txt");

void make_set() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = i;
    }
}

int find(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return false;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] + sz[b];
    return true;
}

void init() {
    ifs >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        ifs >> x >> y >> w;
        edge e;
        e.u = x;
        e.v = y;
        e.w = w;
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void kruskal() {
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for (int i = 0; i < m; i++) {
        if (mst.size() == n - 1) {
            break;
        }
        edge e = canh[i];
        if (Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    if (mst.size() != n - 1) {
        ofs << "Du an khong dap ung yeu cau ve tinh thong suot" << endl;
    } else {
        ofs << "Du an dap ung yeu cau ve tinh thong suot" << endl;
        ofs << "Tong chi phi noi toi thieu: " << d << endl;
        for (auto it : mst) {
            ofs << it.u << " " << it.v << " " << it.w << endl;
        }
    }
    cout << "Da xuat ket qua ra file output.txt" << endl;
}

int main() {
    init();
    make_set();
    kruskal();

    ifs.close();
    ofs.close();
    return 0;
}
