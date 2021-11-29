clear; close all; clc;
iter = 100000;
n = 0:1:iter;
a = [-0.6, -0.1, 1.1, 0.2, -0.8, 0.6, -0.7, 0.7, 0.7, 0.3, 0.6, 0.9];       %M1
x0 = 0.1; y0 = 0.2;
xn = zeros(1,iter+1); yn = zeros(1,iter+1);
xn(1) = x0; yn(1) = y0;
for i = 2:iter+1
    xn(i) = a(1) + a(2)*xn(i-1) + a(3)*xn(i-1)^(2) + a(4)*xn(i-1)*yn(i-1) + a(5)*yn(i-1) + a(6)*yn(i-1)^(2);
    yn(i) = a(7) + a(8)*xn(i-1) + a(9)*xn(i-1)^(2) + a(10)*xn(i-1)*yn(i-1) + a(11)*yn(i-1) + a(12)*yn(i-1)^(2);
end
plot(xn,yn,'.k','MarkerSize',0.5); grid on; xlabel("xn"); ylabel("yn"); axis equal;