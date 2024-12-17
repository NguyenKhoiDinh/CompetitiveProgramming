#include <iostream>
#include <string> 
#include <vector>

const int mod = 1000000007; 
std::string s; 
int n; 
int f[2][1000005]; 
std::vector <int> listValue; 
std::vector <int> listPos[2]; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  std::cin >> n; 
  std::cin >> s;
  int freeOpen = 0; 
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '?') {
      if (i > 0 && s[i - 1] != '?') {
        listValue.push_back(freeOpen); 
      }
      listValue.push_back(-1000000007);
      freeOpen = 0; 
    }
    else if (s[i] == '(') {
      freeOpen++; 
    }
    else {
      freeOpen--; 
    }
  }
  if (s.back() != '?') {
    listValue.push_back(freeOpen); 
  } 
  f[0][0] = 1;
  listPos[0].push_back(0); 
  int sz = (int) listValue.size(); 
  for (int i = 0; i < sz; i++) {
    int now = i % 2;
    int nxt = !now;
    for (int j = 0; j < (int) listPos[nxt].size(); j++) {
      f[nxt][listPos[nxt][j]] = 0; 
    } 
    listPos[nxt].clear();
    for (int j = 0; j < (int) listPos[now].size(); j++) {
      int freeOpen = listPos[now][j];
      if (listValue[i] == -1000000007) {
        if (f[nxt][freeOpen + 1] == 0) {
          listPos[nxt].push_back(freeOpen + 1);
        }
        if (freeOpen > 0 && f[nxt][freeOpen - 1] == 0) {
          listPos[nxt].push_back(freeOpen - 1); 
        }
        (f[nxt][freeOpen + 1] += f[now][freeOpen]) %= mod; 
        if (freeOpen > 0) {
          (f[nxt][freeOpen - 1] += f[now][freeOpen]) %= mod; 
        }
      }                                              
      else {
        if (freeOpen + listValue[i] >= 0 && f[nxt][freeOpen + listValue[i]] == 0) {
          listPos[nxt].push_back(freeOpen + listValue[i]); 
        }
        if (freeOpen + listValue[i] >= 0) {
          (f[nxt][freeOpen + listValue[i]] += f[now][freeOpen]) %= mod; 
        }
      }                       
    }     
  }
  std::cout << f[sz % 2][0]; 
  return 0; 
}                 