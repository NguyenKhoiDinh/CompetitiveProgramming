def POW(x, n):
  if n == 0:
    return 1
  tmp = POW(x, n // 2)
  tmp *= tmp
  if n % 2 == 1:
    tmp *= x
  return tmp

class PlanningTrips:
  def find(self, a, num):
    sum = 0
    for n in num:
      sum += POW(a, n)
    val = 1
    ans = 0
    while val < sum:
      val *= a
      ans += 1
    return ans