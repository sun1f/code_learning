#  操作数据库

## 1. 初始MySQL

### 1.1 什么是数据库

数据库（DB，DataBase）

- 概念：数据仓库，**软件**，安装在操作系统之上，可以存储大量的数据，存储数据，管理数据
- 分类：
  - 关系型数据库（SQL）
    - MySQL，Oracle，SQL Server，DB2，SQLite
    - 通过表和表之间，行和列之间的关系进行数据的存储，如学生信息表，考勤表...
  - 非关系型数据库（NoSQL）
    - Redis，MongoDB
    - 非关系型数据，对象存储，通过对象自身的属性来决定

数据库管理系统（DBMS）

- 数据库的管理软件，科学有效管理数据。
- MySQL是一个数据库管理系统

### 1.2 MySQL简介

[MySQL简介](https://baike.baidu.com/item/mysql/471251 )

## 2. 操作数据库

### 2.1 操作数据库表（了解）

学习思路：

- 对照sqlyog可视化历史查看sql
- 记住固定的语法或关键字

### 2.2 数据库列的列类型

> 数值 

|   名称    |                   类型                   | 内存  |
| :-------: | :--------------------------------------: | :---: |
|  tinyint  |               十分小的数据               | 1字节 |
| smallint  |                 较小数据                 | 2字节 |
| mediumint |               中等大小数据               | 3字节 |
|  **int**  |              **标准的整数**              | 4字节 |
|  bigint   |                较大的数据                | 8字节 |
|   float   |                  浮点数                  | 4字节 |
|  double   |                  浮点数                  | 8字节 |
|  decimal  | 字符串形式的浮点数（一般金融计算时使用） |       |



> 字符串

|    名称     |                 类型                 |  表示范围   |
| :---------: | :----------------------------------: | :---------: |
|    char     |           字符串固定大小的           |    0~255    |
| **varchar** | **可变字符串（对应Java中的String）** | **0~65535** |
|  tinytext   |               微型文本               |    2^8-1    |
|    text     |                文本串                |   2^16-1    |



> 时间日期

|     名称      |                   格式                    |
| :-----------: | :---------------------------------------: |
|     date      |           YYYY-MM-DD，日期格式            |
|     time      |            HH:mm:ss，时间格式             |
| **datetime**  | **YYYY-MM-DD HH:mm:ss，最常用的时间格式** |
| **timestamp** |        **1970.1.1到现在的毫秒数**         |
|     year      |                   年份                    |



> null

- 没有值 ，未知
- 注意不要使用NULL进行运算，结果为NULL

### 2.3 数据库的字段类型（重点）

Unsigned：

- 无符号的整数
- 声明后该列不能为负数

zerofill：

- 0填充的
- 不足的位数，使用0来填充，int(3)，5→005

自增 AUTO_INCREMENT：

- 自动在上一条记录的基础上+1（默认）
- 通常用来设计唯一的主键index，必须是整数类型
- 可以自定义设计主键自增的起始值和步长

非空 NULL

- 假设设置为not null，如果不给它赋值，就会报错
- 如果不填写值，默认是null

默认default：

- 设置默认的值

**扩展**

```mysql
/*
每个表，都必须存在以下五个字段
id 主键
`version`	乐观锁
is_deleted	伪删除
gmt_create	创建时间
gmt_update	修改时间
*/
```



### 2.4 创建数据库表（重点）

> 用SQL语句创建在school数据库下创建student数据表

注意：

- 使用英文()，表的名称和字段尽量用 `` 括起来
- AUTO_CREMENT表示自增
- 字符串使用单引号括起来
- 所有的语句后面加英文逗号','，最后一个不用加
- PRIMARY KEY主键，一般一个表只有一个主键

```mysql
CREATE TABLE IF NOT EXISTS `student` (
     `id` INT(4) NOT NULL AUTO_INCREMENT COMMENT '学号',
     `name` VARCHAR(30) NOT NULL DEFAULT '匿名' COMMENT '姓名',
     `pwd` VARCHAR(20) NOT NULL DEFAULT '123456' COMMENT '密码',
     `sex` VARCHAR(2) NOT NULL DEFAULT '女' COMMENT '性别',
     `birthday` DATETIME DEFAULT NULL COMMENT '出生日期',
     `address` VARCHAR(100) DEFAULT NULL COMMENT '家庭住址',
     `email` VARCHAR(50) DEFAULT NULL COMMENT '邮箱',
     PRIMARY KEY(`id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8
```

格式：

```mysql
CREATE TABLE [IF NOT EXISTS] `表名` (
	'字段名' 列类型 [属性] [索引] [注释],
    '字段名' 列类型 [属性] [索引] [注释],
    ......
    '字段名' 列类型 [属性] [索引] [注释]
)[表类型][字符集设置][注释]
```



> 用下面语句查看创建数据库与表时使用的语句

```mysql
SHOW CREATE DATABASE school -- 查看创建数据库的语句
SHOW CREATE TABLE student -- 查看创建student数据表的定义语句
DESC student -- 查看student表的结构
```



### 2.5 数据表的类型

```sql
-- 关于数据引擎
/*
INNODB 默认使用
MYISAM 早些年使用的
*/
```



|            | MYISAM |    INNODB     |
| :--------: | :----: | :-----------: |
|  事务支持  | 不支持 |     支持      |
| 数据行锁定 | 不支持 |     支持      |
|  外键约束  | 不支持 |     支持      |
|  全文检索  |  支持  |    不支持     |
| 表空间大小 |  较小  | 较大，约为2倍 |

常规使用操作：

- MYISAM   节约空间，速度较快
- INNODB   安全性高，事务的处理，多表多用户操作

> INNODB在物理空间中都存与D:\MySQL\MySQL\MySQL Server 57\Data目录下，本质上是文件的存储

> 设置数据库表的字符集编码

```sql
CHARSET=utf8
```

不设置的话，会是MySQL默认的字符集编码，不支持中文

MySQL的默认编码为Latin1，不支持中文

在my.ini中可以永久配置默认的编码

```ini
character-set-server=utf8
```

### 2.6 修改删除表

修改：

```mysql
-- 修改表名：ALTER TABLE 旧表名 RENAME AS 新表名
ALTER TABLE teacher RENAME AS teacher1

-- 增加表的字段：ALTER TABLE 表名 ADD 字段名 列属性
ALTER TABLE teacher1 ADD age INT(11)

-- 修改表的字段
	-- ALTER TABLE 表名 MODIFY 字段名 列属性()
ALTER TABLE teacher1 MODIFY age VARCHAR(11) -- 修改约束

	-- ALTER TABLE 表名 CHANGE 旧名字 新名字 列属性()
ALTER TABLE teacher1 CHANGE age age1 INT(1) -- 字段重命名

-- 删除列的字段：ALTER TABLE 表名 DROP 字段名
ALTER TABLE teacher1 DROP age1
```

删除：

```mysql
-- 删除表，所有的创建和删除操作都尽量加上判断，以免报错
DROP TABLE IF EXISTS teacher1
```

注意事项：

- 字段名用``包裹
- 注释为 -- 或 /**/
- sql关键字大小写不敏感，建议使用小写
- 所有的符号全部用英文

## 3. MySQL数据管理

### 3.1 外键（了解即可）

> 方法一：在创建表的时候，增加约束（比较麻烦）

```mysql
CREATE TABLE IF NOT EXISTS `grade`(
    `grade_id` INT(10) NOT NULL AUTO_INCREMENT COMMENT '年级id',
    `grade_name` VARCHAR(50) NOT NULL COMMENT '年级名称',
    PRIMARY KEY(`grade_id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8

-- 学生表的 grade_id 字段，要去引用年级表的 grade_id
-- 定义外键 key
-- 给这个外键添加约束（执行引用） references 引用

CREATE TABLE IF NOT EXISTS `student` (
     `id` INT(4) NOT NULL AUTO_INCREMENT COMMENT '学号',
     `name` VARCHAR(30) NOT NULL DEFAULT '匿名' COMMENT '姓名',
     `pwd` VARCHAR(20) NOT NULL DEFAULT '123456' COMMENT '密码',
     `sex` VARCHAR(2) NOT NULL DEFAULT '女' COMMENT '性别',
     `birthday` DATETIME DEFAULT NULL COMMENT '出生日期',
     `gradeid` INT(10) NOT NULL COMMENT '学生的年级',
     `address` VARCHAR(100) DEFAULT NULL COMMENT '家庭住址',
     `email` VARCHAR(50) DEFAULT NULL COMMENT '邮箱',
     PRIMARY KEY(`id`),
     KEY `FK_gradeid` (`gradeid`),
     CONSTRAINT `FK_gradeid` FOREIGN KEY (`gradeid`) REFERENCES `grade`(`grade_id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8
```

删除有外键关系的表的时候，必须要先删除引用的表，再删除被引用的表

> 方法二：创建表成功后，添加外键约束

```mysql
-- 创建表的时候没有外键关系
CREATE TABLE IF NOT EXISTS `student` (
     `id` INT(4) NOT NULL AUTO_INCREMENT COMMENT '学号',
     `name` VARCHAR(30) NOT NULL DEFAULT '匿名' COMMENT '姓名',
     `pwd` VARCHAR(20) NOT NULL DEFAULT '123456' COMMENT '密码',
     `sex` VARCHAR(2) NOT NULL DEFAULT '女' COMMENT '性别',
     `birthday` DATETIME DEFAULT NULL COMMENT '出生日期',
     `gradeid` INT(10) NOT NULL COMMENT '学生的年级',
     `address` VARCHAR(100) DEFAULT NULL COMMENT '家庭住址',
     `email` VARCHAR(50) DEFAULT NULL COMMENT '邮箱',
     PRIMARY KEY(`id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8

-- ALTER TABLE 表名 ADD CONSTRAINT 约束名 FOREIGN KEY(作为外键的列) REFERENCES 那个表(那个字段)
ALTER TABLE `student` 
ADD CONSTRAINT `FK_gradeid` FOREIGN KEY(`gradeid`) REFERENCES `grade`(`grade_id`); 
```

以上的操作都是物理外键，即数据库级别的外键，不建议使用！（避免数据库过多造成困扰）

**最佳方案：**

- 数据库就是单纯的表，只用来存数据，只有行（数据）和列（字段）
- 当需要在多张表中使用外键的时候，用程序实现

### 3.2 DML语言（全部记住）







 
