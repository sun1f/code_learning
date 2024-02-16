package com.sun1f.servlet;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.URLEncoder;

public class FileServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //- 获取下载文件的路径
        String realpath = "F:\\yaner\\programming\\learning\\JavaWeb\\javaweb-02-servlet\\response\\target\\classes\\头像.jpg";
        System.out.println("下载文件的路径为: " + realpath);
        //- 获取下载文件的名称 （一般最后一个 / 后面的字符串就是文件名）
        String filename = realpath.substring(realpath.lastIndexOf("\\") + 1);
        //- 设置想办法让浏览器能够支持下载我们需要的东西
        // 下面是下载的固定写法，对于中文文件名，通过URLEncoder.encode编码，否则可能乱码
        // resp.setHeader("Content-Disposition", "attachment;filename=" + filename);
        resp.setHeader("Content-Disposition", "attachment;filename=" + URLEncoder.encode(filename, "UTF-8"));
        //- 获取下载文件的输入流
        FileInputStream fin = new FileInputStream(realpath);
        //- 创建缓冲区
        int len = 0;
        byte[] buffer = new byte[1024];
        //- 获取OutStream对象
        ServletOutputStream sout = resp.getOutputStream();
        //- 将FileInputStream流写入到buffer缓冲区
        //- 使用OutStream将缓冲区中的数据输出到客户端
        while((len = fin.read(buffer)) > 0) {
            sout.write(buffer, 0, len);
        }
        fin.close();
        sout.close();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }
}
