package com.sun1f.lesson3;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.sun1f.utils.*;

public class TestSelect {
    public static void main(String[] args) {
        Connection conn = null;
        PreparedStatement st = null;
        ResultSet rs = null;

        try {
            conn = jdbcUtils.getConnection();
            String sql = "select `password` from `users` where `id` = ?";

            st = conn.prepareStatement(sql);
            st.setInt(1, 4);

            rs = st.executeQuery();

            while(rs.next()) {
                System.out.println("password: " + rs.getString("password"));
            }


        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.release(conn, st, rs);
        }
    }
}
