#include <bits/stdc++.h> 

using namespace std;
priority_queue <pair <int, pair <int, int> >, vector <pair <int, pair <int, int> > >, greater <pair <int, pair <int, int> > > > pq; 
int n;
int a[1000005]; 
int nxt[1000005], pre[1000005]; 
bool visited[1000005]; 

int main () {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
    if (i < n) {
      nxt[i] = i + 1; 
    }
    if (i > 1) {
      pre[i] = i - 1; 
    }
  }
  for (int i = 1; i < n; i++) {
    pq.push(make_pair(max(a[i], a[i + 1]), make_pair(i, i + 1)));
  }
  long long ans = 0LL;             
  while (pq.empty() == false) {
    pair <int, pair <int, int> > pqTop = pq.top();
    pq.pop(); 
    if (visited[pqTop.second.first] == true || visited[pqTop.second.second] == true) {
      continue; 
    }
    ans += pqTop.first; 
    int u = pqTop.second.first; 
    int v = pqTop.second.second; 
    if (a[u] > a[v]) {
      visited[v] = true; 
      nxt[u] = nxt[v]; 
      pre[nxt[u]] = u; 
      if (nxt[u] > 0) {
        pq.push(make_pair(max(a[u], a[nxt[u]]), make_pair(u, nxt[u]))); 
      }
    }
    else {
      visited[u] = true;
      pre[v] = pre[u];
      nxt[pre[v]] = v;
      if (pre[v] > 0) {
        pq.push(make_pair(max(a[pre[v]], a[v]), make_pair(pre[v], v))); 
      }  
    }
  }
  cout << ans;
  return 0; 
}