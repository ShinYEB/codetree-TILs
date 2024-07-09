N = int(input())
board = [[0 for _ in range(N+2)]]
for _ in range(N):
    temp = list(map(int, input().split()))
    temp = [0] + temp + [0]
    board.append(temp)
board.append([0 for _ in range(N+2)])

result = 0
for y in range(N+1):
    for x in range(N+1):
        s = board[y][x+1] + board[y+1][x] + board[y][x-1] + board[y-1][x]
        if s >= 3:
            result += 1

print(result)