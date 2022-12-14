#include <bits/stdc++.h> 

using namespace std;
long long ways[2][16][16][16][16][16]; 
struct problem {
  int ds, graph, mathgeo, dp, adhoc;
  problem() {
    ds = 0;
    graph = 0;
    mathgeo = 0;
    dp = 0;
    adhoc = 0; 
  } 
};
int n; 
int dpmin, dpmax;
int dsmin, dsmax;
int mathgeomin, mathgeomax;
int adhocmin, adhocmax;
int graphmin, graphmax;  
vector <problem> save; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int cnt;
    cin >> cnt; 
    problem p; 
    for (int j = 1; j <= cnt; j++) {
      string s;
      cin >> s;
      if (s == "ds") {
        p.ds++; 
      }
      else if (s == "graph") {
        p.graph++; 
      }
      else if (s == "mathgeo") {
        p.mathgeo++; 
      }
      else if (s == "dp") {
        p.dp++; 
      }
      else {
        p.adhoc++; 
      }
    }
    save.push_back(p); 
  }
  cin >> dpmin >> dpmax;
  cin >> graphmin >> graphmax;
  cin >> mathgeomin >> mathgeomax;
  cin >> dsmin >> dsmax; 
  cin >> adhocmin >> adhocmax; 
  ways[0][0][0][0][0][0] = 1; 
  for (int i = 0; i < n; i++) {
    int cur = i & 1; 
    int nxt = !cur; 
    memset(ways[nxt], 0, sizeof(ways[nxt])); 
    for (int ds = 0; ds <= 15; ds++) {
      for (int graph = 0; graph <= 15; graph++) {
        for (int mathgeo = 0; mathgeo <= 15; mathgeo++) {
          for (int dp = 0; dp <= 15; dp++) {
            for (int adhoc = 0; adhoc <= 15; adhoc++) {
              if (ways[cur][ds][graph][mathgeo][dp][adhoc] == 0) {
                continue; 
              }
              long long curValue = ways[cur][ds][graph][mathgeo][dp][adhoc]; 
              ways[nxt][ds][graph][mathgeo][dp][adhoc] += curValue; 
              if (ds + save[i].ds <= 15 && graph + save[i].graph <= 15 && mathgeo + save[i].mathgeo <= 15 && dp + save[i].dp <= 15 && adhoc + save[i].adhoc <= 15) {
                ways[nxt][ds + save[i].ds][graph + save[i].graph][mathgeo + save[i].mathgeo][dp + save[i].dp][adhoc + save[i].adhoc] += curValue; 
              }
            }
          }
        }
      }
    }
  }
  long long ans = 0LL; 
  for (int ds = dsmin; ds <= dsmax; ds++) {
    for (int graph = graphmin; graph <= graphmax; graph++) {
      for (int mathgeo = mathgeomin; mathgeo <= mathgeomax; mathgeo++) {
        for (int dp = dpmin; dp <= dpmax; dp++) {
          for (int adhoc = adhocmin; adhoc <= adhocmax; adhoc++) {
            ans += ways[n & 1][ds][graph][mathgeo][dp][adhoc]; 
          }
        }
      }
    }
  }
  if (dsmin + dpmin + mathgeomin + graphmin + adhocmin == 0) {
    ans--;
  }
  cout << ans; 
  return 0; 
}