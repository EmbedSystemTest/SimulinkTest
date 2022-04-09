load('sp.mat');
x1 = time_arr;
y1 = cov_arr;

load('sc.mat');
x2 = time_arr;
y2 = cov_arr;

plot(x1,y1,x2,y2);
legend('SPsCGF','rawCGF');
grid on;
xlabel('time');
ylabel('Condition Coverage');
title('Test Result');



