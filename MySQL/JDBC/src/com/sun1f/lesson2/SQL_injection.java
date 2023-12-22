package com.sun1f.lesson2;

import com.sun1f.utils.jdbcUtils;

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
