N = int(input())
board = [input() for _ in range(N)]
K = int(input())
reflect = {("\\", "L"):"U", ("\\", "D"):"R",
            ("\\", "R"):"D", ("\\", "U"):"L",
            ("/", "L"):"D", ("/", "D"):"L",
            ("/", "R"):"U", ("/", "U"):"R"}
move = {"L":[0, -1], "R":[0, 1], "U":[-1, 0], "D":[1, 0]}

x, y = 0, 0
direct = ""
if int((K-1) / N) == 0:
    x = (K-1) % N
    y = 0
    direct = "D"
elif int((K-1) / N) == 1:
    x = N-1
    y = (K-1) % N
    direct = "L"
elif int((K-1) / N) == 2:
    x = (K-1) % N
    y = N-1
    direct = "U"
elif int((K-1) / N) == 3:
    x = 0
    y = (K-1) % N
    direct = "R"

cnt = 0

while (x != -1 and y != -1 and x != N and y != N):
    mirror = board[y][x]
    direct = reflect[(mirror, direct)]
    cnt += 1
    x += move[direct][1]
    y += move[direct][0]

print(cnt)