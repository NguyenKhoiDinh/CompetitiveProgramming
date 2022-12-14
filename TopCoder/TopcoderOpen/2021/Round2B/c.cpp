#include <bits/stdc++.h> 

using namespace std;

string convertToString(int x) {
  string res = "";
  while (x > 0) {
    int r = x % 10;
    x /= 10;
    res += (char) (r + '0');
  }
  reverse(res.begin(), res.end());
  return res;
}

class IncorrectCancellation  {
  public:
  int find(int D) {
    string s = convertToString(D);
    int sz = (int) s.size();
    for (int mask = 1; mask < (1 << sz) - 1; mask++) {
      int pos = -1;
      for (int i = 0; i < sz; i++) {
        if ((mask & (1 << i)) > 0) {
          pos = i;
          break;
        }
      }
      if (s[pos] == '0') {
        continue;
      }
      int newNume = 0;
      for (int i = 0; i < sz; i++) {
        if ((mask & (1 << i)) == 0) {
          newNume = newNume * 10 + s[i] - '0';
        }
      }
      if (D % newNume) {
        continue;
      }
      vector <int> cnt(10, 0);
      for (int i = 0; i < sz; i++) {
        if ((mask & (1 << i)) > 0) {
          cnt[s[i] - '0']++;
        }
      }
      int mul = D / newNume;
      for (int newDeno = 1; newDeno < newNume; newDeno++) {
        int deno = newDeno * mul;
        string st = convertToString(newDeno);
        vector <int> cntNewDeno(10, 0);
        for (int i = 0; i < (int) st.size(); i++) {
          cntNewDeno[st[i] - '0']++;
        }
        st = convertToString(deno);
        vector <int> cntDeno(10, 0);
        for (int i = 0; i < (int) st.size(); i++) {
          cntDeno[st[i] - '0']++;
        }
        bool flag = true;
        for (int d = 0; d <= 9; d++) {
          if (cntNewDeno[d] + cnt[d] != cntDeno[d]) {
            flag = false;
            break;
          }
        }
        if (flag == true) {
          return deno;
        }
      }
    }
    return -1;
  }
};

IncorrectCancellation I;

int main () {
  cout << I.find(64);
  return 0; 
}
