%%
for i = 1 : 10
    x=linspace(0, 10, 101);
    plot(x, sin(x+i));
    print(gcf, '-deps', strcat('plot', num2str(i), '.ps'));
end
%%
a = 3;
if rem(a, 2) == 0
    disp('a is even')
else
    disp('a is odd')
end
%%
% 数据准备 
xi=-10:0.5:10; 
yi=-10:0.5:10; 
[x,y]=meshgrid(xi,yi); 
z=sin(sqrt(x.^2+y.^2))./sqrt(x.^2+y.^2); 
% 绘图 
surf(x,y,z) 
%%
% 数据准备 
xi=-10:0.5:10; 
yi=-10:0.5:10; 
[x,y]=meshgrid(xi,yi); 
z=sin(sqrt(x.^2+y.^2))./sqrt(x.^2+y.^2); 
[x,y,z] = meshgrid(-2:.2:2, -2:.25:2, -2:.16:2); 
v = x.*exp(-x.^2-y.^2-z.^2); 
xslice = [-1.2,.8,2]; 
yslice = 2; 
zslice = [-2,0]; 
% 绘图 
slice(x,y,z,v,xslice,yslice,zslice) 
%%
for n = 1 : 2 : 10
    a(n) = 2 ^ n;
end
disp(a(1 : 2 : 10))
%%
s1 = 'Example';
s2 = 'String';
s3 = [s1 s2];
s4 = [s1; s1];
%%
s1 = 'I like English';
s2 = reverse(s1);
%%
str = ["airport","control tower","radar","runway"];

newStr = reverse(str);

tf = (newStr == str);

str(tf);
%%
A{1, 1} = [1 4 3; 0 5 8; 7 2 9];
A{1, 2} = 'Anne Smith';
A{2, 1} = 3 + 7i;
A{2, 2} = -pi: pi: pi;
A;
%%
hold on
plot(cos(0:pi/20:2*pi), 'o--g');
plot(sin(0:pi/20:2*pi), 'p:r');
hold off
%%
t = 1 : 0.01 : 2;
f = t .* t;
g = sin(2 * pi * t);
h = plot(t, f, 'k-',t, g, 'ro');
% h = plot(t, f, 'k-');
legend('t^{2}', 'sin(2\pit)');
xlabel('Time(ms)');
ylabel('f(t)');
title('Mini Assignment #1')
% get(h)