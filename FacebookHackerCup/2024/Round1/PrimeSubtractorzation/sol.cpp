#include <bits/stdc++.h> 

using namespace std; 
const int lim = 10000000; 
bool isPrime[lim + 5];
vector <int> listPrimes;
int smallestN[lim + 5];  
void erathonesSieve() {
  for (int i = 2; i <= lim; i++) {
    isPrime[i] = true; 
  }  
  for (int i = 2; i * i <= lim; i++) {
    if (isPrime[i] == true) {
      for (int j = i * i; j <= lim; j += i) {
        isPrime[j] = false; 
      }
    }
  }
  for (int i = 2; i <= lim; i++) {
    if (isPrime[i] == true) {
      listPrimes.push_back(i); 
    }
  }
  smallestN[5] = 1;
  for (int i = 1; i < (int) listPrimes.size(); i++) {
    int p = 2 + listPrimes[i];
    if (isPrime[p] == true) {
      smallestN[p]++; 
    } 
  } 
  for (int i = 1; i <= lim; i++) {
    smallestN[i] += smallestN[i - 1]; 
  }
} 

int main () {
  erathonesSieve(); 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    int N;
    cin >> N;
    cout << smallestN[N] << endl; 
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}