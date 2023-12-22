package com.sun1f.lesson1;

import java.sql.*;

public class jdbc_demo1 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        // 1. 加载驱动（固定写法）
        // DriverManager.registerDriver(new com.mysql.jdbc.Driver());
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
