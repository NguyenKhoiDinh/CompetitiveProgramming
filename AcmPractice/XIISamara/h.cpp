#include <bits/stdc++.h> 

using namespace std;
vector <int> numb, id;
int n; 

int ask(int bit, int pos) {
  cout << "? " << pos << ' ' << bit << endl;
  fflush(stdout);
  int ret;
  cin >> ret;
  return ret;
}

int dfs(int pos, vector <int> &numb, vector <int> &id) {
  if ((int) numb.size() == 1) {
    return numb[0];
  }
  vector <int> numb1, numb0, id1, id0;
  for (int i = 0; i < (int) numb.size(); i++) {
    if ((numb[i] & (1 << pos)) > 0) {
      numb1.push_back(numb[i]);
    }
    else {
      numb0.push_back(numb[i]);
    }
  }
  for (int i = 0; i < (int) id.size(); i++) {
    int bit = ask(pos, id[i]);
    if (bit == 1) {
      id1.push_back(id[i]);
    }
    else {
      id0.push_back(id[i]);
    }
  }
  if ((int) id1.size() < (int) numb1.size()) {
    return dfs(pos + 1, numb1, id1);
  }
  else {
    return dfs(pos + 1, numb0, id0);
  }
}

int main () {
  cin >> n;
  int maxBit = -1;
  for (int i = 0; i < 15; i++) {
    if ((n & (1 << i)) > 0) {
      maxBit = i;
    }
  }
  for (int i = 0; i <= n; i++) {
    numb.push_back(i);
    if (i > 0) {
      id.push_back(i);
    }
  }
  int ans = dfs(0, numb, id);
  cout << "! " << ans << endl;
  fflush(stdout);
  return 0; 
}