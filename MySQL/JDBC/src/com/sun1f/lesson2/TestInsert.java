package com.sun1f.lesson2;

import com.sun1f.utils.jdbcUtils;

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
