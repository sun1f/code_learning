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
