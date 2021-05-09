#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

struct edge { int u, v, c; };
typedef vector<edge>::iterator iter;

int dijkstra(int z, const vector<edge> &E, const vector<iter> &s) {
    if (s[z] == E.end()) return -1;

    priority_queue<pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > heap;
    vector<int> f(s.size(), 0);

    heap.push(make_pair(s[z]->c, s[z]));
    while (!heap.empty()) {
        pair <int, int> x = heap.top();
        if (x.first == z) return x.second;

        int u = x.second;
        f[u] = x.s;
        if (s[u] != E.end()) heap.push({x.s + s[u]->c, s[u]});

        while (f[heap.top().it->v]) {
            iter it = heap.top().it;
            heap.pop();
            int u = it->u;
            while (it != E.end() && it->u == u) {
                if (!f[it->v]) {
                    heap.push({f[u] + it->c, it});
                    break;
                }
                it++;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<edge> E(m);
        for (auto &e: E) {
            cin >> e.u >> e.v >> e.c;
            e.u--, e.v--;
        }

        sort(E.begin(), E.end(), [](const edge &a, const edge &b){
                return a.c<b.c;
            });
        stable_sort(E.begin(), E.end(), [](const edge &a, const edge &b){
                return a.u<b.u;
            });
        vector<iter> s(n, E.end());
        for (auto it=E.begin(); it != E.end(); it++) {
            if (s[it->u] == E.end()) s[it->u] = it;
        }

        for (int i=0; i<n; i++) {
            cout << dijkstra(i, E, s) << '\n';
        }
    }
    return 0;
}