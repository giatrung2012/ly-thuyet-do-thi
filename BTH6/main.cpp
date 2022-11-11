#include<bits/stdc++.h>
using namespace std;

//dinh, canh, dinh bat dau
int n, m, s, t;
vector<pair<int, int>> adj[100];
int pre[100];
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
    ifs >> s >> t;
}

void dijkstra(int s, int t) {
    int e = t;
    vector<int> d(n + 1, 100);
    d[s] = 0;
    pre[s] = s;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        Q.pop();
        int u = top.second;
        int kc = top.first;
        if (kc > d[u]) {
            continue;
        }
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
                pre[v] = u;
            }
        }
    }
    vector<int> path;
    while (1) {
        path.push_back(t);
        if (t == s) {
            break;
        }
        t = pre[t];
    }
    reverse(begin(path), end(path));
    ofs << "Duong di ngan nhat tu " << s << " den " << e << ": " << endl;
    for (int x : path) {
        ofs << x << " ";
    }
    ofs << endl;
    ofs << "Chi phi: " << d[e] << endl;
    cout << "Da xuat ket qua ra file output.txt" << endl;
}

int main() {
    init();
    dijkstra(s, t);

    ifs.close();
    ofs.close();
    return 0;
}
