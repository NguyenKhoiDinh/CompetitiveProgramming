import queue

MAX_N = 100005
inf = 1000000007

adj = [[] for _ in range(MAX_N)]
dist = [inf for _ in range(MAX_N)]

class Node:
  def __init__(self, vertex, w):
    self.vertex = vertex
    self.w = w

  def __lt__(self, other):
    return self.w < other.w

def Dijkstra(start):
  pq = queue.PriorityQueue()
  pq.put(Node(start, 0))
  while pq.qsize() > 0:
    tmp = pq.get()
    u = tmp.vertex
    w = tmp.w
    if w > dist[u]:
      continue
    for i in range(len(adj[u])):
      v = adj[u][i].vertex
      if dist[v] > dist[u] + adj[u][i].w:
        dist[v] = dist[u] + adj[u][i].w
        pq.put(Node(v, dist[v]))

V, E = map(int, input().strip().split())
for e in range(E):
  u, v, w = map(int, input().strip().split())
  adj[u].put(Node(v, w))
  adj[v].put(Node(u, w))
start, end = map(int, input().strip().split())
Dijkstra(start)
print(dist[end])