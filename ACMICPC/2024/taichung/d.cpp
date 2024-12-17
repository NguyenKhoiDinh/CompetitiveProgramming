#include <iostream> 
#include <queue> 
#include <string>
#include <vector> 
#include <tuple> 
#include <utility> 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::vector <std::string> a;
int n, m;
std::queue <std::tuple <int, int, int, int> > myqueue;
std::vector <std::vector <int> > dist[4][4];  
std::pair <int, int> start, end; 

int main () {
  std::cin >> n >> m;
  a.resize(n); 
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        start = std::make_pair(i, j); 
      }   
      else if (a[i][j] == 'T') {
        end = std::make_pair(i, j); 
      }
    }
  }
  for (int direction = 0; direction < 4; direction++) {
    for (int consect = 0; consect < 4; consect++) {
      dist[direction][consect].resize(n); 
      for (int i = 0; i < n; i++) {
        dist[direction][consect][i].resize(m, -1); 
      }
    }
  }
  dist[0][0][start.first][start.second] = 0; 
  myqueue.push(std::make_tuple(start.first, start.second, 0, 0)); 
  while (myqueue.empty() == false) {
    std::tuple <int, int, int, int> element = myqueue.front();
    myqueue.pop(); 
    int x = std::get<0>(element); 
    int y = std::get<1>(element); 
    int direction = std::get<2>(element); 
    int consect = std::get<3>(element);
    if (x == end.first && y == end.second) {
      std::cout << dist[direction][consect][x][y];
      return 0; 
    }
    for (int i = 0; i < 4; i++) {
      int nxtx = x + dx[i];
      int nxty = y + dy[i];
      if (nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < m && a[nxtx][nxty] != '#') {
        if (i != direction) {
          if (dist[i][1][nxtx][nxty] == -1) {
            dist[i][1][nxtx][nxty] = dist[direction][consect][x][y] + 1;
            myqueue.push(std::make_tuple(nxtx, nxty, i, 1));  
          }
        }
        else if (consect + 1 <= 3) {
          if (dist[i][consect + 1][nxtx][nxty] == -1) {
            dist[i][consect + 1][nxtx][nxty] = dist[direction][consect][x][y] + 1;
            myqueue.push(std::make_tuple(nxtx, nxty, i, consect + 1)); 
          }  
        }
      } 
    } 
  }
  std::cout << -1; 
  return 0; 
}