#shader vertex
#version 330 core

layout(location = 0) in vec3 aPos; // 位置变量的属性位置值为0
layout(location = 1) in vec3 aColor; // 颜色变量的属性位置值为1

out vec3 ourColor;

void main()
{
	gl_Position = vec4(aPos, 1.0);
	ourColor = aColor; // 将ourColor设置为我们从顶点数据那里得到的输入颜色
};

#shader fragment
#version 330 core

out vec4 FragColor;
in vec3 ourColor;

void main()
{
	FragColor = vec4(ourColor, 1.0);
};