#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 205; 
int n, s, w; 
long long m, bmin, bmax; 
string ways[MAX_N][MAX_N];

string add(string s1, string s2) {
  while ((int) s1.size() < (int) s2.size()) {
    s1 = "0" + s1; 
  }
  while ((int) s2.size() < (int) s1.size()) {
    s2 = "0" + s2; 
  }
  int len = (int) s1.size(); 
  string res; 
  res.resize(len); 
  int rem = 0; 
  for (int i = len - 1; i >= 0; i--) {
    int r = (s1[i] - '0' + s2[i] - '0' + rem) % 10;
    rem = (s1[i] - '0' + s2[i] - '0' + rem) / 10;
    res[i] = (char) (r + '0');  
  }
  if (rem == 1) {
    res = "1" + res; 
  }
  return res;
}

void init() {
  cout << "Ngu" << endl;
  for (int i = 0; i < MAX_N; i++) {
    for (int j = 0; j < MAX_N; j++) {
      ways[i][j] = "0";
    }
  }
  ways[1][0] = "1"; 
  for (int i = 1; i < MAX_N - 1; i++) {
    for (int j = 0; j <= i; j++) {
      if (ways[i][j] == "0") {
        continue; 
      }
      ways[i + 1][j] = add(ways[i + 1][j], ways[i][j]);
      for (int step = 1; step <= i; step++) {
        ways[i + 1][j + 1] = add(ways[i + 1][j + 1], ways[i][j]);
      }
    }
  }
  cout << ways[5][2];
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  init();
  return 0; 
}