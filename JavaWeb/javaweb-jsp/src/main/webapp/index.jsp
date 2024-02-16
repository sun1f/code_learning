<%--
  Created by IntelliJ IDEA.
  User: sun
  Date: 2024/2/8
  Time: 17:06
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>

<%--JSP表达式
语法：<%=变量或者表达式%>
作用：用来将程序输出到客户端
--%>
<%= new java.util.Date()%>

<%--JSP脚本片段--%>
<%
    int sum = 0;
    for(int i = 1; i <= 100; ++i) {
        sum += i;
    }
    out.println("<h1>sum = " + sum + "</h1>");
%>

</body>
</html>
