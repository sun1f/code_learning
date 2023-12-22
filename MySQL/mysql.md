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

DML语言：数据操作语言

- insert
- update
- delete

#### 3.2.1 插入

> -- 插入语法：INSERT INTO 表名 (字段名1, 字段名2,..., 字段名n) values (值1, 值2,..., 值n), (值1, 值2,..., 值n),..., (值1, 值2,..., 值n)

```mysql
-- 当不写表的字段时，会按顺序一一匹配，当字段设为自增或有默认值时，添加时可以省略不写
-- 一般写插入语句时，要将字段与数据一一对应
INSERT INTO `grade`(`grade_name`) VALUES('大四')
INSERT INTO `grade`(grade_name) VALUES('大一'), ('大二'), ('大三')

INSERT INTO `student` (`name`) VALUES('张三')
INSERT INTO `student` (`name`, `pwd`, `sex`) VALUES ('李四', 'abcdef', '男')
INSERT INTO `student` (`name`, `pwd`, `sex`) VALUES ('王五', '1234', '女'), ('赵六', '567', '男'), ('冯七', '8910', '女')
```

注意事项：

- 英文逗号！
- 字段可以省略，但是后面的值必须与表中的字段顺序一一对应
- 可以同时插入多条数据，values后面的值需要使用英文逗号隔开，values(), (),..., ()

#### 3.2.2 修改

> 语法：UPDATE 表名 SET 字段名1 = 值1, 字段名2 = 值2,..., 字段名n = 值n WHERE [条件]

```mysql
-- 带where，指定修改位置
UPDATE `student` SET `name` = 'sun1f' WHERE `id` = 1

-- 不指定条件的情况下，会改动表中的全体数据
UPDATE `student` SET `name` = 'sun1f'

-- 修改多个属性，用英文逗号隔开
UPDATE `student` SET `name` = 'syf', `email` = 'sun1f@foxmail.com' WHERE `id` = 1
```

**条件：**where子句会返回布尔值

|        操作符        |     含义     |       示例       | 结果  |
| :------------------: | :----------: | :--------------: | :---: |
|          =           |     等于     |      5 = 6       | FALSE |
|       <> 或 !=       |    不等于    |      5 <> 6      | FALSE |
|          >           |              |                  |       |
|          <           |              |                  |       |
|          <=          |              |                  |       |
|          >=          |              |                  |       |
| BETWEEN ... AND .... | 在某个范围内 | BETWEEN 5 AND 2  |       |
|         AND          |  相当于 &&   | 5 > 1 AND 1 > 2  | FALSE |
|          OR          | 相当于 \|\|  | 5 > 1 \|\| 1 > 2 | TRUE  |

```mysql
-- 通过多个条件定位数据
UPDATE `student` SET `name` = '长江7号' WHERE `name` = 'sun1f' AND `sex` = '女'

-- value 可以是一个具体的值，也可以是一个变量，CURRENT_TIME 是当前时间
UPDATE `student` SET `birthday` = CURRENT_TIME WHERE `name` = '长江7号' AND `sex` = '女'
```

#### 3.3.3 删除

> 语法：DELETE FROM 表名 WHERE [条件]

```mysql
-- 删除数据（全部删除，避免这样写）
DELETE FROM `student`

-- 删除指定的数据
DELETE FROM `student` WHERE `id` = 1
```

> TRUNCATE命令：完全清空一个数据库表，表的结构和索引约束不会变

```mysql
-- 清空 student 表
TRUNCATE `student`
```

**DELETE** 和 **TRUNCATE**都能删除数据，且不会影响表结构，区别是：

- TRUNCATE会重新设置自增列，自增计数会归零
- TRUNCATE不会影响事务

```mysql
-- 测试 DELETE 和 TRUNCATE 的区别
CREATE TABLE `test` (
   `id` INT(4) NOT NULL AUTO_INCREMENT,
   `coll` VARCHAR(20) NOT NULL,
   PRIMARY KEY(`id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8

INSERT INTO `test` (`coll`) VALUES ('1'), ('2'), ('3')

DELETE FROM `test` -- 不会影响自增计数

TRUNCATE TABLE `test` -- 自增会归零
```

*了解：使用DELETE删除后，重启数据库时：

- 在InnoDB引擎中，自增列会从1开始，因为其存在于内存中，断电即失
- 在MyISAM中，将继续从上一个自增量开始，因为其存在于文件中，不会丢失

## 4. DQL查询数据（最重点）

DQL（Data Query Language）是数据查询语言

- 所有的查询操作都用它 **SELECT**
- 简单的查询、复杂的查询它都能做
- **数据库中最核心的语言，最重要的语句**
- 使用频率最高的语句

> SELECT 完整语法，其中，**[]括号表示可选的，{}括号表示必选的**

```mysql
SELECT [ALL | DISTINCT]
{* | table.* | [table.field1[as alias1][, table.field2[as alias2]][,...]]}
FROM table_name [as table_alias]
	[left | right | inner join table_name2] -- 联合查询
	[where ...] -- 指定结果需满足的条件
	[GROUP BY ...] -- 指定结果按照哪几个字段来分组
	[HAVING] -- 过滤分组的记录必须满足的次要条件
	[ORDER BY ...] -- 指定查询记录按一个或多个条件排序
	[LIMIT {[offset,]row_count | row_countOFFSET offset}];
	-- 指定查询的记录从哪条至哪条
```

### 4.1 数据准备

1. 创建 school 数据库，创建 student 学生表

```mysql
create database if not exists `school`;
-- 创建一个school数据库
use `school`;-- 创建学生表
drop table if exists `student`;
create table `student`(
	`studentno` int(4) not null comment '学号',
    `loginpwd` varchar(20) default null,
    `studentname` varchar(20) default null comment '学生姓名',
    `sex` tinyint(1) default null comment '性别，0或1',
    `gradeid` int(11) default null comment '年级编号',
    `phone` varchar(50) not null comment '联系电话，允许为空',
    `address` varchar(255) not null comment '地址，允许为空',
    `borndate` datetime default null comment '出生时间',
    `email` varchar (50) not null comment '邮箱账号允许为空',
    `identitycard` varchar(18) default null comment '身份证号',
    primary key (`studentno`),
    unique key `identitycard`(`identitycard`),
    key `email` (`email`)
)engine=myisam default charset=utf8;
```

2. 创建 grade 年级表，创建 subject 科目表，创建 result 成绩表

```mysql
drop table if exists `grade`;
create table `grade`(
	`gradeid` int(11) not null auto_increment comment '年级编号',
  `gradename` varchar(50) not null comment '年级名称',
    primary key (`gradeid`)
) engine=innodb auto_increment = 6 default charset = utf8;

-- 创建科目表
drop table if exists `subject`;
create table `subject`(
	`subjectno`int(11) not null auto_increment comment '课程编号',
    `subjectname` varchar(50) default null comment '课程名称',
    `classhour` int(4) default null comment '学时',
    `gradeid` int(4) default null comment '年级编号',
    primary key (`subjectno`)
)engine = innodb auto_increment = 19 default charset = utf8;

