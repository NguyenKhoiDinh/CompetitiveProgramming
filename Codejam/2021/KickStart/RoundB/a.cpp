#include <iostream>
#include <fstream>

using namespace std;
int numTest; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    string s;
    int n;
    cin >> n; 
    cin >> s; 
    int d = 1; 
    cout << d << ' '; 
    for (int i = 1; i < n; i++) {
      if (s[i] > s[i - 1]) {
        d++; 
      }
      else {
        d = 1; 
      }
      cout << d << ' ';
    }
    cout << endl;
  }
  return 0;
}