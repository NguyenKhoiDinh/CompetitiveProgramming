#include <iostream> 
#include <string> 
#include <utility>
#include <math.h>

using namespace std;
int numTest; 
string direction[4] = {"DL", "UL", "UR", "DR"}; 
int n, m;
int startx, starty, endx, endy; 
string currentDir;

int nextDir(int x, int y, int pos) {
  if (x == 1 && y == 1) {
    return 3; 
  }   
  if (x == 1 && y == m) {
    return 0; 
  }
  if (x == n && y == 1) {
    return 2; 
  }
  if (x == n && y == m) {
    return 1; 
  }
  if (x == 1) {
    if (pos == 2) {
      return 3; 
    }
    else {
      return 0; 
    }
  }
  if (x == n) {
    if (pos == 3) {
      return 2; 
    }
    else {
      return 1; 
    }
  }
  if (y == 1) {
    if (pos == 0) {
      return 3; 
    }
    else {
      return 2; 
    }
  }
  if (y == m) {
    if (pos == 3) {
      return 0; 
    }
    else {
      return 1; 
    }
  }
}

pair <int, int> nextPos(int x, int y, int pos) {
  if (pos == 0) {
    int len = min(n - x, y - 1); 
    return make_pair(x + len, y - len); 
  }
  else if (pos == 1) {
    int len = min(x - 1, y - 1); 
    return make_pair(x - len, y - len); 
  }
  else if (pos == 2) {
    int len = min(x - 1, m - y); 
    return make_pair(x - len, y + len); 
  }
  else {
    int len = min(n - x, m - y); 
    return make_pair(x + len, y + len); 
  }
}

bool checkStart(int x, int y, int pos) {
  if (x == 1 && y == 1 && pos == 1) {
    return true; 
  }
  if (x == 1 && y == m && pos == 2) {
    return true; 
  }
  if (x == n && y == 1 && pos == 0) {
    return true; 
  }
  if (x == n && y == m && pos == 3) {
    return true; 
  }
  return false; 
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m >> startx >> starty >> endx >> endy >> currentDir;
    int curx = startx;
    int cury = starty;
    int step = 0; 
    for (int i = 0; i < 4; i++) {
      if (currentDir == direction[i]) {
        step = i; 
      }
    }
    int ans = -1; 
    int numb = 0;
    if (checkStart(curx, cury, step) == true) {
      numb++; 
      step = nextDir(curx, cury, step); 
      pair <int, int> nextPosition = nextPos(curx, cury, step); 
      curx = nextPosition.first;
      cury = nextPosition.second; 
    } 
    do {
      if (abs(endx - curx) == abs(endy - cury)) {
        ans = numb; 
        break; 
      }    
      pair <int, int> nextPosition = nextPos(curx, cury, step); 
      curx = nextPosition.first;
      cury = nextPosition.second; 
      step = nextDir(curx, cury, step); 
      numb++; 
    }
    while (curx != startx || cury != starty);  
    cout << ans << endl; 
  }
  return 0;   
}