N = int(input())
m = {"N":[1, 0], "S":[-1, 0], "E":[0, 1], "W":[0, -1]}
x, y = 0, 0

cnt = 0
for _ in range(N):
    a, b = input().split()

    for i in range(int(b)):
        x += m[a][1]
        y += m[a][0]
        cnt += 1 
        if cnt != 0 and (x == 0 and y ==0):
            break

    if cnt != 0 and (x == 0 and y ==0):
        break 

if cnt != 0 and (x == 0 and y ==0):
    print(cnt)
else:
    print(-1)