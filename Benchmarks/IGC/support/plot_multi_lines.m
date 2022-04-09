load('rt_cov_sta.mat');
x1 = time_arr;
y1 = cov_arr;

load('rt_cov_no_sta.mat');
x2 = time_arr;
y2 = cov_arr;

plot(x1,y1,x2,y2);
legend('STA-CGF','CGF');
grid on;
xlabel('time');
ylabel('decision coverage');
title('Test Result');



