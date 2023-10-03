def maximum_essence_posts(n, m, k, intervals):
    posts = [1] * n  # 初始化帖子列表，默认每个帖子都是精华帖
    intervals.sort(key=lambda x: (x[0], -x[1]))  # 对区间按照起始位置升序，结束位置降序排序

    # 遍历每个区间，将该区间内的帖子标记为非精华帖
    for li, ri in intervals:
        for i in range(li - 1, ri):
            posts[i] = 0

    # 统计精华帖子数量
    essence_count = sum(posts)

    # 运营同学截取帖子列表长度为k
    if k < essence_count:
        posts.sort(reverse=True)  # 将帖子列表按照精华帖子数量降序排序
        essence_count = sum(posts[:k])  # 统计截取后的精华帖子数量

    return essence_count

# 输入示例
if __name__ == "__main__":
    n, m, k = map(int, input().split())
    intervals = []
    for _ in range(m):
        li, ri = map(int, input().split())
        intervals.append((li, ri))

    result = maximum_essence_posts(n, m, k, intervals)
    print(result)
