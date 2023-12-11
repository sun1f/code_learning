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

> SELECT 完整语法

```mysql
SELECT
	[ALL | DISTINCT | DISTINCTROW]
		[HIGH_PRIORITY]
		[STRAIGHT_JOIN]
		[SQL_SMALL_RESULT] [SQL_BIG_RESULT] [SQL_BUFFER_RESULT]
		[SQL_CACHE | SQL_NO_CACHE] [SQL_CALC_FOUND_ROWS]
	select_expr [, select_expr ...]
	[FROM table_references
		[PARTITION partition_list]
	[WHERE where_condition]
	[GROUP BY {col_name | expr | position}
    	[ASC | DESC], ... [WITH ROLLUP]]
	[HAVING where_condition]
	[ORDER BY {col_name | expr | position}
		[ASC | DESC], ...]
    [LIMIT {[offset,] row_count | row_count OFFSET offset}]
    [PROCEDURE procedure_name(argument_list)]
    [INTO OUTFILE 'file_name'
		[CHARACTER SET charset_name]
		export_options
		| INTO DUMPFILE 'file_name'
		| INTO var_name[, var_name]]
    [FOR UPDATE | LOCK IN SHARE MODE]]
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

