#  操作数据库

## 2.1 操作数据库表（了解）

## 2.2 数据库列的类型

## 2.3 数据库的字段类型（重点）

## 2.4 创建数据库表（重点）

> 用SQL语句创建在school数据库下创建student数据表

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

> 用下面语句查看创建数据库与表时使用的语句

```mysql
SHOW CREATE DATABASE school -- 查看创建数据库的语句
SHOW CREATE TABLE student -- 查看创建student数据表的定义语句
DESC student -- 查看student表的结构
```



## 2.5 数据表的类型

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

## 2.6 修改删除表

> 修改

```mysql
ALTER TABLE teacher RENAME AS teacher1
```



