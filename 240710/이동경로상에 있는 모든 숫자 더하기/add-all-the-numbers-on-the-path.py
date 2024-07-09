N, T = map(int, input().split())
I = input()

move = [[-1, 0], [0, 1], [1, 0], [0, -1]]
x, y = int(N/2), int(N/2)
m = 0

w = [list(map(int, input().split())) for _ in range(N)]

cnt = w[y][x]
for i in I:
    if i == "L":
        m = (m - 1) % 4
    elif i == "R":
        m = (m + 1) % 4
    elif i == "F":

        dx = move[m][1] + x
        dy = move[m][0] + y

        if dx < 0 or dy < 0 or dx >= N or dy >= N:
            continue
        else:
            x = dx
            y = dy
            cnt += w[y][x]

print(cnt)