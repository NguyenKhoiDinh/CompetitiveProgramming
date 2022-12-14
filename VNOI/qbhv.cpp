#include <bits/stdc++.h>

using namespace std;
string s; 
vector <string> save; 

int main () {
  cin >> s; 
  sort(s.begin(), s.end());
  do {
    save.push_back(s);
  }
  while (next_permutation(s.begin(), s.end()));
  cout << (int) save.size() << endl;
  for (int i = 0; i < (int) save.size(); i++) {
    cout << save[i] << endl;
  }
  return 0; 
}