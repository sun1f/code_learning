# 标题1
## 这是标题2
-------
字号为什么这么小啊
### ~~标题3~~
#### 标题4
##### 标题5
###### ~标题6~ 
11

**粗体文本**  
__粗体文本__  
***又粗又斜***  
*斜体*  
_斜体_

<u>***带下划线的文本***</u>

什么是一键三连 [^一键三连]  

[^一键三连]: 点赞、投币、收藏  


## Markdown 列表  
### 无需列表
* 第一  
    1. 第一点
    2. 第二点  
        - 第二点中的其中一点
* 第二
* 第三
----
### 有序列表
1. 2023年的任务  
    - [ ] 吃饭
    - [ ] 睡觉
    - [ ] 打游戏
    - [x] 不学习
2. 第二  
  > * 如何嵌套列表
  > * 还是如何嵌套列表
3. 第三  
  > * 如何嵌套列表
  > * 还是如何嵌套列表

## Markdown区块
> 区块引用  
> 菜鸟教程  
> 学的不仅是技术还有梦想  

> 最外层
>> 第一层嵌套
>>> 第二层嵌套  


## Markdown代码
```C++
int main() {
    cout << "Hello World!" << endl;
    cout << "---------" << endl;
    return 0;
}
//这是C++代码
```
## MarkDown链接
这是[百度](https://www.baidu.com "一个搜索引擎")的链接  
这个是[b站](https://www.bilibili.com "一个视频网站")的链接

<https://www.baidu.com>用尖括号直接变成链接

* 用变量指代  
  这个链接用谷歌作为网址变量[Google][谷歌]  
  这个链接用百度作为网址变量[Baidu][百度]  
  然后再文档的结尾为变量赋值（网址）

这个链接是指代的[百度]地址

  [谷歌]: https://www.google.com "这个搜索引擎叫谷歌"
  [百度]: https://www.baidu.com "这个搜索引擎叫度娘"

## Markdown图片
![美女](https://img1.baidu.com/it/u=1349727138,86782678&fm=253&app=138&size=w931&n=0&f=JPEG&fmt=auto?sec=1672592400&t=887d9cd065614849eda84b064dcb7309)  
![图标](https://www.bing.com/th?id=OIP.xH-XuuVdFGEUTV1wJXeS_QHaHb&w=249&h=250&c=8&rs=1&qlt=90&o=6&dpr=2&pid=3.1&rm=2)

<iframe src="//player.bilibili.com/player.html?aid=327623069&bvid=BV1JA411h7Gw&cid=171385214&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true"> </iframe>

## Markdown表格
|左对其对齐对齐|右对其对齐|居中对齐居中对齐|
|:-----|:----:|:----:|
|1|4|[百度]|
|22|[标题1](#标题1)|66|

<video src="视频链接"></video>
<iframe height=498 width=510 src="[视频链接](https://www.bilibili.com/video/BV1nY411U75U/?spm_id_from=333.1007.tianma.1-2-2.click&vd_source=a50f589772cb2a3ec1f9190291cd27be)">
