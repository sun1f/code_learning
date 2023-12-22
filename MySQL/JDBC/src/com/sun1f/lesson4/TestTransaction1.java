package com.sun1f.lesson4;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.sun1f.utils.*;

public class TestTransaction1 {
    public static void main(String[] args) {
        Connection conn = null;
        PreparedStatement st = null;
        ResultSet rs = null;

        try {
            conn = jdbcUtils.getConnection();

            // 关闭数据库的自动提交，自动会开启事务（无需手动）
            conn.setAutoCommit(false);

            String sql1 = "update account set money = money - 100 where `name` = 'A'";
            st = conn.prepareStatement(sql1);
            st.executeUpdate();

            String sql2 = "update account set money = money + 100 where `name` = 'B'";
            st = conn.prepareStatement(sql2);
            st.executeUpdate();

            // 业务完毕，提交事务
            conn.commit();
            System.out.println("事务执行成功");

        } catch (SQLException e) {
            try {
                // 不需要手动写回滚
                conn.rollback();
            } catch (SQLException ex) {
                throw new RuntimeException(ex);
            }
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.release(conn, st, rs);
        }
    }
}
