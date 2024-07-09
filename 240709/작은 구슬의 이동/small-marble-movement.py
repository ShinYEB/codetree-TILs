n, t = map(int, input().split())
r, c, d = input().split()
r = int(r) - 1
c = int(c) - 1

mapper = {"L":[0, -1], "R":[0, 1], "U":[-1, 0], "D":[1, 0]}
reverse = {"L":"R", "R":"L", "U":"D", "D":"U"}

for _ in range(t):
    c += mapper[d][0]
    r += mapper[d][1]

    if r < 0 or r >= n:
        d = reverse[d]
        c += mapper[d][0]
        r += mapper[d][1]
    if c < 0 or c >= n:
        d = reverse[d]
        c += mapper[d][0]
        r += mapper[d][1]

print(c, r)