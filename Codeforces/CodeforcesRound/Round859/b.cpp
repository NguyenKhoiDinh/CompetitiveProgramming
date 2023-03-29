#include <iostream> 

using namespace std;
int numTest; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int mihai = 0, bianca = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x % 2 == 0) {
        mihai += x; 
      }
      else {
        bianca += x; 
      }
    } 
    if (mihai > bianca) {
      cout << "YES";
    }
    else {
      cout << "NO"; 
    }
    cout << endl;
  }
  return 0;   
}