#include <bits/stdc++.h> 

using namespace std;
struct pacman {
  int x, y, direction; 
};
pacman p[10005];
int n, P, numQueries; 
pair <int, int> coordinates[4]; 

int main () {
  cin >> n >> P >> numQueries;
  for (int i = 1; i <= P; i++) {
    cin >> p[i].x >> p[i].y >> p[i].direction;
    p[i].direction--; 
  }
  int changex = -1, changey = -1;
  int changeDirection = 0;
  int sumDirection = 0; 
  for (int query = 1; query <= numQueries; query++) {
    char type;
    cin >> type; 
    if (type == 'A') {
      int numbSteps;
      cin >> numbSteps;
      coordinates[0].first -= (numbSteps % n); 
      (coordinates[0].first += n) %= n;
      (coordinates[2].first += (numbSteps % n)) %= n;
      (coordinates[1].second += (numbSteps % n)) %= n;
      coordinates[3].second -= (numbSteps % n);
      (coordinates[3].second += n) %= n;    
    }
    else if (type == 'R') {
      int nextK;
      cin >> nextK;
      sumDirection += nextK; 
      sumDirection %= 4; 
      pair <int, int> nextCoordinates[4]; 
      for (int direction = 0; direction < 4; direction++) {
        nextCoordinates[(direction + nextK) % 4] = coordinates[direction];  
      }
      for (int direction = 0; direction < 4; direction++) {
        coordinates[direction] = nextCoordinates[direction]; 
      }
    }
    else {
      int K;
      cin >> K;  
      changex = K / n;
      changey = K % n; 
      for (int direction = 0; direction < 4; direction++) {
        coordinates[direction] = make_pair(0, 0); 
      }
    }
  }
  for (int i = 1; i <= P; i++) {
    if (changex != -1 && changey != -1) {
      p[i].x = changex;
      p[i].y = changey; 
    }
    (p[i].direction += sumDirection) %= 4;
    cout << (p[i].x + coordinates[p[i].direction].first) % n << ' ' << (p[i].y + coordinates[p[i].direction].second) % n << endl;  
  }  
  return 0; 
}