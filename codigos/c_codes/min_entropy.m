clear; close all; clc;

% Parametros
T1 = 3e-9;
T2 = 3e-9;
sigma = 4e-12;
K = 80000;
% hmin = 0.8563

% sigma = 3e-12;
% K = 135000;
% hmin = 0.8457

% sigma = 8e-12;
% K = 20000;
% hmin = 0.8563


t1 = (4)/(log(2)*pi^(2) );
t2 = ((-pi^(2))*(sigma^(2))*K*T2) / (T1^(3));
hmin = 1 - t1*exp(t2)

jit = sqrt( (K*sigma^(2))/(4) );


% jit = 5.66e-10;
t1 = (4)/(log(2)*pi^(2) );
t2 = ((-4*pi^(2))*(jit^(2))*T2) / (T1^(3));
hmin2 = 1 - t1*exp(t2)

