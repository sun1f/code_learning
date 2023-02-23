function [y] = xy_plot(input, x)
%UNTITLED4 y = f(x)画图
% 调用此函数传参时，如f(x)需要传递sin，则需要输入@sin，用指针来传递，不能直接传递函数名
y = input(x);
plot(x, y, 'r--');
xlabel('x');
ylabel('f(x)');
end

