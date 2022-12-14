#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 63; 
struct element {
  int r, p, s; 
};
int numTest; 
double X, E, W;
double dp[MAX_N][MAX_N][MAX_N];
element trace[MAX_N][MAX_N][MAX_N]; 

string track(int r, int p, int s) {
  string res = ""; 
  while (r > 0 || p > 0 || s > 0) {
    int prevr = trace[r][p][s].r;
    int prevp = trace[r][p][s].p; 
    int prevs = trace[r][p][s].s;
    if (prevr + 1 == r) {
      res += 'R'; 
    } 
    else if (prevp + 1 == p) {
      res += 'P'; 
    }
    else {
      res += 'S'; 
    }
    r = prevr; 
    p = prevp;
    s = prevs;
  }
  reverse(res.begin(), res.end()); 
  return res;
}

int main () {
  //freopen("input.txt", "r", stdin);
  cin >> numTest;
  cin >> X; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> W >> E; 
    for (int r = 0; r < MAX_N; r++) {
      for (int s = 0; s < MAX_N; s++) {
        for (int p = 0; p < MAX_N; p++) {
          dp[r][s][p] = -1.0;
          trace[r][p][s] = (element) {-1, -1, -1}; 
        }
      }
    }
    dp[1][0][0] = dp[0][1][0] = dp[0][0][1] = (E + W) / 3.0;
    trace[1][0][0] = trace[0][1][0] = trace[0][0][1] = (element) {0, 0, 0};
    for (int r = 0; r <= 60; r++) {
      for (int p = 0; p <= 60; p++) {
        for (int s = 0; s <= 60; s++) {
          if (dp[r][p][s] == -1.0) {
            continue; 
          }
          int total = r + p + s; 
          double value = W * 1.0 * p / total + E * 1.0 * s / total; 
          if (dp[r + 1][p][s] < dp[r][p][s] + value) {
            dp[r + 1][p][s] = dp[r][p][s] + value; 
            trace[r + 1][p][s] = (element) {r, p, s}; 
          }
          value = W * 1.0 * s / total + E * 1.0 * r / total;
          if (dp[r][p + 1][s] < dp[r][p][s] + value) {
            dp[r][p + 1][s] = dp[r][p][s] + value; 
            trace[r][p + 1][s] = (element) {r, p, s}; 
          }
          value = W * 1.0 * r / total + E * 1.0 * p / total;
          if (dp[r][p][s + 1] < dp[r][p][s] + value) {
            dp[r][p][s + 1] = dp[r][p][s] + value;
            trace[r][p][s + 1] = (element) {r, p, s}; 
          }
        }
      }
    }
    bool found = false; 
    string res = "";
    int resr, resp, ress;
    double maxi = -1.0;  
    for (int r = 0; r <= 60; r++) {
      if (found == true) {
        break; 
      }
      for (int p = 0; p <= 60; p++) {
        if (found == true) {
          break; 
        }
        for (int s = 0; s <= 60; s++) {
          if (maxi < dp[r][p][s] && (r + p + s == 60)) {
            resr = r; 
            resp = p; 
            ress = s;
            maxi = dp[r][p][s];
            break; 
          }
        }
      }
    }
    res = track(resr, resp, ress);
    cout << res << endl; 
  }
  return 0;
}