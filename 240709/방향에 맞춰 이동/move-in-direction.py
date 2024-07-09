N = int(input())
forawrd = {"N":[0, 1], "S":[0, -1], "E":[1, 0], "W":[-1, 0]}
answer = [0, 0]

for _ in range(N):
    f, w = input().split()

    answer[0] += forawrd[f][0] * int(w)
    answer[1] += forawrd[f][1] * int(w)

print(answer[0], answer[1])