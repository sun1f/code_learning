def maximum_essence_posts(n, m, k, intervals):
    posts = [1] * n  # ��ʼ�������б�Ĭ��ÿ�����Ӷ��Ǿ�����
    intervals.sort(key=lambda x: (x[0], -x[1]))  # �����䰴����ʼλ�����򣬽���λ�ý�������

    # ����ÿ�����䣬���������ڵ����ӱ��Ϊ�Ǿ�����
    for li, ri in intervals:
        for i in range(li - 1, ri):
            posts[i] = 0

    # ͳ�ƾ�����������
    essence_count = sum(posts)

    # ��Ӫͬѧ��ȡ�����б���Ϊk
    if k < essence_count:
        posts.sort(reverse=True)  # �������б��վ�������������������
        essence_count = sum(posts[:k])  # ͳ�ƽ�ȡ��ľ�����������

    return essence_count

# ����ʾ��
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    intervals = []
    for _ in range(m):
        li, ri = map(int, input().split())
        intervals.append((li, ri))

    result = maximum_essence_posts(n, m, k, intervals)
    print(result)