-- 创建成绩表
drop table if exists `result`;
create table `result`(
	`studentno` int(4) not null comment '学号',
    `subjectno` int(4) not null comment '课程编号',
    `examdate` datetime not null comment '考试日期',
    `studentresult` int (4) not null comment '考试成绩',
    key `subjectno` (`subjectno`)
)engine = innodb default charset = utf8;
```

3. 插入学生数据

```mysql
-- 插入学生数据
insert into `student` (`studentno`,`loginpwd`,`studentname`,`sex`,`gradeid`,`phone`,`address`,`borndate`,`email`,`identitycard`)
values
(1000,'123456','张伟',0,2,'13800001234','北京朝阳','1980-1-1','text123@qq.com','123456198001011234'),
(1001,'123456','赵强',1,3,'13800002222','广东深圳','1990-1-1','text111@qq.com','123456199001011233');
```

4. 插入年级数据

```mysql
-- 插入年级数据
insert into `grade` (`gradeid`,`gradename`) values(1,'大一'),(2,'大二'),(3,'大三'),(4,'大四'),(5,'预科班');
```

5. 插入科目数据

```mysql
-- 插入科目数据
insert into `subject`(`subjectno`,`subjectname`,`classhour`,`gradeid`)values
(1,'高等数学-1',110,1),
(2,'高等数学-2',110,2),
(3,'高等数学-3',100,3),
(4,'高等数学-4',130,4),
(5,'C语言-1',110,1),
(6,'C语言-2',110,2),
(7,'C语言-3',100,3),
(8,'C语言-4',130,4),
(9,'Java程序设计-1',110,1),
(10,'Java程序设计-2',110,2),
(11,'Java程序设计-3',100,3),
(12,'Java程序设计-4',130,4),
(13,'数据库结构-1',110,1),
(14,'数据库结构-2',110,2),
(15,'数据库结构-3',100,3),
(16,'数据库结构-4',130,4),
(17,'C#基础',130,1);
```



5. 插入成绩数据

```mysql
-- 插入两个学生的成绩数据
INSERT INTO `result`(`studentno`,`subjectno`,`examdate`,`studentresult`)
VALUES
(1000, 1, '2014-11-11 18:00:00', 90),
(1000, 2, '2014-11-12 16:00:00', 71),
(1000, 3, '2014-01-11 09:00:00', 62),
(1000, 4, '2014-05-13 16:00:00', 78),
(1000, 5, '2014-12-11 16:00:00', 91),
(1000, 6, '2014-11-11 16:00:00', 99),
(1000, 7, '2014-09-12 16:00:00', 84),
(1000, 8, '2014-11-11 09:00:00', 75),
(1000, 9, '2012-11-13 16:00:00', 86),
(1000, 10, '2014-11-15 16:00:00', 77),
(1000, 11, '2015-11-22 16:00:00', 67),
(1000, 12, '2017-12-04 16:00:00', 73),
(1000, 13, '2012-11-11 16:00:00', 84),
(1000, 14, '2014-11-12 16:00:00', 89),
(1000, 15, '2013-11-10 16:00:00', 64),
(1000, 16, '2016-10-14 16:00:00', 97),
(1000, 17, '2014-12-14 16:00:00', 71);

(1001, 1, '2011-12-11 16:00:00', 85),
(1001, 2, '2012-10-12 16:00:00', 70),
(1001, 3, '2012-03-11 09:00:00', 68),
(1001, 4, '2012-04-13 16:00:00', 98),
(1001, 5, '2013-12-11 16:00:00', 58),
(1001, 6, '2013-11-11 16:00:00', 95),
(1001, 7, '2013-09-12 16:00:00', 74),
(1001, 8, '2016-11-11 09:00:00', 62),
(1001, 9, '2015-11-13 16:00:00', 91),
(1001, 10, '2014-11-15 16:00:00', 78),
(1001, 11, '2015-11-22 16:00:00', 48),
(1001, 12, '2017-12-04 16:00:00', 78),
(1001, 13, '2012-11-11 16:00:00', 70),
(1001, 14, '2013-11-12 16:00:00', 66),
(1001, 15, '2014-11-10 16:00:00', 88),
(1001, 16, '2015-10-14 16:00:00', 100),
(1001, 17, '2013-12-14 16:00:00', 88);
```

### 4.2 指定查询字段

> 基本语法：SELECT 字段 FROM 表

```mysql
-- 查询全部的学生，SELECT 字段 FROM 表
SELECT * FROM student

 -- 查询指定字段
SELECT `studentno`, `studentname` FROM `student`

-- AS 给字段起别名，不需要加引号
SELECT `studentno` AS 学号, `studentname` AS 姓名 FROM `student`

-- AS 也可以给表起别名
SELECT `studentno` AS 学号, `studentname` AS 姓名 FROM `student` AS s

-- 函数 concat(a, b)
SELECT CONCAT('姓名：', studentname) AS 新名字 FROM `student`
```

> DISTINCT 去重，去除 SELECT 查询出来的结果中重复的数据，只显示一条

```mysql
-- 查询有哪些同学有成绩
SELECT * FROM `result`
SELECT `studentno` FROM `result`
SELECT DISTINCT `studentno` FROM `result` -- 对重复的数据进行去重
```

> 数据库的列（表达式），语法：SELECT 表达式 FROM 表

数据库中的表达式包括：文本值、列、Null、函数、计算表达式、系统变量等

```mysql
SELECT VERSION() -- 查询系统版本（函数）

SELECT 100 * 3 - 1 AS 计算结果 -- 用来计算（表达式）

SELECT @@auto_increment_increment -- 查询自增的步长（变量）

SELECT `studentno`, `studentresult` + 1 AS '提分后' FROM result -- 学生考试成绩 +1分 查看
```

### 4.3 where条件子句

where作用：检索数据中**符合条件**的值，搜索的条件由一个或多个表达式组成，结果为布尔值

> 逻辑运算符

|   运算符    |        语法        |  描述  |
| :---------: | :----------------: | :----: |
|  and 或 &&  | a and b 或 a && b  | 逻辑与 |
| or  或 \|\| | a or b 或 a \|\| b | 逻辑或 |
|  not 或 !   |    not a 或 !a     | 逻辑非 |

```mysql
-- 查询考试成绩在 95~100 之间
SELECT `studentno`, `studentresult` FROM result
WHERE `studentresult` >= 95 AND `studentresult` <= 100

SELECT `studentno`, `studentresult` FROM result
WHERE `studentresult` >= 95 && `studentresult` <= 100

SELECT `studentno`, `studentresult` FROM result
WHERE `studentresult` BETWEEN 95 AND 100

-- 查询学号不为 1000 的学生
SELECT `studentno`, `studentresult` FROM result
WHERE `studentno` != 1000

SELECT `studentno`, `studentresult` FROM result
WHERE NOT `studentno` = 1000
```

> **模糊查询**：比较运算符

|   运算符    |        用法         |                     描述                      |
| :---------: | :-----------------: | :-------------------------------------------: |
|   is null   |      a is null      |             如果a为null，结果为真             |
| is not null |    a is not null    |            如果a不为null，结果为真            |
|   between   |  a between b and c  |           如果a在b和c之间，结果为真           |
|  **like**   |      a like b       |        SQL匹配，如果a匹配到b，结果为真        |
|   **in**    | a in a1, a2, a3,... | 如果a在a1, a2, a3,...其中的某一个中，结果为真 |

- **like（正则表达式） 结合 % 代表0到任意个字符，_ 代表一个字符 **

```mysql
-- 查询姓赵的同学
SELECT `studentno`, `studentname` FROM student
WHERE `studentname` LIKE '赵%' -- 能查出来“赵某”，“赵某某”等等

-- 查询姓张的同学
SELECT `studentno`, `studentname` FROM student
WHERE `studentname` LIKE '张_' -- 能查出来“张某”

SELECT `studentno`, `studentname` FROM student
WHERE `studentname` LIKE '张_' -- 能查出来“张某某”

