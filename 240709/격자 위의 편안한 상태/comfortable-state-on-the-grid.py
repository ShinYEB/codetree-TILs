N, M = map(int, input().split())
board = [[0 for _ in range(N+2)] for _ in range(N+2)]

for _ in range(M):
    y, x = map(int, input().split())
    board[y][x] = 1

    cnt = board[y+1][x] + board[y][x+1] + board[y-1][x] + board[y][x-1]
    if cnt == 3:
        print(1)
    else:
        print(0)