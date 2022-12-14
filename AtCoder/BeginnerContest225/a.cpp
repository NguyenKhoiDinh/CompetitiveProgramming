#include <bits/stdc++.h> 

using namespace std;
set <string> S; 
string s; 

int main () {
  cin >> s;
  sort(s.begin(), s.end());
  do {
    S.insert(s); 
  }
  while (next_permutation(s.begin(), s.end())); 
  cout << (int) S.size();
  return 0; 
}