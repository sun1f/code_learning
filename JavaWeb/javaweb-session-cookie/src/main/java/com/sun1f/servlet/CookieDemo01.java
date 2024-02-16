package com.sun1f.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

public class CookieDemo01 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 解决中文乱码
        req.setCharacterEncoding("GBK");
        resp.setCharacterEncoding("GBK");

        PrintWriter out = resp.getWriter();

        // Cookie，服务器端从客户端获取
        Cookie[] cookies = req.getCookies(); // 返回数组，说明cookie可能存在多个

        // 判断cookie是否存在
        if(cookies != null) {
            out.write("您上一次访问本网站的时间是：");
            for(int i = 0; i < cookies.length; ++i) {
                Cookie cookie = cookies[i];
                // 获取cookie的名字
                if(cookie.getName().equals("lastLoginTime")) {
                    // 获取cookie中的值
                    long lastLoginTime = Long.parseLong(cookie.getValue());
                    Date date = new Date(lastLoginTime);
                    out.write(date.toLocaleString());
                }
            }
        }else {
            out.write("这是您第一次访问本网站");
        }
        // 服务端给客户端响应一个cookie
        Cookie cookie = new Cookie("lastLoginTime", System.currentTimeMillis() + "");

        // cookie的有效期设为1天（换算成多少秒）
        cookie.setMaxAge(24 * 60 * 60);

        resp.addCookie(cookie);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }


}
