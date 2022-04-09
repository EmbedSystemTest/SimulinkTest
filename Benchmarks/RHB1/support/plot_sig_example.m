
%%  清内存 关闭窗口 准备工作
clear 
close all
clc
 
%%  signal
A=1;                %amplify
f=1;               %Hz
w=2*pi*f;           %rad/s
p=0;                %rad
%采样
T=5;                %s        %观测时间
fs=20*f;            %Hz       %采样频率
d=1/fs;             %s        %采样间隔
 
 
t=-T/2:d:T/2;       %离散时间t
s1=A*sin(w*t+p);    %正弦信号
 
figure(1)
plot(t,s1);
xlabel('time/s');
ylabel('value');

