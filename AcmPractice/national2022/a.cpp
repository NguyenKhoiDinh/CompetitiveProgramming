#include <iostream> 
#include <vector> 

struct question {
  char type; 
  int u, v, id; 
};
char ans[200005]; 
int n, numQuery; 
int root[200005]; 
std::vector <question> listQuestions[200005]; 

int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}

void unionSet(int u, int v) {
  int rootu = findRoot(u);
  int rootv = findRoot(v);
  if (rootu != rootv) {
    root[rootu] = rootv; 
  }
}

int main () {
  std::cin >> n >> numQuery; 
  for (int i = 1; i <= n; i++) {
    root[i] = i; 
  }
  int current_snap_shot = 1; 
  for (int query = 1; query <= numQuery; query++) {
    char type;
    std::cin >> type; 
    if (type == 'A') {
      int u, v;
      std::cin >> u >> v;
      listQuestions[current_snap_shot].push_back((question) {'A', u, v, query});   
    }
    else if (type == '?') {
      int u, v; 
      std::cin >> u >> v;
      listQuestions[current_snap_shot].push_back((question) {'?', u, v, query}); 
    }
    else if (type == 'C') {
      current_snap_shot++; 
    }
    else {
      int snap_shot;
      int u, v;
      std::cin >> snap_shot >> u >> v;
      listQuestions[snap_shot].push_back((question) {'!', u, v, query});  
    }
  }
  for (int snap_shot = 0; snap_shot <= current_snap_shot; snap_shot++) {
    std::vector <question> &a = listQuestions[snap_shot]; 
    for (int i = 0; i < (int) a.size(); i++) {
      question e = a[i]; 
      if (e.type == 'A') {
        unionSet(e.u, e.v); 
      }
      else {
        int rootu = findRoot(e.u);
        int rootv = findRoot(e.v);
        if (rootu == rootv) {
          ans[e.id] = 'Y'; 
        }
        else {
          ans[e.id] = 'N'; 
        }
      }
    }
  }
  for (int i = 1; i <= numQuery; i++) {
    if (ans[i] == 'Y' || ans[i] == 'N') {
      std::cout << ans[i]; 
    }  
  }
  return 0; 
}