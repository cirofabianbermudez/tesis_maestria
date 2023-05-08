clear; close all; clc;

ai = [-0.6, -0.1, 1.1, 0.2, -0.8, 0.6, -0.7, 0.7, 0.7, 0.3, 0.6, 0.9];
iter = 100000;
paso = 0.1;
x = -2:paso:2;
y = -2:paso:2;

status = zeros(numel(x), numel(y));


for j = 1:numel(x)
    xn = zeros(1,iter);
    yn = zeros(1,iter);
    xn(1) = x(j);
    yn(1) = 0.0;
    for i = 2:iter
        xn(i) = ai(1) + ai(2)*xn(i-1) + ai(3)*xn(i-1)*xn(i-1) + ai(4)*xn(i-1)*yn(i-1) + ai(5)*yn(i-1) + ai(6)*yn(i-1)*yn(i-1);
        yn(i) = ai(7) + ai(8)*xn(i-1) + ai(9)*xn(i-1)*xn(i-1) + ai(10)*xn(i-1)*yn(i-1) + ai(11)*yn(i-1) + ai(12)*yn(i-1)*yn(i-1);
    end  
    if any(abs(xn) > 1000) || any(abs(yn) > 1000)
        status(j) = 0;
    else
        status(j) = 1;
    end
end

result = [x.' status.'];

plot(x, status)
% plot(xn,yn,'.k',"MarkerSize",0.1);

