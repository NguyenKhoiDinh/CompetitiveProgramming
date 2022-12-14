#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
int numChar[26];
string s;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> s;
  for (int i = 0; i < (int) s.size(); i++) {
    numChar[s[i] - 'a']++;
  }
  vector <int> save;
  for (int c = 0; c < 26; c++) {
    if (numChar[c] > 0) {
      save.push_back(numChar[c]);
    }
  }
  sort(save.begin(), save.end());
  if ((int) save.size() <= 2) {
    cout << 0;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < (int) save.size() - 2; i++) {
    ans += save[i];
  }
  cout << ans;
  return 0;
}