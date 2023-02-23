function [y] = compute_integral(l, r)
%UNTITLED5 此处显示有关此函数的摘要
%   此处显示详细说明
p = @(x) sin(x);
y = integral(p, l, r);
end

