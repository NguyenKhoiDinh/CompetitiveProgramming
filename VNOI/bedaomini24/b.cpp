#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
int n, k; 
pair <long long, long long> prefix[100005], suffix[100005];
string dir;  
long long startx, starty, endx, endy; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k; 
    cin >> startx >> starty >> endx >> endy;
    cin >> dir; 
    prefix[0].first = startx;
    prefix[0].second = starty; 
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i - 1]; 
      if (dir[i - 1] == 'L') {
        prefix[i].first--; 
      }
      else if (dir[i - 1] == 'R') {
        prefix[i].first++; 
      }
      else if (dir[i - 1] == 'U') {
        prefix[i].second--; 
      }
      else if (dir[i - 1] == 'D') {
        prefix[i].second++; 
      }
    }
    suffix[n + 1].first = endx;
    suffix[n + 1].second = endy; 
    for (int i = n; i >= 1; i--) {
      suffix[i] = suffix[i + 1];
      if (dir[i - 1] == 'L') {
        suffix[i].first++; 
      } 
      else if (dir[i - 1] == 'R') {
        suffix[i].first--; 
      }
      else if (dir[i - 1] == 'U') {
        suffix[i].second++; 
      }
      else if (dir[i - 1] == 'D') {
        suffix[i].second--; 
      }
    }
    bool check = false;
    for (int i = k + 1; i <= n + 1; i++) {
      long long sumx = suffix[i].first - prefix[i - k - 1].first;
      long long sumy = suffix[i].second - prefix[i - k - 1].second;
      if (abs(sumx) + abs(sumy) <= k) {
        check = true;
        break;  
      } 
    }
    cout << (check == true ? "YES" : "NO") << endl;
  }
  return 0; 
}