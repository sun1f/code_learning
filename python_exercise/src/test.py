n, m, k = map(int, input().split())
a = list(map(int, input().split()))
h = list(map(int, input().split()))

dp = [[[0] * (k + 1) for _ in range(4)] for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, 4):
        for t in range(0, k + 1):
            dp[i][j][t] = dp[i - 1][j][t]
            if t >= h[i - 1]:
                dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j - 1][t - h[i - 1]] + a[i - 1])

answer = max(dp[n][1][k], dp[n][2][k], dp[n][3][k])
print(answer)
