#include <iostream>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
set<int> adj[100];
int deg[100];
//dinh bat ky
int k;
ifstream ifs("input.txt");
ofstream ofs("output.txt");
int cnt = 0;

void nhap() {
    ifs >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        ifs >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
    ifs >> k;
}

bool check() {
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 != 0) {
            cnt++;
        }
    }
    if (cnt == 0 || cnt == 2) {
        return true;
    }
    return false;
}

void euler(int v) {
    stack<int> st;
    vector<int> EC;
    st.push(v);
    int x, y;
    while (!st.empty()) {
        x = st.top();
        if (!adj[x].empty()) {
            y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(begin(EC), end(EC));
    if (check()) {
        if (EC.front() == EC.back()) {
            ofs << "Chu trinh Euler: ";
        } else {
            ofs << "Duong di Euler: ";
        }
        for (int item : EC) {
            ofs << item << " ";
        }
    } else {
        ofs << "Do thi khong cho chu trinh hoac duong di Euler" << endl;
    }
    cout << "Da xuat ket qua ra file output.txt" << endl;
}

int main() {
    nhap();
    euler(k);
    ifs.close();
    ofs.close();
    return 0;
}
