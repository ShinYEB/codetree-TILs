n, m = map(int, input().split())

move = [[1, 0], [0, 1], [-1, 0], [0, -1]]
f = 0

board = [[0 for _ in range(m)] for _ in range(n)]

board[0][0] = 1
x, y = 0, 0
for i in range(2, n * m + 1):
    dx = x + move[f][1]
    dy = y + move[f][0]

    if dx < 0 or dy <0 or dx >= m or dy >= n:
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