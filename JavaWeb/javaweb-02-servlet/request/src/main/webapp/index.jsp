<%--
  Created by IntelliJ IDEA.
  User: sun
  Date: 2024/1/21
  Time: 18:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录</title>
</head>
<body>

<h1>Login</h1>

<div style="text-align: center">
    <%--以post的方式提交到login请求--%>
    <form action="${pageContext.request.contextPath}/login" method="post">
        username: <input type="text" name="username"> <br>
        password: <input type="password" name="password"> <br>
        hobby:
        <input type="checkbox" name="hobby" value="girl"> girl
        <input type="checkbox" name="hobby" value="code"> code
        <input type="checkbox" name="hobby" value="singing"> singing
        <input type="checkbox" name="hobby" value="movie"> movie
        <br>
        <input type="submit">
    </form>
</div>

</body>
</html>
