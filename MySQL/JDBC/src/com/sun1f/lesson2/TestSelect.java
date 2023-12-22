package com.sun1f.lesson2;

import com.sun1f.utils.jdbcUtils;

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
