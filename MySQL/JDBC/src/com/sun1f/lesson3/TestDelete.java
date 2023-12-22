package com.sun1f.lesson3;

import com.sun1f.utils.jdbcUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class TestDelete {
    public static void main(String[] args) {
        Connection conn = null;
        PreparedStatement st = null;

        try {
            conn = jdbcUtils.getConnection();

            // 和 Statement的区别
            // 1. 使用 ? 占位符代替参数
            String sql = "delete from users where `id` = ?";

            // 2. 预编译SQL：先不执行SQL
            st = conn.prepareStatement(sql);

            // 3. 手动给参数赋值，set函数第一个参数表示第几个括号，第二个参数为赋值的内容
            st.setInt(1, 4);

            // 执行
            int num = st.executeUpdate();
            if(num > 0) {
                System.out.println("删除成功！");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } finally {
            jdbcUtils.release(conn, st, null);
        }
    }
}
