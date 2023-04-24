clear; close all; clc;

syms r x
eqn = (r^2)*x*(1-x)*(1 - r*x*(1-x) ) -x == 0;
% expand(eqn)
r = 3.2;
x = 1 - 1/r
p = ( r + 1 + sqrt( (r-3)*(r+1) ) ) / (2*r)
q = ( r + 1 - sqrt( (r-3)*(r+1) ) ) / (2*r)
% S = solve(eqn)
% pretty(S)