import math
power10 = [0 for _ in range(16)]
power10[0] = 1
for i in range(1, 16):
    power10[i] = power10[i - 1] * 10
numTest = int(input().strip())
for testCase in range(1, numTest + 1):
    print("Case #", end = '')
    print(testCase, end = '')
    print(": ", end = '')
    frac = input()
    a = 0
    posDot = -1
    for i in range(len(frac)):
        if frac[i] == '.':
            posDot = i
            break
        else:
            a = a * 10 + ord(frac[i]) - 48
    if posDot == -1:
        print(a, end = '')
        print('/', end = '')
        print(1)
    else:
        b = 0 
        posBrack = -1
        for i in range(posDot + 1, len(frac)):
            if frac[i] == '(':
                posBrack = i
                break 
            else:
                b = b * 10 + ord(frac[i]) - 48
        if posBrack == -1:
            deno = b 
            nume = power10[len(frac) - posDot - 1]
            g = math.gcd(deno, nume)
            deno //= g 
            nume //= g
            deno = deno + a * nume 
            print(deno, end = '')
            print('/', end = '')
            print(nume)
        else:
            tmpDeno = b 
            tmpNume = power10[posBrack - posDot - 1]
            g = math.gcd(tmpDeno, tmpNume)
            tmpDeno //= g 
            tmpNume //= g 
            x = 0 
            for i in range(posBrack + 1, len(frac) - 1):
                x = x * 10 + ord(frac[i]) - 48
            y = power10[len(frac) - 2 - posBrack]
            y -= 1 
            y *= power10[posBrack - posDot - 1]
            g = math.gcd(x, y)
            x //= g 
            y //= g 
            x = x * tmpNume + y * tmpDeno
            y *= tmpNume
            g = math.gcd(x, y)
            x //= g 
            y //= g
            x = x + a * y
            print(x, end = '')
            print('/', end = '')
            print(y)
            