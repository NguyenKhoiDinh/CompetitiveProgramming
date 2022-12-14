#include <bits/stdc++.h>

using namespace std;
int n, m, k; 
vector <string> listGen; 
string pattern; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> m >> k; 
  cin >> pattern; 
  pattern += pattern; 
  for (int i = 1; i <= k; i++) {
    string s; 
    cin >> s; 
    listGen.push_back(s); 
  }
  for (int i = 0; i < k; i++) {
    string gen = listGen[i]; 
    for (int j = 0; j < (int) pattern.size() - )
  }
  return 0; 
}