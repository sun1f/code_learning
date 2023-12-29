# 1. CSS简介

**CSS的优势：**

- 内容和表现分离
- 网页结构表现统一，可以实现复用
- 样式十分丰富
- 建立使用独立于html的css文件
- 利用SEO，容易被搜索引擎收录

## 1.1 发展史

CSS1.0

CSS2.0	DIV（块）+ CSS，==HTML与CSS结构分离的思想==，使网页变得简单，SEO

CSS2.1	浮动，定位

CSS3.0	圆角、阴影、动画、浏览器兼容性...

## 1.2 主要内容

1. CSS是什么
2. CSS快速入门
3. **CSS选择器（重点 + 难点）**
4. 美化网页（文字、阴影、超链接、列表、渐变...）
5. 盒子模型
6. 浮动
7. 定位
8. 网页动画（特效效果）



## 1.3 快速入门

- style写法（css写在html里面）

  ```html
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <title>Title</title>
  
      <!-- <style> 可以编写css代码。每一个声明，最好使用分号结尾。
      语法：
          选择器 {
              声明1;
              声明2;
              声明3;
      -->
      <style>
         h1 {
             color: red;
         }
      </style>
  
  </head>
  <body>
  
  <h1>我是标题一</h1>
  
  </body>
  </html>
  ```

- css 与 html 分离（建议使用这种规范）

  ![1703488975946](E:\wechatfile\WeChat Files\wxid_7fcpz51fwzpt22\FileStorage\Temp\1703488975946.png)

## 1.4 CSS的三种导入方式

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>

    <!--内部样式-->
    <style>
        h1 {
            color: green;
        }
    </style>

    <!--外部样式1-->
    <style>
        @import url("css/style.css");
    </style>

    <!--外部样式2-->
    <link rel="stylesheet" href="css/style.css">


</head>
<body>

<!--优先级：就近原则-->
<!--行内样式：在标签元素中，编写一个style属性，编写样式即可-->
<h1 style="color: red">这是标题一</h1>

</body>
</html>
```

- 行内样式

  ```css
  <!--行内样式：在标签元素中，编写一个style属性，编写样式即可-->
  <h1 style="color: red">这是标题一</h1>
  ```

- 内部样式

  ```css
  <!--内部样式-->
  <style>
      h1 {
          color: green;
      }
  </style>
  ```

- 外部样式

  - 链接式（推荐使用）

    ```html
    <!--链接式-->
    <link rel="stylesheet" href="css/style.css">
    ```

  - 导入式（CSS 2.1特有，现在已经不用）

    ```html
    <!--导入式-->
    <style>
    	@import url("css/style.css");
    </style>
    ```


# 2. 选择器

**作用：**选择页面上的某一个或者某一类元素

## 2.1 基本选择器

==优先级：id选择器 > 类选择器 > 标签选择器==

1. 标签选择器：选择一个标签

   ```html
   <!DOCTYPE html>
   <html lang="en">
   <head>
       <meta charset="UTF-8">
       <title>Title</title>
   
       <!--标签选择器，会覆盖到页面上所有的这个标签的元素-->
       <style>
           h1 {
               color: #ee3ca9;
               background: #18de4f;
               border-radius: 24px;
           }
           p {
               font-size : 80px;
           }
   
       </style>
   </head>
   <body>
   
   <h1>学习css</h1>
   <h1>学习Java</h1>
   
   <p>学习html</p>
   
   </body>
   </html>
   ```

2. 类（Class）选择器：选择所有class属性一致的标签，跨标签

   ```html
   <!DOCTYPE html>
   <html lang="en">
   <head>
       <meta charset="UTF-8">
       <title>Title</title>
   
       <!--类选择器
       格式：.class名{}
       好处：可以多个标签归类为同一个class，便于复用
       -->
       <style>
           .sun1f {
               color: #3f59ee;
           }
           .sun2f {
               color: #47ee23;
           }
           .sun3f {
               color: #ee2914;
           }
   
       </style>
   </head>
   <body>
   
   <h1 class="sun1f">标题1</h1>
   <h1 class="sun2f">标题2</h1>
   <h2 class="sun3f">标题3</h2>
   
   <h3 class="sun1f">标题4</h3>
   
   <p class="sun1f">p标签</p>
   
   </body>
   </html>
   ```

3. id 选择器：全局唯一

   ```html
   <!DOCTYPE html>
   <html lang="en">
   <head>
       <meta charset="UTF-8">
       <title>Title</title>
   
       <!--id选择器，id必须保证全局唯一
       格式：#id名称 {}
   
       不遵循就近原则，优先级为：id选择器 > class选择器 > 标签选择器
       -->
       <style>
   
           #sun1f {
               color: #37ee16;
           }
           .style1 {
               color: #1dddee;
           }
           h1 {
               color: #ee9a52;
           }
       </style>
   </head>
   <body>
   
   <h1 class="style1" id="sun1f">标题1</h1>
   <h1 class="style1">标题2</h1>
   <h1 class="style1">标题3</h1>
   <h1>标题4</h1>
   <h1>标题5</h1>
   
   </body>
   </html>
   ```

## 2.2 层次选择器

1. 后代选择器（所有后代）

   ```css
   /*后代选择器，body的后代全部变色*/
   body p {
       background: #1dddee;
   }
   ```

2. 子选择器（儿子）

   ```css
   /*子选择器：只有body的儿子变色*/
   body > p {
       background: #ee3ca9;
   }
   ```

3. 相邻兄弟选择器（向下一个同辈）

   ```css
   /*相邻兄弟选择器：向下一个同级标签变色*/
   .active + p {
       background: #ee9a52;
   }
   ```

4. 通用选择器（向下所有同辈）

   ```css
   /*通用兄弟选择器：当前选中元素的向下所有兄弟标签标色*/
   .active ~ p {
       background: #3f59ee;
   }
   ```

## 2.3 结构伪类选择器

```css
<!--不使用class和id选择器-->
<style>
  /*选中ul的第一个元素*/
  ul li:first-child {
    background: #3f59ee;
  }
  /*选中ul的最后一个元素*/
  ul li:last-child {
    background: #ee9a52;
  }

  p:nth-child(2) {
    background: #ee3ca9;
  }
  p:nth-of-type(1) {
    background: #1dddee;
  }

  a:hover {
    background: grey;
  }