-- 查询名字中间有“嘉”字的同学
SELECT `studentno`, `studentname` FROM student
WHERE `studentname` LIKE '%嘉%'
```

- **in**

```mysql
-- 查询 1000，1001 号学生
SELECT `studentno`, `studentname` FROM student
WHERE `studentno` IN (1000, 1001)

-- 查询地址为北京朝阳的学生 注意：不能使用类似 %北京 这样模糊匹配，in是精确查询，正则表达式匹配只有在like中使用
SELECT `studentno`, `studentname` FROM student
WHERE `address` IN ('北京朝阳')
```

- **null,  not null**

```mysql
-- 查询地址为空的学生 null 或 ''
SELECT `studentno`, `studentname` FROM student
WHERE `address` = ''OR `address` IS NULL

-- 查询出生日期不为空的学生
SELECT `studentno`, `studentname` FROM student
WHERE `borndate` IS NOT NULL
```

### 4.4 联表查询

#### 4.4.1 联表查询 join on

|    操作    |                    描述                    |
| :--------: | :----------------------------------------: |
| inner join |      如果表中至少有一个匹配，就返回行      |
| left join  | 会从左表中返回所有的值，即使右表中没有匹配 |
| right join | 会从右表中返回所有的值，即使左表中没有匹配 |

```mysql
-- join （连接的表） on （判断条件）   连接查询
-- where                           等值查询
-- join on 是固定语法，但是 on 与 where 效果是一样的


-- 查询参加了考试的同学（学号、姓名、科目编号、分数）

/*
思路： 
	1，分析查询的字段来自哪些表
	2. 确定使用哪种连接查询
	3. 确定交叉点（两个表中的哪个数据是相同的）
*/

-- INNER JOIN
SELECT s.`studentno`, `studentname`, `subjectno`, `studentresult`
FROM student AS s
INNER JOIN result AS r
ON s.`studentno` = r.`studentno`

-- RIGHT JOIN
SELECT s.`studentno`, `studentname`, `subjectno`, `studentresult`
FROM student s -- AS 可以省略
RIGHT JOIN result r
ON s.`studentno` = r.`studentno`

-- LEFT JOIN
SELECT s.`studentno`, `studentname`, `subjectno`, `studentresult`
FROM student AS s
LEFT JOIN result AS l
ON s.`studentno` = l.`studentno`
```

插入一个缺考的同学

```mysql
-- 插入一个缺考的同学，即只增加 student 表，不改变 result 表
INSERT INTO `school`.`student` (`studentno`, `loginpwd`, `studentname`, `sex`, `gradeid`, `phone`, `address`, `borndate`, `email`, `identitycard`) VALUES ('1002', '123456', 'sun', '1', '3', '44545454545', '山东济南', '2023-12-05 23:14:09', 'ysf@qq.com', '323131231133123123')
```

查询刚插入的缺考同学

```mysql
-- 查询缺考的同学
SELECT s.`studentno`, `studentname`, `subjectno`, `studentresult`
FROM student s
LEFT JOIN result l
ON s.`studentno` = l.`studentno`
WHERE l.`studentresult` IS NULL
```

> **思考题**

涉及超过两张表的查询，先查询两张表再慢慢增加

```mysql
-- 查询参加了考试的同学信息：学号、姓名、科目名、分数
SELECT s.`studentno`, `studentname`, `subjectname`, `studentresult`
FROM student s
RIGHT JOIN result r
ON s.`studentno` = r.`studentno`
INNER JOIN `subject` sub
ON r.`subjectno` = sub.`subjectno`
```

#### 4.4.2 自连接（了解）

思路：将一张表拆为两张一样的表

数据准备

```mysql
CREATE TABLE `category`(
 `categoryid` INT(10) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT '主题id',
 `pid` INT(10) NOT NULL COMMENT '父id',
 `categoryname` VARCHAR(50) NOT NULL COMMENT '主题名字',
PRIMARY KEY (`categoryid`) 
 ) ENGINE=INNODB  AUTO_INCREMENT=9 DEFAULT CHARSET=utf8; 

INSERT INTO `category` (`categoryid`, `pid`, `categoryname`) 
VALUES ('2','1','信息技术'),
('3','1','软件开发'),
('5','1','美术设计'),
('4','3','数据库'),
('8','2','办公信息'),
('6','3','web开发'),
('7','5','ps技术');
```

父类

| categoryid | categoryname |
| :--------: | :----------: |
|     2      |   信息技术   |
|     3      |   软件开发   |
|     5      |   美术设计   |

子类

| pid  | categoryid | categoryname |
| :--: | :--------: | :----------: |
|  3   |     4      |    数据库    |
|  2   |     8      |   办公信息   |
|  3   |     6      |   web开发    |
|  5   |     6      |    ps技术    |

操作：查询父类对应的子类关系

|   父类   |   子类   |
| :------: | :------: |
| 信息技术 | 办公信息 |
| 软件开发 |  数据库  |
| 软件开发 | web开发  |
| 美术设计 |  ps技术  |

```mysql
-- 查询父子信息：把一张表看成两张一模一样的表
SELECT a.`categoryname` AS '父栏目', b.`categoryname` AS '子栏目'
FROM `category` AS a, `category` AS b
WHERE a.`categoryid` = b.`pid`
```

#### 4.4.3 练习

1. 查询学生所属的年级：学号、姓名、年级名称

```mysql
SELECT s.`studentno`, s.`studentname`, g.`gradename`
FROM `student` AS s
INNER JOIN `grade` AS g
ON s.`gradeid` = g.`gradeid`
```

2. 查询科目所属的年级：科目名称，年级名称

```mysql
SELECT `subjectname`, `gradename`
FROM `grade` AS g
INNER JOIN `subject` AS s
ON g.`gradeid` = s.`gradeid`
```

3. 查询参加了《数据库结构》考试的同学的信息：学号，姓名，科目名称，分数

```mysql
SELECT s.`studentno`, s.`studentname`, sub.`subjectname`, res.`studentresult`
FROM `student` AS s
INNER JOIN `subject` AS sub
ON s.`gradeid` = sub.`gradeid`
INNER JOIN `result` AS res
ON sub.`subjectno` = res.`subjectno`
WHERE sub.`subjectname` LIKE '数据库结构-_'
```

### 4.5 排序和分页

#### 4.5.1 排序

> -- 升序 ASC   降序 DESC
> -- ORDER BY 字段：表示根据哪个字段排序

例：查询参加了《数据库结构》考试的同学的信息：学号，姓名，科目名称，分数。查询结果按降序排序

```mysql
SELECT s.`studentno`, s.`studentname`, sub.`subjectname`, res.`studentresult`
FROM `student` AS s
INNER JOIN `subject` AS sub
ON s.`gradeid` = sub.`gradeid`
INNER JOIN `result` AS res
ON sub.`subjectno` = res.`subjectno`
WHERE sub.`subjectname` LIKE '数据库结构-_'
ORDER BY res.`studentresult` DESC
```

#### 4.5.2 分页

分页可以缓解数据库压力，带来刚好的用户体验。 不分页的情况如图片采用瀑布流处理（抖音等）

> 语法：limit 起始值，页面的大小

```mysql
-- 第一页：limit 0, 5
-- 第二页：limit 5, 5
-- 第n页：limit (n - 1) * 5, 5

