#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
std::vector <std::string> a; 
int n; 
std::vector <int> score;
std::vector <std::vector <int> > adj; 
std::vector <bool> canWin;
int power3[12]; 

std::vector <int> convert(int mask, int sz) {
  std::vector <int> ret; 
  while (mask > 0) {
    ret.push_back(mask % 3);
    mask /= 3; 
  }
  while ((int) ret.size() < sz) {
    ret.push_back(0); 
  }
  std::reverse(ret.begin(), ret.end());
  return ret; 
}

void solve() {
  int maxWin = -1;
  int x = -1;
  for (int i = 0; i < n; i++) {
    if (maxWin < score[i]) {
      maxWin = score[i];
      x = i; 
    }
  }
  for (int i = 0; i < n; i++) {
    if (score[i] == maxWin && i != x) {
      return; 
    }
  }
  canWin[x] = true; 
}

void backTrack(int u) {
  int sz = (int) adj[u].size(); 
  for (int mask = 0; mask < power3[sz]; mask++) {
    std::vector <int> listBit = convert(mask, sz);
    for (int i = 0; i < sz; i++) {
      int v = adj[u][i];
      if (listBit[i] == 0) {
        score[v] += 2; 
      }
      else if (listBit[i] == 1) {
        score[u]++;
        score[v]++;
      }
      else {
        score[u] += 2;
      }
    }
    if (u == n - 1) {
      solve();   
    }
    else {
      backTrack(u + 1); 
    }
    for (int i = 0; i < sz; i++) {
      int v = adj[u][i];
      if (listBit[i] == 0) {
        score[v] -= 2; 
      }
      else if (listBit[i] == 1) {
        score[u]--;
        score[v]--;
      }
      else {
        score[u] -= 2;
      }
    } 
  }
}

int main () {
  freopen("chess.inp", "r", stdin);
  freopen("chess.out", "w", stdout);
  std::cin >> n;
  a.resize(n);
  adj.resize(n); 
  canWin.resize(n, false);
  power3[0] = 1;
  for (int i = 1; i <= 10; i++) {
    power3[i] = power3[i - 1] * 3; 
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  }
  score.resize(n, 0); 
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i][j] == 'd') {
        score[i]++;
        score[j]++; 
      }
      else if (a[i][j] == '1') {
        score[i] += 2; 
      }
      else if (a[i][j] == '0') {
        score[j] += 2; 
      }
      else if (a[i][j] == '.') {
        adj[i].push_back(j);   
      }
    }
  }
  backTrack(0); 
  for (int i = 0; i < n; i++) {
    if (canWin[i] == true) {
      std::cout << i + 1 << ' '; 
    }
  }
  return 0; 
}