def convertToString(n) -> str:
    tmp = n
    st = ""
    while tmp > 0:
        if tmp % 2 == 1:
            st += '1'
        else:
            st += '0'
        tmp //= 2
    ret = st[::-1]
    return ret
numTest = int(input().strip())
for testCase in range(numTest):
    a, b, c, d = map(int, input().strip().split())
    dp = [[[[[0 for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(705)]
    l1 = convertToString(a)
    r1 = convertToString(b)
    l2 = convertToString(c)
    r2 = convertToString(d)
    r1 = "0" + r1
    r2 = "0" + r2
    n = len(r1)
    if n < len(r2):
        n = len(r2)
    while len(l1) < n:
        l1 = "0" + l1
    while len(r1) < n:
        r1 = "0" + r1
    while len(l2) < n:
        l2 = "0" + l2
    while len(r2) < n:
        r2 = "0" + r2
    n -= 1
    for statea in range(2):
        for stateb in range(2):
            for statec in range(2):
                for stated in range(2):
                    dp[n][statea][stateb][statec][stated] = 1
    for i in range(n - 1, -1, -1):
        for statea in range(2):
            for stateb in range(2):
                for statec in range(2):
                    for stated in range(2):
                        for x in range(2):
                            for y in range(2):
                                if statea == 1 and x < ord(l1[i + 1]) - 48:
                                    continue
                                if stateb == 1 and x > ord(r1[i + 1]) - 48:
                                    continue
                                if statec == 1 and y < ord(l2[i + 1]) - 48:
                                    continue
                                if stated == 1 and y > ord(r2[i + 1]) - 48:
                                    continue
                                nextStatea = statea
                                if statea == 1 and x > ord(l1[i + 1]) - 48:
                                    nextStatea = 0
                                nextStateb = stateb
                                if stateb == 1 and x < ord(r1[i + 1]) - 48:
                                    nextStateb = 0
                                nextStatec = statec
                                if statec == 1 and y > ord(l2[i + 1]) - 48:
                                    nextStatec = 0
                                nextStated = stated
                                if stated == 1 and y < ord(r2[i + 1]) - 48:
                                    nextStated = 0
                                dp[i][statea][stateb][statec][stated] += dp[i + 1][nextStatea][nextStateb][nextStatec][nextStated]
    ans = 0
    median = ((b - a + 1) * (d - c + 1) + 1) // 2
    listState = [[1, 1, 1, 1, 1]]
    for i in range(n):
        count = [[[[0 for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(2)]
        mark = [[[[False for _ in range(2)] for _ in range(2)] for _ in range(2)] for _ in range(2)]
        nextListState = []
        numberOfWays = 0
        listXor0 = []
        listXor1 = []
        for state in listState:
            statea = state[0]
            stateb = state[1]
            statec = state[2]
            stated = state[3]
            numb = state[4]
            for x in range(2):
                for y in range(2):
                    if statea == 1 and x < ord(l1[i + 1]) - 48:
                        continue
                    if stateb == 1 and x > ord(r1[i + 1]) - 48:
                        continue
                    if statec == 1 and y < ord(l2[i + 1]) - 48:
                        continue
                    if stated == 1 and y > ord(r2[i + 1]) - 48:
                        continue
                    nextStatea = statea
                    if statea == 1 and x > ord(l1[i + 1]) - 48:
                        nextStatea = 0
                    nextStateb = stateb
                    if stateb == 1 and x < ord(r1[i + 1]) - 48:
                        nextStateb = 0
                    nextStatec = statec
                    if statec == 1 and y > ord(l2[i + 1]) - 48:
                        nextStatec = 0
                    nextStated = stated
                    if stated == 1 and y < ord(r2[i + 1]) - 48:
                        nextStated = 0
                    if x == y:
                        numberOfWays += numb * dp[i + 1][nextStatea][nextStateb][nextStatec][nextStated]
                        listXor0.append([nextStatea, nextStateb, nextStatec, nextStated, numb])
                    else:
                        listXor1.append([nextStatea, nextStateb, nextStatec, nextStated, numb])
        if median <= numberOfWays:
            ans = ans * 2
            for element in listXor0:
                count[element[0]][element[1]][element[2]][element[3]] += element[4]
            for element in listXor0:
                if mark[element[0]][element[1]][element[2]][element[3]] == False:
                    mark[element[0]][element[1]][element[2]][element[3]] = True
                    element[4] = count[element[0]][element[1]][element[2]][element[3]]
                    nextListState.append(element)
        else:
            median -= numberOfWays
            ans = ans * 2 + 1
            for element in listXor1:
                count[element[0]][element[1]][element[2]][element[3]] += element[4]
            for element in listXor1:
                if mark[element[0]][element[1]][element[2]][element[3]] == False:
                    mark[element[0]][element[1]][element[2]][element[3]] = True
                    element[4] = count[element[0]][element[1]][element[2]][element[3]]
                    nextListState.append(element)
        listState = nextListState
    print(ans)