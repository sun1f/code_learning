package com.sun1f.lesson2;

import com.sun1f.utils.jdbcUtils;

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