SELECT s.`studentno`, s.`studentname`, sub.`subjectname`, res.`studentresult`
FROM `student` AS s
INNER JOIN `subject` AS sub
ON s.`gradeid` = sub.`gradeid`
INNER JOIN `result` AS res
ON sub.`subjectno` = res.`subjectno`
WHERE sub.`subjectname` LIKE '数据库结构-_'
ORDER BY res.`studentresult` DESC
LIMIT 0, 5
```

#### 4.5.3 练习

1. 查询 《Java程序设计-1》课程成绩排名前十，并且分数要大于80的学生信息：学号，姓名，课程名称，分数

```mysql
SELECT s.`studentno`, s.`studentname`, sub.`subjectname`, r.`studentresult`
FROM `student` s
INNER JOIN `result` r
ON s.`studentno` = r.`studentno`
INNER JOIN `subject` sub
ON sub.`subjectno` = r.`subjectno`
WHERE subjectname = 'Java程序设计-1' AND studentresult > 80
ORDER BY r.`studentresult` DESC
LIMIT 0, 10
```

### 4.6 子查询

> 本质：在 where 中嵌套子查询语句，==速度比联表更快==

例：

1.  查询《数据库结构-1》的所有考试成绩降序排列：学号、科目编号、成绩

方式一：联表查询

```mysql
SELECT r.`studentno`, sub.`subjectno`, `studentresult`
FROM `result` r
INNER JOIN `subject` sub
ON sub.`subjectno` = r.`subjectno`
WHERE sub.`subjectname` = '数据库结构-1'
ORDER BY `studentresult` DESC
```

方式二：子查询（由里及外）

```mysql
SELECT `studentno`, `subjectno`, `studentresult`
FROM `result` 
WHERE `subjectno` = (
	SELECT `subjectno` FROM `subject`
	WHERE `subjectname` = '数据库结构-1'
)
ORDER BY `studentresult` DESC
```

2. 查询《高等数学-2》分数不少于70的学生信息：学号，姓名

方式一：联表查询

```mysql
SELECT s.`studentno`, s.`studentname`
FROM `student` s
INNER JOIN `result` r
ON s.`studentno` = r.`studentno`
INNER JOIN `subject` sub
ON sub.`subjectno` = r.`subjectno`
WHERE sub.`subjectname` = '高等数学-2' AND r.`studentresult` >= 70
```

方式二：子查询（由里及外）

```mysql
SELECT DISTINCT s.`studentno`, `studentname`
FROM `student` s
INNER JOIN `result` r
ON s.`studentno` = r.`studentno`
WHERE r.`studentresult` >= 70 AND r.`subjectno` = (
	SELECT `subjectno` FROM `subject` 
	WHERE `subjectname` = '高等数学-2'
)
```

方式三：进一步由里及外

```mysql
SELECT `studentno`, `studentname` FROM `student` WHERE`studentno` IN (
	SELECT `studentno` FROM `result` WHERE `studentresult` >= 70 AND `subjectno` = (
		SELECT `subjectno` FROM `subject` WHERE `subjectname` = '高等数学-2'
	)
)
```

### 4.7 分组和过滤

> group by + having

例：查询不同课程的得分情况：科目名称，平均分（大于80的），最高分，最低分。

```mysql
SELECT `subjectname`, AVG(`studentresult`), MAX(`studentresult`), MIN(`studentresult`)
FROM `result` r
INNER JOIN `subject` sub
ON sub.`subjectno` = r.`subjectno`
GROUP BY r.`subjectno` -- 通过什么字段来分组
HAVING AVG(`studentresult`) > 80
```

**核心：**

- **根据不同的课程分组**
- **分组后再进行条件筛选不能用 where，要用 having**

## 5. MySQL函数

[官网](https://www.mysqlzh.com/doc/113.html)

### 5.1 常用函数

1. 数学运算

```mysql
SELECT ABS(-8) -- 绝对值
SELECT CEILING(9.4) -- 向上取整
SELECT FLOOR(9.4) -- 向下取整
SELECT RAND() -- 返回一个 0~1 之间的随机数
SELECT SIGN(10) -- 判断一个数的符号 0→0，负数→-1，正数→1
```

2. 字符串函数

```mysql
SELECT CHAR_LENGTH('即使在小的帆也能远航') -- 字符串长度
SELECT CONCAT('我', '爱', '你们') -- 拼接字符串
SELECT INSERT('我爱编程helloworld', 1, 2, '超级热爱') -- 从某个位置开始替换某个长度的字符串
SELECT LOWER('aBcD') -- 小写字母
SELECT UPPER('abcd') -- 大写字母
SELECT INSTR('sun1f', '1') -- 返回第一次出现的子串的索引
SELECT REPLACE('坚持就能成功', '坚持', '努力') -- 替换出现的指定字符串
SELECT SUBSTR('坚持就能成功', 4, 6) -- 返回指定的字符串（原字符串，截取的位置，截取的长度）
SELECT REVERSE('你是年少的欢喜') -- 反转

-- 查询赵姓同学的名字并将其替换成邹姓
SELECT REPLACE(`studentname`, '赵', '邹') FROM `student`
WHERE `studentname` LIKE '赵%'
```

3. 时间和日期函数（记住）

```mysql
SELECT CURRENT_DATE() -- 当前日期
SELECT CURDATE() -- 当前日期
SELECT NOW() -- 当前时间
SELECT LOCALTIME() -- 本地时间
SELECT SYSDATE() -- 系统时间

SELECT YEAR(NOW())
SELECT MONTH(NOW())
SELECT DAY(NOW())
SELECT HOUR(NOW())
SELECT MINUTE(NOW())
SELECT SECOND(NOW())
```

4. 系统

```mysql
SELECT SYSTEM_USER()
SELECT USER()
SELECT VERSION()
```

### 5.2 聚合函数（常用）

| 函数名称 |  作用  |
| :------: | :----: |
| count()  |  计数  |
|  sum()   |  求和  |
|  avg()   | 平均值 |
|  max()   | 最大值 |
|  min()   | 最小值 |

```mysql
SELECT COUNT(`borndate`) FROM `student` -- count(字段)，会忽略所有的null值
SELECT COUNT(*) FROM `result` -- count(*)，不会忽略null值，本质是计算行数
SELECT COUNT(1) FROM `result` -- count(1)，不会忽略null值，本质也是计算行数

SELECT SUM(`studentresult`) FROM `result`
SELECT AVG(`studentresult`) FROM `result`
SELECT MAX(`studentresult`) FROM `result`
SELECT MIN(`studentresult`) FROM `result`
```

### 5.3 数据库级别的MD5加密（扩展）

什么是md5：

- 增强算法的复杂度与不可逆性
- md5不可逆，相同的值的md5是一样的

```mysql
============================ 数据准备 ============================
CREATE TABLE `testmd5` (
	`id` INT(4) NOT NULL,
	`name` VARCHAR(20) NOT NULL,
	`pwd` VARCHAR(50) NOT NULL,
	PRIMARY KEY(`id`)
)ENGINE=INNODB DEFAULT CHARSET=utf8

============================== 测试 ==============================
-- 明文密码
INSERT INTO `testmd5` VALUES (1, 'sun1f', '1234'), (2, 'sun2f', '1243'), (3, 'sun3f', '1254')

-- 加密 id = 1 的密码
UPDATE `testmd5` SET `pwd` = MD5(pwd) WHERE `id` = 1
 -- 加密全部密码
UPDATE `testmd5` SET `pwd` = MD5(pwd)

-- 插入时直接加密
INSERT INTO `testmd5` VALUES (4, 'sun4f', MD5('1423'))

