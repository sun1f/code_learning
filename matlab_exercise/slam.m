clear all;
clc;

fidin=fopen('trajectory_estimate.txt');                               % 打开test2.txt文件             
fidout=fopen('trajectory_deal.txt','w');                       % 创建MKMATLAB.txt文件
while ~feof(fidin)                                      % 判断是否为文件末尾               
    tline=fgetl(fidin);                                 % 从文件读行   
    if double(tline(1))>=48&&double(tline(1))<=57       % 判断首字符是否是数值
       fprintf(fidout,'%s\n\n',tline);                  % 如果是数字行，把此行数据写入文件MKMATLAB.txt
       continue                                         % 如果是非数字继续下一次循环
    end
end
fclose(fidout);
transformation=importdata('trajectory_deal.txt');      % 将生成的MKMATLAB.txt文件导入工作空间，变量名为MK，实际上它不显示出来 

plot3(transformation(:, 2), transformation(:, 3), transformation(:, 4), 'ro-', 'Linewidth', 2);
grid on;