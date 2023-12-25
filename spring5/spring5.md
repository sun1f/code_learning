# 1. Spring

## 1.1 简介

- Spring：春天
- 2002年，首次推出了Spring框架的雏形：interface21框架
- Spring框架以interface21框架为基础，经过重新设计，并不断丰富其内涵，于2004年3月24日发布了1.0正式版
- **Rod Johnson**，Spring Framework的创始人，著名作者，悉尼大学博士，专业不是计算机，而是音乐
- Spring理念：使现有的技术更加容易使用，本身是一个大杂烩，整合了现有的技术框架
- 学习路线：
  - SSH：Struct2 + Spring + Hibernate
  - SSM：SpringMVC + Spring + Mybatis

[官网](https://spring.io/projects/spring-framework#overview)

[官方下载地址](https://repo1.maven.org/maven2/org/springframework/spring/)

## 1.2 优点

- Spring是一个开源的免费框架（容器）
- Spring是一个轻量级的、非入侵式的框架
- 控制反转（IOC） + 面向切面编程（AOP）
- 支持事务的处理，对框架整合的支持

==总结：Spring是一个轻量级的控制反转（IOC）和面向切面编程（AOP）的框架==

## 1.3 组成

![1702699646562](E:\wechatfile\WeChat Files\wxid_7fcpz51fwzpt22\FileStorage\Temp\1702699646562.png)

## 1.4 拓展

Spring官网介绍：现代化的Java开发，就是基于Spring的开发！

![1702699605679](E:\wechatfile\WeChat Files\wxid_7fcpz51fwzpt22\FileStorage\Temp\1702699605679.png)

- Spring Boot：
  - 一个快速开发的脚手架
  - 基于Spring Boot可以快速开发单个微服务
  - 约定大于配置

- Spring Cloud：
  - Spring Cloud基于Spring Boot实现

现在大多数公司都在使用Spring Boot进行快速开发，学习Spring Boot的前提，==需要完全掌握Spring和SpringMVC==



弊端：发展了太久之后，违背了原来的理念，配置十分繁琐，人称 “配置地狱”

## 2. IOC理论推导

1. UserDao 接口
2. UserDaoImpl 实现类
3. UserService 业务接口
4. UserServiceImpl 业务实现类