-- 如何校验：将用户传递进来的密码进行md5加密，然后比对加密后的值
SELECT * FROM `testmd5` WHERE `name` = 'sun4f' AND `pwd` = MD5('1423')
```

## 6. 事务

### 6.1 事务的ACID原则

> 事务原则：ACID，即原子性，一致性，隔离性，持久性 （脏读，幻读...）

- **原子性（Atomicity）**

​		要么都成功，要么都失败

- **一致性（Consistency）**

​		事务前后的数据完整性要保证一致

- **隔离性（Isolation）**

  多个用户并发访问数据库时，数据库为每一个用户开启的事务，不能被其他事务所干扰，事务之间要相互隔离

  所导致的一些问题：

  - 脏读：指一个事务读取了另外一个事务未提交的数据
  - 不可重复读：在一个事务内读取表中的某一行数据，多次读取结果不同（这个不一定是错误，只是某些场合不对）
  - 虚读（幻读）：指在一个事务内读取到了别的事务插入的数据，导致前后读取不一致

- **持久性（Durability）**

​		事务一旦提交则不可逆，被持久化到数据库中

```mysql
-- mysql 是默认开启事务自动提交的
SET autocommit = 0
SET autocommit = 1

-- 手动处理事务
SET autocommit = 0 -- 关闭自动提交

-- 事务开启
START TRANSACTION -- 标记事务的开始，从这个之后 sql 都在同一个事务内

INSERT xx
INSERT xx

-- 提交；持久化（成功）
COMMIT

-- 回滚：回滚到原来的样子（失败）
ROLLBACK

-- 事务结束
SET autocommit = 1 -- 开启自动提交

-- 了解
SAVEPOINT 保存点名 -- 设置一个事物的保存点
ROLLBACK TO SAVEPOINT 保存点名 -- 回滚到保存点
RELEASE SAVEPOINT 保存点名 -- 撤销保存点
```

> 场景模拟：转账

```mysql
-- 数据准备：创建数据库 shop
CREATE DATABASE shop CHARACTER SET utf8 COLLATE utf8_general_ci
USE shop

CREATE TABLE `account` (
	`id` INT(3) NOT NULL AUTO_INCREMENT,
	`name` VARCHAR(30) NOT NULL,
	`money` DECIMAL(9, 2) NOT NULL,
	PRIMARY KEY(`id`)
)ENGINE = INNODB DEFAULT CHARSET = utf8

-- 插入数据
INSERT INTO `account` (`name`, `money`) VALUES ('A', 2000.00), ('B', 10000.00)

SET autocommit = 0 -- 关闭自动提交
START TRANSACTION -- 开启一个事务（一组事务）

UPDATE `account` SET `money` = `money` - 500 WHERE `name` = 'A'
UPDATE `account` SET `money` = `money` + 500 WHERE `name` = 'B'

COMMIT -- 提交事务，被持久化
ROLLBACK -- 回滚

SET autocommit = 1 -- 恢复默认值
```

## 7. 索引

> ==索引（Index）是==帮助MySQL高效获取数据的==数据结构==。

### 7. 1 索引的分类

- 主键索引（primary key）
  - 唯一的标识，主键不可重复，只能有一个列作为主键
- 唯一索引（unique index）
  - 避免重复的列出现，唯一索引可以重复，多个列都可以标识为唯一索引
- 常规索引（key / index）
  - 默认的，通过index  / key 关键字来设置
- 全文索引（FullText）
  - 在特定的数据库引擎下才有，MyISAM
  - 快速定位数据

基础语法：

```mysql
-- 显示所有的索引信息
SHOW INDEX FROM `student`

-- 增加一个全文索引：索引名（字段名）
ALTER TABLE `school`.`student` ADD FULLTEXT INDEX `studentname`(`studentname`)

-- explain 分析 sql 的执行状况

EXPLAIN SELECT * FROM `student` -- 非全文索引

EXPLAIN SELECT * FROM `student` WHERE MATCH(`studentname`) AGAINST('赵')
```

### 7.2 测试索引

数据准备：

- 创建表 app_user

```mysql
CREATE TABLE `app_user` (
`id` BIGINT(20) UNSIGNED NOT NULL AUTO_INCREMENT,
`name` VARCHAR(50) DEFAULT '',
`eamil` VARCHAR(50) NOT NULL,
`phone` VARCHAR(20) DEFAULT '',
`gender` TINYINT(4) UNSIGNED DEFAULT '0',
`password` VARCHAR(100) NOT NULL DEFAULT '',
`age` TINYINT(4) DEFAULT NULL,
`create_time` DATETIME DEFAULT CURRENT_TIMESTAMP,
`update_time` TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
PRIMARY KEY (`id`)
) ENGINE=INNODB DEFAULT CHARSET=utf8
```

- 插入100万条数据（不需要掌握）

```mysql
DELIMITER $$
CREATE FUNCTION mock_data()
RETURNS INT
BEGIN
	DECLARE num INT DEFAULT 1000000;
	DECLARE i INT DEFAULT 0;
	WHILE i < num DO
		INSERT INTO `app_user`(`name``eamil``phone``gender``password``age`)
		VALUES(CONCAT('用户', i), 'sun1f@foxmail.com',
		CONCAT('18', FLOOR(RAND() * ((999999999 - 100000000) + 100000000))),
		FLOOR(RAND() * 2), UUID(), FLOOR(RAND() * 100))
		SET i = i + 1；
	END WHILE;
	RETURN i;
END;
SELECT mock_data();
```

测试：

```mysql
SELECT * FROM app_user WHERE `name` = '用户9999'; -- 1,098s
EXPLAIN SELECT * FROM app_user WHERE `name` = '用户9999';

-- 添加索引：create index 索引名 on 表(字段名)
CREATE INDEX id_app_user_name ON app_user(`name`); 

SELECT * FROM app_user WHERE `name` = '用户9999'; -- 0.001s
EXPLAIN SELECT * FROM app_user WHERE `name` = '用户9999';
```

![1702953051219](E:\wechatfile\WeChat Files\wxid_7fcpz51fwzpt22\FileStorage\Temp\1702953051219.png)

==索引在小数据量的时候用处不大，在大数据量的时候作用十分明显==

### 7.3 索引原则

- 索引不是越多越好
- 不要对经常变动的数据加索引
- 小数据量的表不需要加索引
- 索引一般加载常用来查询的字段上

索引的数据结构推荐阅读：[CodingLabs - MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)

## 8. 权限管理和备份

### 8.1 用户管理

```mysql
-- 创建用户：create user 用户名 identified by 密码
CREATE USER sun1f IDENTIFIED BY '123456'

-- 修改当前用户密码
SET PASSWORD = PASSWORD('111111')

-- 修改指定用户密码
SET PASSWORD FOR sun1f = PASSWORD('111111')

-- 重命名 rename user 原名字 to 新名字
RENAME USER sun1f AS sun2f

-- 用户授权：grant 权限 on 数据库（表） to 用户
-- all privileges是授予其全部的权限（除了给别人授权的功能，只有root有），*.*表示所有库的所有表
GRANT ALL PRIVILEGES ON *.* TO sun2f

-- 查看指定用户的权限
SHOW GRANTS FOR sun2f 
SHOW GRANTS FOR root@localhost

-- 撤销权限：revoke 权限 on 数据库（表） from 用户
REVOKE ALL PRIVILEGES ON *.* FROM sun2f

