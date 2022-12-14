f = [0 for _ in range(205)]
f[0] = 1
f[1] = 1
for i in range(2, 205):
  f[i] = f[i - 1] + f[i - 2]

numTest = int(input().strip())
for testCase in range(numTest):
  n = int(input().strip())
  print(f[n])
  