#include <iostream>
#include <utility> 
#include <vector>
int n; 
struct element {
  int l, r, id;  
};
std::vector <element> listElement; 
std::vector <std::pair <int, int> > listSegment; 
std::vector <int> ask[100005];  
int queryAsk[100005]; 
void process(int index, int L, int R, bool save) {
  if (save == true) {
    ask[index].push_back(index); 
  }
  else {
    ask[index].push_back(index / 2); 
    ask[index].push_back(index - 1); 
  }
  listElement.push_back((element) {L, R, index}); 
  if (L >= R) {
    return;
  }
  int mid = (L + R) / 2; 
  process(2 * index, L, mid, true); 
  process(2 * index + 1, mid + 1, R, false); 
}
std::vector <int> rows, cols; 

void solve(int index, int L, int R, int l, int r, std::vector <int> &a) {
  if (L > r || l > R) {
    return; 
  }
  if (l <= L && R <= r) {                                                        
    a.push_back(index); 
    return; 
  }
  int mid = (L + R) / 2;
  solve(2 * index, L, mid, l, r, a);
  solve(2 * index + 1, mid + 1, R, l, r, a);
}

long long get(int id1, int id2) {
  std::cout << "? " << id1 << ' ' << id2 << std::endl; 
  long long value;
  std::cin >> value;
  return value; 
}

int main () {
  std::cin >> n; 
  process(1, 1, n, true);
  for (int i = 0; i < (int) listElement.size(); i++) {
    element e = listElement[i];
    if ((int) ask[e.id].size() == 1) {
      listSegment.push_back(std::make_pair(e.l, e.r));
      queryAsk[e.id] = (int) listSegment.size();  
    }    
  }
  std::cout << (int) listSegment.size() << std::endl;
  for (int i = 0; i < (int) listSegment.size(); i++) {
    std::cout << listSegment[i].first << ' ' << listSegment[i].second << std::endl; 
  } 
  int numQueries;
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    int X1, Y1, X2, Y2;
    std::cin >> X1 >> Y1 >> X2 >> Y2;
    rows.clear();
    cols.clear();
    solve(1, 1, n, X1, X2, rows);
    solve(1, 1, n, Y1, Y2, cols);
    long long sum = 0LL; 
    for (int i = 0; i < (int) rows.size(); i++) {
      for (int j = 0; j < (int) cols.size(); j++) {
        std::vector <int> qRows = ask[rows[i]]; 
        std::vector <int> qCols = ask[cols[j]];
        if (((int) qRows.size() * (int) qCols.size()) == 1) {
          sum += get(queryAsk[qRows[0]], queryAsk[qCols[0]]);     
        }
        else if (((int) qRows.size() * (int) qCols.size()) == 2) {
          sum += get(queryAsk[qRows[0]], queryAsk[qCols[0]]);
          if ((int) qRows.size() == 2) {
            sum -= get(queryAsk[qRows[1]], queryAsk[qCols[0]]);
          }    
          else {
            sum -= get(queryAsk[qRows[0]], queryAsk[qCols[1]]);
          }
        }
        else {
          sum += get(queryAsk[qRows[0]], queryAsk[qCols[0]]);
          sum -= get(queryAsk[qRows[1]], queryAsk[qCols[0]]);
          sum -= get(queryAsk[qRows[0]], queryAsk[qCols[1]]);
          sum += get(queryAsk[qRows[1]], queryAsk[qCols[1]]);   
        } 
      }
    }
    std::cout << "! " << sum << std::endl;    
  } 
  return 0; 
}