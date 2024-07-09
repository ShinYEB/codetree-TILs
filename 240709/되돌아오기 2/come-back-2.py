I = input()
move = [[1, 0], [0, 1], [-1, 0], [0, -1]]
x, y = 0, 0

m = 0
cnt = 0
for i in I:
    if i == "F":
        x += move[m][1]
        y += move[m][0]
    elif i == "L":
        m = (m - 1) % 4
    elif i == "R":
        m = (m + 1) % 4
    cnt += 1

    if cnt != 0 and (x == 0 and y ==0):
        break 

if cnt != 0 and (x == 0 and y ==0):
    print(cnt)
else:
    print(-1)