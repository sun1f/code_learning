%% polynomial是多项式
a = [9, -5, 3, 7];
x = -2 : 0.01 : 5;
f = polyval(a, x);
plot(x, f, 'LineWidth', 2);
xlabel('x');
ylabel('f(x)');
set(gca, 'FontSize', 14);
%% 多项式微分polyder
p = [5 0 -2 0 1];
pp = polyder(p);
polyval(polyder(p), 7);
x = 0 : 0.01 : 2 * pi;
plot(x, sin(x));% sin(x)不是多项式无法用poly函数计算微积分
%% exercise
a = conv([20 -7 5 10], [4 12 -3]); 
x = -2 : 0.01 : 1;
f = polyval(a,x);
g = polyval(polyder(a),x);
% plot(x,f,'b:', x,g,'r-', 'LineWidth', 2);
p = plot(x, f, x, g);
NameArray = {'LineStyle'};
ValueArray = {':', '-'};
ColorArray = {'b', 'r'};
set(p, NameArray, ValueArray, ColorArray);

% plot(x, g, 'LineWidth', 2);
%% 多项式polyint积分
p = [5 0 -2 0 1];
polyint(p, 3);
polyval(polyint(p, 3), 7);
%% diff()返回数组前后两个数字的差（后-前），可用来计算非多项式微积分
x0 = pi / 2; h = 0.00001;
x = [x0 x0 + h];
y = [sin(x0) sin(x0 + h)];
m = diff(y) ./ diff(x);
%%
h = 0.01; x = 0 : h : 2 * pi;
y = sin(x);
m = diff(y) ./ diff(x);
mm = [m 1];
plot(x, y, x, mm);
%% Various Step Size
g = colormap(lines); hold on;
for i = 1 : 4
    x = 0 : power(10, -i) : pi;
    y = sin(x); m = diff(y) ./ diff(x);
    plot(x(1 : end - 1), m, 'Color', g(i, :));
end
hold off;
set(gca, 'XLim', [0, pi / 2]); set(gca, 'YLim', [0, 1.2]);
set(gca, 'FontSize', 18); %set(gca, 'FontName', 'symbol');
set(gca, 'XTick', 0 : pi / 4 : pi / 2);
set(gca, 'XTickLabel', {'0', '\pi/4', '\pi/2'});
h = legend('h = 0.1', 'h = 0.01', 'h = 0.001', 'h = 0.0001');
set(h, 'FontName', 'Times New Roman'); box on;
%% exercise
g = colormap(lines); hold on;
for i = 1 : 3
    x = 0 : power(10, -i) : 2 * pi;
    y = exp(-x) .* sin(x.^2 / 2); m = diff(y) ./ diff(x);
    plot(x(1 : end - 1), m, 'Color', g(i, :));
end
hold off;
set(gca, 'XLim', [0, 2 * pi]); set(gca, 'YLim', [-0.2, 0.2]);
set(gca, 'FontSize', 14); %set(gca, 'FontName', 'symbol');
set(gca, 'XTick', 0 : pi / 2 : 2 * pi);
set(gca, 'XTickLabel', {'0', '\pi/2', '\pi', '3\pi/2', '2\pi'});
h = legend('h = 0.1', 'h = 0.01', 'h = 0.001');
set(h, 'FontName', 'Times New Roman'); box on;
%%
y = @(x) 1 ./ (x.^3 - 2 * x - 5);
integral(y, 0, 2);