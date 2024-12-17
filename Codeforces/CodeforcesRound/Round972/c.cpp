#include <bits/stdc++.h>

using namespace std;
string s[1005]; 
int n, m;
int f[1000005][5][2];
int cost[1005];
char ch[5] = {'n', 'a', 'r', 'e', 'k'};   

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
      cost[i] = 0; 
      for (int j = 0; j < m; j++) {
        bool ok = false; 
        for (int k = 0; k < 5; k++) {
          if (s[i][j] == ch[k]) {
            ok = true; 
            break; 
          }
        }
        if (ok == true) {
          cost[i]++; 
        }
      } 
    } 
    string st = "";
    for (int i = 0; i < n; i++) {
      st += s[i]; 
    }
    int len = (int) st.size();
    for (int i = 0; i <= len; i++) {
      for (int cur = 0; cur < 5; cur++) {
        for (int state = 0; state <= 1; state++) {
          f[i][cur][state] = -1000000007; 
        }
      }   
    }
    f[0][0][0] = 0;   
    for (int i = 0; i < len; i++) {
      for (int cur = 0; cur < 5; cur++) {
        for (int state = 0; state <= 1; state++) {
          if (i % m == 0) {
            f[i + 1][cur][0] = max(f[i + 1][cur][0], f[i][cur][state]); 
          }
          else {
            f[i + 1][cur][state] = max(f[i + 1][cur][state], f[i][cur][state]);
          }
          if (ch[cur] == st[i]) {
            if (state == 0 || i % m == 0) {
              f[i + 1][(cur + 1) % 5][1] = max(f[i + 1][(cur + 1) % 5][1], f[i][cur][state] + (cur == 4 ? 10 : 0) - cost[i / m]);    
            }
            else {
              f[i + 1][(cur + 1) % 5][1] = max(f[i + 1][(cur + 1) % 5][1], f[i][cur][state] + (cur == 4 ? 10 : 0));
            }
          }
        }
      }
    }
    int ans = -1000000007; 
    for (int cur = 0; cur < 5; cur++) {
      for (int state = 0; state <= 1; state++) {
        ans = max(ans, f[len][cur][state]); 
      }
    }
    cout << ans << endl; 
  }
  return 0; 
}