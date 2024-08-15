#include <bits/stdc++.h>

using namespace std;
int numTest; 
int n, k, pb, ps; 
int p[200005], a[200005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k >> pb >> ps;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    long long finalb = 0LL; 
    long long finals = 0LL;
    int tmpb = pb;
    int maxb = 0; 
    for (int i = 1; i <= n; i++) {
      maxb = max(maxb, a[tmpb]); 
      if (i == k) {
        break;
      }
      tmpb = p[tmpb]; 
    }
    int tmps = ps;
    int maxs = 0;
    for (int i = 1; i <= n; i++) {
      maxs = max(maxs, a[tmps]); 
      if (i == k) {
        break; 
      }
      tmps = p[tmps];
    } 
    int stepb = 0; 
    long long sumb = 0LL; 
    while (true) {
      stepb++;
      sumb += a[pb]; 
      finalb = max(finalb, sumb + (long long) (k - stepb) * a[pb]);
      if (stepb == k || stepb == n + 1) {
        break; 
      }  
      pb = p[pb]; 
    }
    int steps = 0;
    long long sums = 0LL; 
    while (true) {
      steps++;
      sums += a[ps]; 
      finals = max(finals, sums + (long long) (k - steps) * a[ps]); 
      if (steps == k || steps == n + 1) {
        break; 
      }
      ps = p[ps]; 
    }
    if (finalb > finals) {
      cout << "Bodya";
    }
    else if (finalb == finals) {
      cout << "Draw"; 
    }
    else {
      cout << "Sasha";
    }
    cout << endl; 
  }
  return 0; 
}