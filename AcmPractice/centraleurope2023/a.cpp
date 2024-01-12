#include <iostream> 
#include <utility>
#include <vector> 
#include <map>   
std::vector <std::pair <int, int> > adj[100005]; 
int n, numQueries; 
int sz[100005]; 
int parent[100005]; 
bool deleted[100005]; 
std::map <int, int> dist[100005]; 
std::vector <int> fw[100005]; 
int ans[100005]; 
std::vector <std::pair <int, int> > listEdges; 

void dfs_size(int u, int father) {
  sz[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i]; 
    int v = neighbor.first; 
    if (v == father) {
      continue; 
    }
    if (deleted[v] == true) {
      continue; 
    }
    dfs_size(v, u); 
    sz[u] += sz[v]; 
  }
}

int findCentroid(int u, int father, int numbChild) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i]; 
    if (neighbor.first == father) {
      continue; 
    }
    if (deleted[neighbor.first] == true) {
      continue; 
    }
    if (2 * sz[neighbor.first] > numbChild) {
      return findCentroid(neighbor.first, u, numbChild); 
    }
  }
  return u; 
}

void dfs(int u, int centroid, int father, int distance) {
  dist[u][centroid] = distance; 
  dist[centroid][u] = distance; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i];
    if (neighbor.first == father) {
      continue;
    }
    if (deleted[neighbor.first] == true) {
      continue; 
    }
    if (distance + neighbor.second > 1000000000) {
      continue; 
    }
    dfs(neighbor.first, centroid, u, distance + neighbor.second); 
  }  
}

void build(int u, int father) {
  dfs_size(u, father);  
  int numbChildren = sz[u];
  int centroid = findCentroid(u, father, numbChildren);
  deleted[centroid] = true;  
  dfs(centroid, centroid, father, 0); 
  parent[centroid] = father; 
  std::vector <int> listVertex; 
  for (int i = 0; i < (int) adj[centroid].size(); i++) {
    std::pair <int, int> neighbor = adj[centroid][i]; 
    if (deleted[neighbor.first] == true) {
      continue; 
    }
    listVertex.push_back(neighbor.first); 
  }
  for (int i = 0; i < (int) listVertex.size(); i++) {
    int v = listVertex[i];  
    build(v, centroid);
  }
}

int main () {
  freopen("input.txt", "r", stdin); 
  freopen("output.txt", "w", stdout); 
  std::ios_base::sync_with_stdio(false); 
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, weight;
    std::cin >> u >> v >> weight;
    adj[u].push_back(std::make_pair(v, weight)); 
    adj[v].push_back(std::make_pair(u, weight));   
    listEdges.push_back(std::make_pair(u, v)); 
  }
  build(1, -1);
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    char type;
    std::cin >> type; 
    if (type == '+') {
      int u, radius; 
      std::cin >> u >> radius;
      while (true) {
        int father = parent[u]; 
        if (father == -1) {
          break; 
        }
        int distance = dist[u][father]; 
        if (distance <= radius) {
          ans[u]++; 
        }
        S[u].insert(std::make_pair(radius - distance, (int) S[u].size())); 
        u = father; 
      }  
    }
    else {
      int id;
      std::cin >> id;
      std::pair <int, int> e = listEdges[id - 1];
      int u = e.first;
      int v = e.second;
      std::cout << std::min(calc(u), calc(v)) << std::endl;          
    }
  } 
  return 0; 
}