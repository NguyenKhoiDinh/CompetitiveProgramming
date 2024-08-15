#include <iostream>
#include <algorithm>
#include <math.h> 
#include <vector> 
#include <utility>
#include <deque>
unsigned long long ans = 9000000000000000007LL;
unsigned long long total = 0LL;  
int nA, nB;
std::vector <unsigned long long> fA_out, fA_in, sqA_out, sqA_in, szA;
std::vector <unsigned long long> fB_out, fB_in, sqB_out, sqB_in, szB;
std::vector <std::vector <int> > adjA, adjB;   
struct line {
  unsigned long long a, b;
  long double x;  
};              
bool compareA(const line &l1, const line &l2) {
  return (l1.a > l2.a || (l1.a == l2.a && l1.b < l2.b)); 
}
bool compareB(const line &l1, const line &l2) {
  return l1.a < l2.a; 
}
std::deque <line> hull; 
unsigned long long query(const unsigned long long &x) {
  while ((int) hull.size() >= 2 && hull[0].a * x + hull[0].b > hull[1].a * x + hull[1].b) {
    hull.pop_front(); 
  } 
  return hull[0].a * x + hull[0].b; 
}                                                
long double intersect(const line &l1, const line &l2) {
  long long deno = l2.b - l1.b; 
  long long nume = l1.a - l2.a; 
  return 1.0 * deno / (long double) nume; 
}
bool bad(const line &l1, const line &l2, const line &l3) {
  long double x12 = intersect(l1, l2); 
  long double x13 = intersect(l1, l3); 
  if (x13 < x12) {
    return true; 
  }
  return false;                     
}
void dfs_size(int u, int father, const std::vector <std::vector <int> > &adj, std::vector <unsigned long long> &sz) {
  sz[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs_size(v, u, adj, sz);
    sz[u] += sz[v];  
  }
}
void dfs_out(int u, int father, const std::vector <std::vector <int> > &adj, std::vector <unsigned long long> &sz, std::vector <unsigned long long> &f_out) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs_out(v, u, adj, sz, f_out);
    f_out[u] += f_out[v] + sz[v];  
  }
}
void dfs_in(int u, int father, const std::vector <std::vector <int> > &adj, std::vector <unsigned long long> &sz, std::vector <unsigned long long> &f_out, std::vector <unsigned long long> &f_in) {
  int n = (int) adj.size(); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    f_in[v] = f_in[u] + f_out[u] - f_out[v] - sz[v] + n - sz[v];
    dfs_in(v, u, adj, sz, f_out, f_in);  
  }
}
void dfs_square_out(int u, int father, const std::vector <std::vector <int> > &adj, std::vector <unsigned long long> &sz, std::vector <unsigned long long> &f_out, std::vector <unsigned long long> &sq_out) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs_square_out(v, u, adj, sz, f_out, sq_out); 
    sq_out[u] += sq_out[v] + 2LL * f_out[v] + sz[v];  
  }
}
void dfs_square_in(int u, int father, const std::vector <std::vector <int> > &adj, std::vector <unsigned long long> &sz, std::vector <unsigned long long> &f_out, std::vector <unsigned long long> &sq_out, std::vector <unsigned long long> &f_in, std::vector <unsigned long long> &sq_in) {
  int n = (int) adj.size();
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    sq_in[v] = sq_in[u] + sq_out[u] - sq_out[v] - 2LL * f_out[v] - sz[v] + 2LL * (f_in[u] + f_out[u] - f_out[v] - sz[v]) + n - sz[v];
    dfs_square_in(v, u, adj, sz, f_out, sq_out, f_in, sq_in);  
  }
}
void solve(int &n, std::vector <std::vector <int> > &adj, std::vector <unsigned long long> &sz, std::vector <unsigned long long> &f_out, std::vector <unsigned long long> &f_in, std::vector <unsigned long long> &sq_in, std::vector <unsigned long long> &sq_out) {
  std::cin >> n;
  adj.resize(n);
  sz.resize(n, 0);
  f_out.resize(n, 0);
  f_in.resize(n, 0);
  sq_out.resize(n, 0);
  sq_in.resize(n, 0);
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v; 
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }  
  dfs_size(0, -1, adj, sz);
  dfs_out(0, -1, adj, sz, f_out); 
  dfs_in(0, -1, adj, sz, f_out, f_in); 
  dfs_square_out(0, -1, adj, sz, f_out, sq_out); 
  dfs_square_in(0, -1, adj, sz, f_out, sq_out, f_in, sq_in);
  long long total_square = 0LL;
  for (int u = 0; u < n; u++) {
    total_square += sq_out[u] + sq_in[u]; 
  }
  total += total_square / 2; 
}
void process(int n, int m, const std::vector <unsigned long long> &f_out, const std::vector <unsigned long long> &f_in, const std::vector <unsigned long long> &sq_out, const std::vector <unsigned long long> &sq_in) {
  std::vector <line> listLine; 
  for (int u = 0; u < n; u++) {
    listLine.push_back((line) {2LL * (f_out[u] + f_in[u]), 1LL * m * (sq_out[u] + sq_in[u]) + 2LL * m * (f_out[u] + f_in[u]), 0.000}); 
  }
  std::sort(listLine.begin(), listLine.end(), compareA); 
  for (int i = 0; i < (int) listLine.size(); i++) {
    line &l = listLine[i]; 
    if (hull.empty() == false && hull.back().a == l.a) {
      continue; 
    }
    while ((int) hull.size() >= 2 && bad(hull[(int) hull.size() - 2], hull.back(), l) == true) {
      hull.pop_back(); 
    }
    if (hull.empty() == false) {
      long double x = intersect(hull.back(), l);
      l.x = x;
    }
    hull.push_back(l);      
  }                                           
}

int main () {              
  solve(nA, adjA, szA, fA_out, fA_in, sqA_out, sqA_in);
  solve(nB, adjB, szB, fB_out, fB_in, sqB_out, sqB_in);
  process(nA, nB, fA_out, fA_in, sqA_out, sqA_in);
  total += 1LL * nA * nB;
  std::vector <line> listLine;
  for (int v = 0; v < nB; v++) {
    listLine.push_back((line) {fB_out[v] + fB_in[v], 1LL * nA * (sqB_out[v] + sqB_in[v]) + 2LL * nA * (fB_out[v] + fB_in[v])}); 
  } 
  std::sort(listLine.begin(), listLine.end(), compareB); 
  for (int i = 0; i < (int) listLine.size(); i++) {
    ans = std::min(ans, listLine[i].b + query(listLine[i].a)); 
  }   
  std::cout << ans + total; 
  return 0; 
}