</style>
```

## 2.4 属性选择器（重要 + 常用）

id + class 组合

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>

    <style>
        .demo a {
            float: left;
            display: block;
            height: 50px;
            width: 50px;
            border-radius: 10px; /*圆角边框*/
            background: cadetblue;
            text-align: center;
            color: darkgreen;
            text-decoration: none; /*去掉下划线*/
            margin-right: 6px;
            font: bold 20px/50px Arial;
        }

        /*选中存在id属性的a标签*/
        a[id] {
            background: #ee9a52;
        }
        /*选中id=first的a标签，中括号[]里面可以用正则表达式*/
        a[id = first] {
            background: #ee3ca9;
        }
        /*选中class=links的a标签，其中"="表示等于，"*="表示包含此元素*/
        a[class *= "links"] {
            background: grey;
        }

        /*选中herf中以https开头的a标签。其中，"^="表示以此元素开头*/
        a[href ^= "https"] {
            background: #ee2914;
        }
        /*选中herf中以pdf结尾的a标签。其中，"$="表示以此元素结尾*/
        a[href $= "pdf"] {
            background: bisque;
        }

    </style>

</head>
<body>

    <p class="demo">
        <a href="https://www.baidu.com" class="links item first" id="first">1</a>
        <a href="" class="links item active" target="_blank" title="test">2</a>
        <a href="images/123.html" class="links item">3</a>
        <a href="images/123.png" class="links item">4</a>
        <a href="images/123.jpg" class="links item">5</a>
        <a href="abc" class="links item">6</a>
        <a href="/a.pdf" class="links item">7</a>
        <a href="/abd.pdf" class="links item">8</a>
        <a href="/abd.doc" class="links item">9</a>
        <a href="/abcd.docx" class="links item last">10</a>

    </p>

</body>
</html>
```



# 3. 美化网页元素

### 3.1 span标签

> 通常给需要突出表达的内容加一个`span`标签

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>

    <style>
        #title1 {
            font-size: 40px;
        }
    </style>

</head>
<body>
    <!--通常给需要突出表达的内容加一个span标签-->
    It's happy to learn <span id="title1">Java</span>!

</body>
</html>
```

### 3.2 字体样式
