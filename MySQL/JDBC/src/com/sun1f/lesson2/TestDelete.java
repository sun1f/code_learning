package com.sun1f.lesson2;

import com.sun1f.utils.jdbcUtils;

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
