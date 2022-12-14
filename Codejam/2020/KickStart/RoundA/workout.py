numTest = int(input().strip())
for testCase in range(1, numTest + 1):
  print("Case #", end = '')
  print(testCase, end = '')
  print(": ", end = '')
  n, k = map(int, input().strip().split())
  a = list(map(int, input().strip().split()))
  l = 1
  r = 1000000007
  ans = -1
  while l <= r:
    mid = (l + r) // 2
    numbAdd = 0
    for i in range(0, n - 1):
      diff = a[i + 1] - a[i]
      numbAdd += diff // mid
      if diff % mid == 0:
        numbAdd -= 1
    if numbAdd <= k:
      ans = mid
      r = mid - 1
    else:
      l = mid + 1
  print(ans)