import sys

def calculate_edit_distance(s1, s2):
    len_s1 = len(s1)
    len_s2 = len(s2)

    # ����һ����ά�������ڴ洢�༭����
    dp = [[0] * (len_s2 + 1) for _ in range(len_s1 + 1)]

    # ��ʼ����һ�к͵�һ��
    for i in range(len_s1 + 1):
        dp[i][0] = i
    for j in range(len_s2 + 1):
        dp[0][j] = j

    # ������鲢����༭����
    for i in range(1, len_s1 + 1):
        for j in range(1, len_s2 + 1):
            cost = 0 if s1[i - 1] == s2[j - 1] else 1
            dp[i][j] = min(dp[i - 1][j] + 1,       # ɾ������
                           dp[i][j - 1] + 1,       # �������
                           dp[i - 1][j - 1] + cost) # �滻����

    return dp[len_s1][len_s2]

# �ӱ�׼�����ȡ�����ַ���
true_text = input().strip()
recognize_text = input().strip()

# ����༭����
distance = calculate_edit_distance(true_text, recognize_text)

# ����������ɾ��������滻����Ĵ���
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

# ����������ɾ��������滻����Ĵ���
print(insertions, deletions, replacements)
