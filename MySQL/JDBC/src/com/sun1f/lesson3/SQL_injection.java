package com.sun1f.lesson3;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.sun1f.utils.*;

public class SQL_injection {
    public static void main(String[] args) {
        // login("sun1f", "123123"); // 可以查出来
        login("'' or 1 = 1", "123123"); // 查不出来
    }

    public static void login(String username, String password) {
        Connection conn = null;
        PreparedStatement st = null;
        ResultSet rs = null;

        try {
            conn = jdbcUtils.getConnection();

            // PreparedStatement 防止SQL注入的本质，是把传递进来的参数当做字符
            // 假设其中存在转义字符，比如 ' 会被直接转义
            String sql = "select * from users where `name` = ? and `password` = ?";
            st = conn.prepareStatement(sql);

            st.setString(1, username);
            st.setString(2, password);

            rs = st.executeQuery();

            while(rs.next()) {
                System.out.println(rs.getString("name"));
                System.out.println(rs.getString("password"));
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.release(conn, st, rs);
        }
    }
}
