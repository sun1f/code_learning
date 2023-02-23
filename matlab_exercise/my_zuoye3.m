clc;
clear all;
close all;
fs=1000; %采样率
ts=1/fs;
f1=300;
f2=400;
f3=350;
for i=1:128
    z(i)=sin(2*pi*f2*i*ts);
end
Nmax=length(z);
figure;
yyt1=fft((z));
df=fs/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('原信号频谱图');
for i=1:128
    y(4*(i-1)+1)=z(i);
    y(4*(i-1)+2)=0;
    y(4*(i-1)+3)=0;
    y(4*(i-1)+4)=0;
end
[y1,b]=interp(z,4,8,0.35);

fs3=4*fs;
Nmax=length(y1);
figure;
yyt1=fft((y1));
df=fs3/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('interp线性内插信号频谱图');

Nmax=length(y);
figure;
yyt=fft((y));
df=fs3/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt)*2)/Nmax)
title('手动内插信号频谱图');

h=neicha;
x2=filter(h,y);
x3=conv(y1,b);
Nmax=length(x2);
figure;
yyt=fft((x2));
df=fs3/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt)*2)/Nmax)
title('手动内插滤波信号频谱图');

Nmax=length(x3);
figure;
yyt=fft((x3));
df=fs3/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt)*2)/Nmax)
title('interp线性内插滤波信号频谱图');

%% 采样
for i=1:256
    xc(i)=sin(2*pi*f1*ts*i)+sin(2*pi*f3*ts*i);
end

h1=kanghundie;
xc1=filter(h1,xc);
j=1;
for i=1:256
    if i/3==j
    xxc(j)=xc1(i);
    j=j+1;
    end
end



xd=decimate(xc,3);

Nmax=length(xc);
figure;
yyt1=fft((xc));
df=fs/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('原信号频谱图');

fs1=fs/3;
Nmax=length(xxc);
figure;
yyt1=fft((xxc));
df=fs1/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('手动降采样信号频谱图');

Nmax=length(xd);
figure;
yyt1=fft((xd));
df=fs1/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('decimate降采样信号频谱图');


%% 分数变换
fs2=12000;
ts2=1/fs2;
t=0:ts2:511*ts2
yp=cos(2*pi*1500*t)+cos(2*pi*500*t)+cos(2*pi*1000*t);
Nmax=length(yp);
figure;
yyt1=fft((yp));
df=fs2/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('信号频谱图');
%% neicha
[yp1,bp]=interp(yp,10,12,0.5);
fs3=10*fs2;
Nmax=length(yp1);
figure;
yyt1=fft((yp1));
df=fs3/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('interp线性内插信号频谱图');

x3=conv(yp1,bp);
Nmax=length(x3);
figure;
yyt=fft((x3));
df=fs3/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt)*2)/Nmax)
title('interp线性内插滤波信号频谱图');

xd=decimate(x3,6);
fs4=fs3/6;
Nmax=length(xd);
figure;
yyt1=fft((xd));
df=fs4/Nmax;
fhz=0:df:df*(Nmax-1);
plot(fhz,(abs(yyt1)*2)/Nmax)
title('decimate降采样信号频谱图');


    
    



    