-- 删除用户：drop user 用户
DROP USER sun2f
```

### 8.2 MySQL备份

为什么要备份：

- 保证重要数据不丢失
- 数据转移

MySQL数据库备份的方式：

- 直接拷贝物理文件

- 在Sqlyog可视化工具中手动导出

- 使用命令行导出 mysqldump命令

  ```bash
  # mysqldump -h主机 -u用户名 -p密码 数据库 表名 > 物理磁盘位置:/文件名
  mysqldump -hlocalhost -uroot -p12345678 school student > D:/a.sql
  
  # mysqldump -h主机 -u用户名 -p密码 数据库 表名1 表名2 表名3 > 物理磁盘位置:/文件名
  mysqldump -hlocalhost -uroot -p12345678 school result subject > D:/b.sql
  
  # mysqldump -h主机 -u用户名 -p密码 数据库 > 物理磁盘位置:/文件名
  mysqldump -hlocalhost -uroot -p12345678 school > D:/c.sql
  
  # 导入：source 备份文件
  source D:/a.sql
  
  # 登录的情况下，切换到指定的数据库
  mysql -u用户名 -p密码 库名 < 备份文件
  ```

## 9. 规范数据库设计



## 10. JDBC（重点）

### 10.1 数据库驱动

数据库同声卡、显卡一样也需要驱动，Java程序通过数据库驱动和数据库打交道

![1702959032303](E:\wechatfile\WeChat Files\wxid_7fcpz51fwzpt22\FileStorage\Temp\1702959032303.png)

### 10.2 JDBC

SUN 公司为了简化开发人员的（对数据库的统一）操作，提供了一个（Java操作数据库的）规范，俗称 JDBC，这些规范的实现由具体厂商去做，对于开发人员来说，只需要掌握 JDBC 接口的操作即可

![1702959407593](E:\wechatfile\WeChat Files\wxid_7fcpz51fwzpt22\FileStorage\Temp\1702959407593.png)

### 10.3 第一个JDBC程序

1. 创建测试数据库 `jdbcStudy`

```mysql
CREATE DATABASE `jdbcStudy` CHARACTER SET utf8 COLLATE utf8_general_ci;

USE `jdbcStudy`;

CREATE TABLE `users`(
 `id` INT PRIMARY KEY,
 `NAME` VARCHAR(40),
 `PASSWORD` VARCHAR(40),
 `email` VARCHAR(60),
 birthday DATE
);

 INSERT INTO `users`(`id`,`NAME`,`PASSWORD`,`email`,`birthday`)
VALUES(1,'zhangsan','123456','zs@sina.com','1980-12-04'),
(2,'lisi','123456','lisi@sina.com','1981-12-04'),
(3,'wangwu','123456','wangwu@sina.com','1979-12-04')
```

2. 创建一个普通项目并导入数据库驱动 `mysql-connector-java-5.1.47.jar`

   ![1702969958613](E:\wechatfile\WeChat Files\wxid_7fcpz51fwzpt22\FileStorage\Temp\1702969958613.png)

3. 编写测试代码

```java
package com.sun1f.lesson1;

import java.sql.*;

public class jdbc_demo1 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        // 1. 加载驱动（固定写法）
        Class.forName("com.mysql.jdbc.Driver");

        // 2. 用户信息和url
        // useUnicode=true 支持中文编码
        // characterEncoding=utf8 设置中文字符集为utf8
        // useSSL 使用安全连接
        String url = "jdbc:mysql://localhost:3306/jdbcstudy?useUnicode=true&characterEncoding=utf8&useSSL=true";
        String username = "root";
        String password = "12345678";

        // 3. 连接成功，返回数据库对象。connection就代表数据库
        Connection connection = DriverManager.getConnection(url, username, password);

        // 4. 执行SQL的对象 statement 执行sql的对象
        Statement statement = connection.createStatement();

        // 5. 执行SQL的对象 去执行sql，可能存在结果，查看返回结果
        String sql = "SELECT * FROM users";

        ResultSet resultSet = statement.executeQuery(sql); // 结果集中封装了全部查询出来的结果

        while(resultSet.next()) {
            System.out.println("id = " + resultSet.getObject("id"));
            System.out.println("name = " + resultSet.getObject("NAME"));
            System.out.println("pwd = " + resultSet.getObject("PASSWORD"));
            System.out.println("email = " + resultSet.getObject("email"));
            System.out.println("birth = " + resultSet.getObject("birthday"));
        }

        // 6. 释放连接
        resultSet.close();
        statement.close();
        connection.close();
    }
}
```

**步骤总结：**

1. 加载驱动
2. 连接数据库 DriverManager
3. 获取执行sql的对象 Statement
4. 获取返回的结果集
5. 释放连接

**详细解释：**

`DriverManager`

```java
 // DriverManager.registerDriver(new com.mysql.jdbc.Driver());
 Class.forName("com.mysql.jdbc.Driver"); // 固定写法，加载驱动
Connection connection = DriverManager.getConnection(url, username, password);

// connection 代表数据库，可以做数据库层面的所有操作，如数据库设置自动提交，事务提交，事务回滚等
connection.commit();
connection.rollback();
connection.setAutoCommit();
```

`URL`

```java
String url = "jdbc:mysql://localhost:3306/jdbcstudy?useUnicode=true&characterEncoding=utf8&useSSL=true";

// 写法：协议://主机地址:端口号/数据库名?参数1&参数2&参数3

// mysql    ->   jdbc:mysql://localhost:3306
// oracle   ->   jdbc:oracle:thin:@localhost:1521:sid
```

`Statement / PrepareStatement 执行SQL的对象`

```java
String sql = "SELECT * FROM users"; // 编写SQL

