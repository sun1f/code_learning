import sys

def calculate_edit_distance(s1, s2):
    len_s1 = len(s1)
    len_s2 = len(s2)

    # 创建一个二维数组用于存储编辑距离
    dp = [[0] * (len_s2 + 1) for _ in range(len_s1 + 1)]

    # 初始化第一行和第一列
    for i in range(len_s1 + 1):
        dp[i][0] = i
    for j in range(len_s2 + 1):
        dp[0][j] = j

    # 填充数组并计算编辑距离
    for i in range(1, len_s1 + 1):
        for j in range(1, len_s2 + 1):
            cost = 0 if s1[i - 1] == s2[j - 1] else 1
            dp[i][j] = min(dp[i - 1][j] + 1,       # 删除操作
                           dp[i][j - 1] + 1,       # 插入操作
                           dp[i - 1][j - 1] + cost) # 替换操作

    return dp[len_s1][len_s2]

# 从标准输入读取两行字符串
true_text = input().strip()
recognize_text = input().strip()

# 计算编辑距离
distance = calculate_edit_distance(true_text, recognize_text)

# 计算插入错误、删除错误和替换错误的次数
insertions = 0
deletions = 0
replacements = 0

i, j = len(true_text), len(recognize_text)

while i > 0 or j > 0:
    if i > 0 and j > 0 and dp[i][j] == dp[i - 1][j - 1]:
        i -= 1
        j -= 1
    elif i > 0 and dp[i][j] == dp[i - 1][j] + 1:
        deletions += 1
        i -= 1
    elif j > 0 and dp[i][j] == dp[i][j - 1] + 1:
        insertions += 1
        j -= 1
    elif i > 0 and j > 0:
        replacements += 1
        i -= 1
        j -= 1

# 输出插入错误、删除错误和替换错误的次数
print(insertions, deletions, replacements)
