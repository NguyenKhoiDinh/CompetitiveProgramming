#include <bits/stdc++.h> 

using namespace std; 
int numTest; 
bool visited[205][205]; 
string a[205]; 
int R, C; 
char direction[4] = {'E', 'S', 'W', 'N'}; 
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0}; 
vector <char> ans;

void dfs(int x, int y, int dir) {
  visited[x][y] = true;
  for (int i = 0; i < 3; i++) {
    int nextDir = (dir + i + 3) % 4;   
    int nextx = x + dx[nextDir]; 
    int nexty = y + dy[nextDir]; 
    if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C || visited[nextx][nexty] == true || a[nextx][nexty] == '#') {
      ans.push_back(direction[(nextDir + 1) % 4]); 
    }
    else {
      ans.push_back(direction[nextDir]); 
      dfs(nextx, nexty, nextDir); 
      ans.push_back(direction[(nextDir + 2) % 4]); 
    }
  }                              
}
    
int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
      cin >> a[i]; 
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        visited[i][j] = false; 
      }
    }
    ans.clear(); 
    dfs(0, 0, 0);       
    bool correct = true; 
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (a[i][j] == '*' && visited[i][j] == false) {
          correct = false; 
        }  
      }
    }
    if (correct == false) {
      cout << "IMPOSSIBLE" << endl; 
    }
    else {
      for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i]; 
      }
      cout << 'N';
      cout << endl; 
    }
  }
  return 0; 
}