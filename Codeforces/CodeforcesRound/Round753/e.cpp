#include <bits/stdc++.h> 

using namespace std;
int numTest;
int n, m; 
string command; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int x0 = 0;
    int y0 = 0; 
    cin >> n >> m;
    vector <pair <int, char> > save; 
    int minLeft = 0;
    int maxRight = 0;
    int maxDown = 0;
    int minUp = 0;
    int stepLeft = 0;
    int stepRight = 0;
    int stepUp = 0;
    int stepDown = 0;
    cin >> command; 
    for (int i = 0; i < (int) command.size(); i++) {
      if (command[i] == 'L') {
        y0--; 
        if (minLeft > y0) {
          minLeft = y0;
          stepLeft = i + 1; 
        }
      }
      else if (command[i] == 'R') {
        y0++;
        if (maxRight < y0) {
          maxRight = y0;
          stepRight = i + 1; 
        }
      }
      else if (command[i] == 'U') {
        x0--;
        if (minUp > x0) {
          minUp = x0; 
          stepUp = i + 1; 
        }
      }
      else {
        x0++;
        if (maxDown < x0) {
          maxDown = x0;
          stepDown = i + 1; 
        }
      }
    }
    save.push_back(make_pair(stepLeft, 'L'));
    save.push_back(make_pair(stepRight, 'R'));
    save.push_back(make_pair(stepUp, 'U'));
    save.push_back(make_pair(stepDown, 'D'));
    sort(save.begin(), save.end()); 
    x0 = 1, y0 = 1; 
    int limLeft = 1, limRight = m, limUp = 1, limDown = n; 
    for (int i = 0; i < 4; i++) {
      if (save[i].second == 'L') {
        limLeft -= minLeft;
        if (limLeft > limRight) {
          break; 
        }
        y0 = limLeft;    
      }
      else if (save[i].second == 'R') {
        limRight -= maxRight;
        if (limRight < limLeft) {
          break;
        }
        y0 = limRight; 
      }
      else if (save[i].second == 'U') {
        limUp -= minUp; 
        if (limUp > limDown) {
          break;
        }
        x0 = limUp;
      }
      else {
        limDown -= maxDown;
        if (limDown < limUp) {
          break;
        }
        x0 = limDown; 
      }
    }
    cout << x0 << ' ' << y0 << endl; 
  }
  return 0; 
}