statement.executeQuery(sql); // 查询操作返回 ResultSet
statement.execute(sql); // 执行任何SQL
statement.executeUpdate(sql); // 更新、插入、删除都用这个方法，返回受影响的行数
```

`ResultSet`

- 获取指定的数据类型

  ```java
  resultSet.getObject(xxx); // 不知道字段类型的情况下使用，xxx为字段
  // 如果知道字段的类型就使用指定的类型
  resultSet.getString(xxx);
  resultSet.getInt(xxx);
  resultSet.getFloat(xxx);
  resultSet.getDate(xxx);
  ```

- 通过指针遍历

  ```java
  resultSet.beforeFirst(); // 移动到最前面
  resultSet.afterLast(); // 移动到最后面
  resultSet.next(); // 移动到下一个数据
  resultSet.previous(); // 移动到前一行
  resultSet.absolute(row); // 移动到指定行（第row行）
  ```

`close`

```java
// 释放连接
resultSet.close();
statement.close();
connection.close(); // 很耗资源，用完必须关掉
```

### 10.4 Statement对象

==jdbc中的statement对象用于向数据库发送SQL语句。想完成对数据库的增删改查，只需通过这个对象向数据库发送增删改查的SQL语句即可。==

statement对象的executeUpdate方法，用于向数据库发送增、删、改的SQL语句，executeUpdate执行完后，返回一个整数（即增删改语句导致了数据库多少行数据发生了变化）。

statement.executeQuery方法用于向数据库发送查询语句，executeQuery方法返回代表查询结果的ResultSet对象。

**CRUD 操作：**

- create：使用executeUpdate(String sql)方法完成数据添加操作

  ```java
  statement st = conn.createStatement();
  String sql = "insert into user (...) values (...)";
  int num = st.executeUpdate(sql);
  if(num > 0) {
      System.out.println("插入成功！");
  }
  ```

- delete：使用executeUpdate(String sql)方法完成对数据库的删除操作

  ```java
  statement st = conn.createStatement();
  String sql = "delete from user where id = 1";
  int num = st.executeUpdate(sql);
  if(num > 0) {
      System.out.println("删除成功！");
  }
  ```

- update：使用executeUpdate(String sql)方法完成数据修改操作

  ```java
  statement st = conn.createStatement();
  String sql = "update user set name = '' where name = ''";
  int num = st.executeUpdate(sql);
  if(num > 0) {
      System.out.println("修改成功！");
  }
  ```

- read：使用executeQuery(String sql)方法完成对数据库的查询操作

  ```java
  statement st = conn.createStatement();
  String sql = "select * from user where id = 1";
  int num = st.executeQuery(sql);
  if(rs.next()) {
      // 根据获取列的数据类型，分别调用rs的相应方法映射到java对象中
  }
  ```

**代码实现：**

1. 提取工具类

   ```java
   package com.sun1f.lesson2.utils;
   
   import java.io.IOException;
   import java.io.InputStream;
   import java.sql.*;
   import java.util.Properties;
   
   public class jdbcUtils {
   
       private static String driver = null;
       private static String url = null;
       private static String username = null;
       private static String password = null;
   
       static {
           try {
               InputStream in = jdbcUtils.class.getClassLoader().getResourceAsStream("db.properties");
               Properties properties = new Properties();
               properties.load(in);
   
               driver = properties.getProperty("driver");
               url = properties.getProperty("url");
               username = properties.getProperty("username");
               password = properties.getProperty("password");
   
               // 1. 驱动只需加载一次
               Class.forName(driver);
           } catch (IOException e) {
               throw new RuntimeException(e);
           } catch (ClassNotFoundException e) {
               throw new RuntimeException(e);
           }
       }
       // 2. 获取连接
       public static Connection getConnection() throws SQLException {
           return DriverManager.getConnection(url, username, password);
       }
   
       // 3. 释放资源
       public static void release(Connection conn, Statement st, ResultSet rs) {
           if(rs != null) {
               try {
                   rs.close();
               } catch (SQLException e) {
                   throw new RuntimeException(e);
               }
           }
           if(st != null) {
               try {
                   st.close();
               } catch (SQLException e) {
                   throw new RuntimeException(e);
               }
           }
           if(conn != null) {
               try {
                   conn.close();
               } catch (SQLException e) {
                   throw new RuntimeException(e);
               }
           }
       }
   }
   ```

2. 编写增、删、改的方法：`executeUpdate`

   - 增

     ```java
     package com.sun1f.lesson2.utils;
     
     import java.sql.Connection;
     import java.sql.ResultSet;
     import java.sql.SQLException;
     import java.sql.Statement;
     
     public class TestInsert {
         public static void main(String[] args) {
             Connection conn = null;
             Statement st = null;
             ResultSet rs = null;
     
             try {
                 conn = jdbcUtils.getConnection();
                 st = conn.createStatement();
                 String sql = "INSERT INTO `users`(`id`, `NAME`, `PASSWORD`, `email`, `birthday`)" +
                         "VALUES(4, 'sun1f', '123456', 'sun1f@foxmail.com', '2021-01-23')";
     
                 int i = st.executeUpdate(sql);
                 if(i > 0) {
                     System.out.println("插入成功！");
                 }
     
             } catch (SQLException e) {
                 throw new RuntimeException(e);
             } finally {
                 jdbcUtils.release(conn, st, rs);
             }
         }
     }
     ```

   - 删

     ```java
     package com.sun1f.lesson2.utils;
     
     import java.sql.Connection;
     import java.sql.ResultSet;
     import java.sql.SQLException;
     import java.sql.Statement;
     
     public class TestDelete {
         public static void main(String[] args) {
             Connection conn = null;
             Statement st = null;
             ResultSet rs = null;
     
             try {
                 conn = jdbcUtils.getConnection();
                 st = conn.createStatement();
                 String sql = "DELETE FROM `users` WHERE `id` = 4";
     
                 int i = st.executeUpdate(sql);
                 if(i > 0) {
                     System.out.println("删除成功！");
                 }
     
             } catch (SQLException e) {
                 throw new RuntimeException(e);
             } finally {
                 jdbcUtils.release(conn, st, rs);
             }
         }
     }
     ```

   - 改

     ```java
     package com.sun1f.lesson2.utils;
     
     import java.sql.Connection;
     import java.sql.ResultSet;
     import java.sql.SQLException;
     import java.sql.Statement;
     
     public class TestUpdate {
         public static void main(String[] args) {
             Connection conn = null;
             Statement st = null;
             ResultSet rs = null;
     
             try {
                 conn = jdbcUtils.getConnection();
                 st = conn.createStatement();
                 String sql = "UPDATE `users` SET `NAME` = 'zhaosi', `PASSWORD` = '1234', " +
                         "`email` = 'zhaosi@sina.com', `birthday` = '1992-12-21' WHERE `id` = 3";
     
                 int i = st.executeUpdate(sql);
                 if(i > 0) {
                     System.out.println("修改成功！");
                 }
     
             } catch (SQLException e) {
                 throw new RuntimeException(e);
             } finally {
                 jdbcUtils.release(conn, st, rs);
             }
         }
     }
     ```

3. 查询代码：`executeQuery`

   ```java
   package com.sun1f.lesson2.utils;
   
   import java.sql.Connection;
   import java.sql.ResultSet;
   import java.sql.SQLException;
   import java.sql.Statement;
   
   public class TestSelect {
       public static void main(String[] args) {
           Connection conn = null; // 由于最后要释放，所以不能写在try里面，单独提到外面
           Statement st = null;
           ResultSet rs = null;
   
           try {
               conn = jdbcUtils.getConnection();
               st = conn.createStatement();
   
               // SQL
               String sql = "select * from users where id = 1";
               rs = st.executeQuery(sql);
   
               while(rs.next()) {
                   System.out.println("Name: " + rs.getString("NAME"));
                   System.out.println("PASSWORD: " + rs.getString("PASSWORD"));
               }
           } catch (SQLException e) {
               throw new RuntimeException(e);
           } finally {
               jdbcUtils.release(conn, st, rs);
           }
       }
   }
   ```


**SQL注入：**

- SQL存在漏洞，会被攻击导致数据泄露。主要原因是在拼接时，`or`的作用

  ```java
  package com.sun1f.lesson2.utils;
  
  import java.sql.Connection;
  import java.sql.ResultSet;
  import java.sql.SQLException;
  import java.sql.Statement;
  
  public class SQL_injection {
      public static void main(String[] args) {
          // login("zhaosi", "1234");
          login(" ' or '1 = 1", " ' or '1 = 1");
      }
  
      // 登录业务
      public static void login(String username, String password) {
          Connection conn = null; // 由于最后要释放，所以不能写在try里面，单独提到外面
          Statement st = null;
          ResultSet rs = null;
  
          try {
              conn = jdbcUtils.getConnection();
              st = conn.createStatement();
  
              // 带入非法的输入：where `NAME` = ' ' or '1 = 1' and `password` = ' ' or '1 = 1' 永远成立
              String sql = "select * from users where `NAME` = '"+ username + "' and `password` = '"+ password + "'";
              rs = st.executeQuery(sql);
  
  
              while(rs.next()) {
                  System.out.println("Name: " + rs.getString("NAME"));
                  System.out.println("PASSWORD: " + rs.getString("PASSWORD"));
                  System.out.println("birthday: " + rs.getDate("birthday"));
              }
          } catch (SQLException e) {
              throw new RuntimeException(e);
          } finally {
              jdbcUtils.release(conn, st, rs);
          }
      }
  }
  ```

  

### 10.5 PreparedStatement对象

PreparedStatement 可以防止SQL注入，效率更高

- 增

  ```java
  package com.sun1f.lesson3;
  
  import java.sql.Connection;
  import java.sql.PreparedStatement;
  import java.sql.SQLException;
  import java.util.Date;
  
  import com.sun1f.utils.*;
  
  public class TestInsert {
      public static void main(String[] args) {
          Connection conn = null;
          PreparedStatement st = null;
  
          try {
              conn = jdbcUtils.getConnection();
  
              // 和 Statement的区别
              // 1. 使用 ? 占位符代替参数
              String sql = "insert into users(id, `name`, `password`, `email`, `birthday`) values(?, ?, ?, ?, ?)";
  
              // 2. 预编译SQL：先不执行SQL
              st = conn.prepareStatement(sql);
  
              // 3. 手动给参数赋值，set函数第一个参数表示第几个括号，第二个参数为赋值的内容
              st.setInt(1, 4);
              st.setString(2, "sun1f");
              st.setString(3, "123123");
              st.setString(4, "sun1f@foxmail.com");
              // sql.Date      数据库的日期       java.sql.Date()
              // util.Date     Java的日期        new Date().getTime()获得时间戳
              st.setDate(5, new java.sql.Date(new Date().getTime()));
  
              // 执行
              int num = st.executeUpdate();
              if(num > 0) {
                  System.out.println("插入成功！");
              }
          } catch (SQLException e) {
              throw new RuntimeException(e);
          } finally {
              jdbcUtils.release(conn, st, null);
          }
      }
  }
  ```

- 删

  ```java
  package com.sun1f.lesson3;
  
  import com.sun1f.utils.jdbcUtils;
  
  import java.sql.Connection;
  import java.sql.PreparedStatement;
  import java.sql.SQLException;
  
  public class TestDelete {
      public static void main(String[] args) {
          Connection conn = null;
          PreparedStatement st = null;
  
          try {
              conn = jdbcUtils.getConnection();
  
              // 和 Statement的区别
              // 1. 使用 ? 占位符代替参数
              String sql = "delete from users where `id` = ?";
  
              // 2. 预编译SQL：先不执行SQL
              st = conn.prepareStatement(sql);
  
              // 3. 手动给参数赋值，set函数第一个参数表示第几个括号，第二个参数为赋值的内容
              st.setInt(1, 4);
  
              // 执行
              int num = st.executeUpdate();
              if(num > 0) {
                  System.out.println("删除成功！");
              }
          } catch (SQLException e) {
              throw new RuntimeException(e);
          } finally {
              jdbcUtils.release(conn, st, null);
          }
      }
  }
  ```

- 改

  ```java
  package com.sun1f.lesson3;
  
  import com.sun1f.utils.jdbcUtils;
  
  import java.sql.Connection;
  import java.sql.PreparedStatement;
  import java.sql.SQLException;
  import java.util.Date;
  
  public class TestUpdate {
      public static void main(String[] args) {
          Connection conn = null;
          PreparedStatement st = null;
  
          try {
              conn = jdbcUtils.getConnection();
  
              // 和 Statement的区别
              // 1. 使用 ? 占位符代替参数
              String sql = "update `users` set `name` = ? where `id` = ?";
  
              // 2. 预编译SQL：先不执行SQL
              st = conn.prepareStatement(sql);
  
              // 3. 手动给参数赋值，set函数第一个参数表示第几个括号，第二个参数为赋值的内容
              st.setString(1, "sun2f");
              st.setInt(2, 4);
  
              // 执行
              int num = st.executeUpdate();
              if(num > 0) {
                  System.out.println("更新成功！");
              }
          } catch (SQLException e) {
              throw new RuntimeException(e);
          } finally {
              jdbcUtils.release(conn, st, null);
          }
      }
  }
  ```

- 查

  ```java
  package com.sun1f.lesson3;
  
  import java.sql.Connection;
  import java.sql.PreparedStatement;
  import java.sql.ResultSet;
  import java.sql.SQLException;
  
  import com.sun1f.utils.*;
  
  public class TestSelect {
      public static void main(String[] args) {
          Connection conn = null;
          PreparedStatement st = null;
          ResultSet rs = null;
  
          try {
              conn = jdbcUtils.getConnection();
              String sql = "select `password` from `users` where `id` = ?";
  
              st = conn.prepareStatement(sql);
              st.setInt(1, 4);
  
              rs = st.executeQuery();
  
              while(rs.next()) {
                  System.out.println("password: " + rs.getString("password"));
              }
  
  
          } catch (SQLException e) {
              throw new RuntimeException(e);
          } finally {
              jdbcUtils.release(conn, st, rs);
          }
      }
  }
  ```

- 测试SQL注入

  ```java
  package com.sun1f.lesson3;
  
  import java.sql.Connection;
  import java.sql.PreparedStatement;
  import java.sql.ResultSet;
  import java.sql.SQLException;
  
  import com.sun1f.utils.*;
  
  public class SQL_injection {
      public static void main(String[] args) {
          // login("sun1f", "123123"); // 可以查出来
          login("'' or 1 = 1", "123123"); // 查不出来
      }
  
      public static void login(String username, String password) {
          Connection conn = null;
          PreparedStatement st = null;
          ResultSet rs = null;
  
          try {
              conn = jdbcUtils.getConnection();
  
              // PreparedStatement 防止SQL注入的本质，是把传递进来的参数当做字符
              // 假设其中存在转义字符，比如 ' 会被直接转义
              String sql = "select * from users where `name` = ? and `password` = ?";
              st = conn.prepareStatement(sql);
  
              st.setString(1, username);
              st.setString(2, password);
  
              rs = st.executeQuery();
  
              while(rs.next()) {
                  System.out.println(rs.getString("name"));
                  System.out.println(rs.getString("password"));
              }
  
          } catch (SQLException e) {
              throw new RuntimeException(e);
          } finally {
              jdbcUtils.release(conn, st, rs);
          }
      }
  }
  ```

###  10.6 IDEA连接数据库



### 10.7 事务

ACID原则

**注意事项：**

- 开启事务：`conn.setAutoCommit(false);`
- 一组业务执行完毕，提交事务
- 可以在catch语句中显示定义回滚语句，但没有必要，因为默认失败就会回滚

```java
package com.sun1f.lesson4;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.sun1f.utils.*;

public class TestTransaction2 {
    public static void main(String[] args) {
        Connection conn = null;
        PreparedStatement st = null;
        ResultSet rs = null;

        try {
            conn = jdbcUtils.getConnection();

            // 关闭数据库的自动提交，自动会开启事务（无需手动）
            conn.setAutoCommit(false);

            String sql1 = "update account set money = money - 100 where `name` = 'A'";
            st = conn.prepareStatement(sql1);
            st.executeUpdate();

            // 报错后，之前执行的也会回滚至原来
            int i = 1 / 0;

            String sql2 = "update account set money = money + 100 where `name` = 'B'";
            st = conn.prepareStatement(sql2);
            st.executeUpdate();

            // 业务完毕，提交事务
            conn.commit();
            System.out.println("事务执行成功");

        } catch (SQLException e) {
            try {
                // 不需要手动写回滚
                conn.rollback();
            } catch (SQLException ex) {
                throw new RuntimeException(ex);
            }
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.release(conn, st, rs);
        }
    }
}
```

### 10.8 数据库连接池

DBCP、C3P0、Druid等开源数据源实现





























