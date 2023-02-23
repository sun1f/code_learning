%%
x = linspace(0,3*pi,200);
y = cos(x) + rand(1,200);
c = linspace(1,10,length(x));
scatter(x,y,[],c)
%%
x = [1 2 3 4 5 6 7 8 9 10];
y = [3.2 4.1 5.8 6.2 7.6 8 9 10 11 12];
scatter(x, y, [15], [1 0 0], 'filled');% 散点图：15是圆的大小，[1 0 0]是RGB，加'filled'表示实心
%%
x = randn(1000, 1);
y = randn(1000, 1);
z = randn(1000, 1);
scatter3(x, y, z, [20], [1 0.5 0], 'filled');