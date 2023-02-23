%% symbolic方法solve解方程
syms x
y = x * sin(x) - x;
solve(y, x)
%% 解多元方程组
syms x y
eq1 = x - y + 4;
eq2 = x + y - 6;
A = solve(eq1, eq2, x, y)
%% all symbol
syms a c b
B = solve(a * b -c, a); % “,a”表示指定a是未知数
%% exercise
syms a b c d
A = [a b; c d];
inv(A)
%% 用symbolic方式解微分，diff()
syms x
y  = 4 * x ^ 5;
diff(y)
%% 用symbolic方式解积分，int()
syms x
y = x ^ 2 * exp(x);
z = int(y);
z = z - subs(z, x, 0)
%% numeric root solver, fsolver用最小二乘法求解非线性方程，给初始值
f2 = @(x) (1.2 * x + 0.3 + x * sin(x));
fsolve(f2, 0)
%% exercise fsolve解非线性方程组
fun = @root2d;
x0 = [-5, -5];
x = fsolve(fun, x0)
%% roots()解多项式方程
roots([1 -3.5 2.75 2.125 -3.875 1.25])
%% 函数必须定义在整篇文档最后
function s = root2d(x)
s(1) = 2 * x(1) - x(2) - exp(-x(1));
s(2) = -x(1) + 2 * x(2) - exp(-x(2));
end