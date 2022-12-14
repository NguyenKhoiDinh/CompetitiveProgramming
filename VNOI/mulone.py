numTest = int(input().strip())
for testCase in range(numTest):
  k = int(input().strip())
  res = 0
  for i in range(k):
    res = res * 10 + 1
  print(res * res)