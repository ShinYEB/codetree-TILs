forward = [[0, 1], [1, 0], [0, -1], [-1, 0]]
answer = [0, 0]
m = 0

I = input()
for i in I:
    if i == "F":
        answer[0] += forward[m][0]
        answer[1] += forward[m][1]
    elif i == "L":
        m = (m + 3) % 4
    elif i == "R":
        m = (m + 1) % 4

print(answer[0], answer[1])