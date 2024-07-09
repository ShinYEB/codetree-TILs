n = int(input())

move = [[0, -1], [-1, 0], [0, 1], [1, 0]]
f = 0

board = [[0 for _ in range(n)] for _ in range(n)]

board[n-1][n-1] = n * n
x, y = n-1, n-1
for i in range(n * n - 1, 0, -1):
    dx = x + move[f][1]
    dy = y + move[f][0]

    if dx < 0 or dy <0 or dx >= n or dy >= n:
        f = (f + 1) % 4
        dx = x + move[f][1]
        dy = y + move[f][0]
    elif board[dy][dx] != 0:
        f = (f + 1) % 4
        dx = x + move[f][1]
        dy = y + move[f][0]

    board[dy][dx] = i
    x, y = dx, dy

for b in board:
    print(*b)