#include <iostream> 
#include <string> 

using namespace std;
int numTest; 
int mark[26]; 
int n; 
string s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int c = 0; c < 26; c++) {
      mark[c] = -1; 
    } 
    cin >> n;
    cin >> s;
    int bit = 0; 
    bool found = true; 
    for (int i = 0; i < n; i++) {
      if (mark[s[i] - 'a'] == -1 || mark[s[i] - 'a'] == bit) {
        mark[s[i] - 'a'] = bit; 
      }  
      else {
        found = false;
        break;   
      }
      bit = !bit; 
    }
    cout << (found == true ? "YES" : "NO") << endl;
  }
  return 0;   
}