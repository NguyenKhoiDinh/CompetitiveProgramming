#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 27; 
bool mark[MAX_N][2]; 
bool markPancake[MÃX_N];

bool check(int N) {
  for (int i = 0; i < N; i++) {
    if (mark[i][0] == false || mark[i][1] == false) {
      return false; 
    }
  }
  return true; 
}

class Pancakes {
  public:
  vector <string> makePancakes(int N, int P) {
    vector <string> ans; 
    while (check(N) == false) {
      string s = ""; 
      for (int c = 0; c < 26; c++) {
        markPancake[c] = false; 
      }
      for (int i = 0; i < P; i++) {
        bool flag = false; 
        for (int i = 0; i < N; i++) {
          if (markPancake[i] == false && mark[i][0] == false) {
            s += (char) (i + 'A'); 
            mark[i][0] = true;
            flag = true;  
            markPancake[i] = true; 
            break; 
          }
        }
        if (flag == false) {
          for (int i = 0; i < N; i++) {
            if (markPancake[i] == false && mark[i][1] == false) {
              s += (char) (i + 'a'); 
              mark[i][1] = true; 
              markPancake[i] = true; 
              flag = true; 
              break; 
            }
          }
        }
        if (flag == false) {
          s += '-'; 
        }
      }
      ans.push_back(s);
    }
    return ans;
  }
};

int main () {
  return 0; 
}