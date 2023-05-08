clear; close all; clc;
tic
ai = [-0.6, -0.1, 1.1, 0.2, -0.8, 0.6, -0.7, 0.7, 0.7, 0.3, 0.6, 0.9];
% ai = [-1.0, 0.9, 0.4, -0.2, -0.6, -0.5, 0.4, 0.7, 0.3, -0.5, 0.7, -0.8];
% ai = [0.8, 1.0, -1.2, -1.0, 1.1, -0.9, 0.4, -0.4, -0.6, -0.2, -0.5, -0.7];
% ai = [-0.6, -0.4, -0.4, -0.8, 0.7, 0.3, -0.4, 0.4, 0.5, 0.5, 0.8, -0.1];
% ai = [0.0, -1.0, 0.5, -1.1, -0.4, 0.3, 0.2, 0.3, -0.5, 0.7, -1.1, 0.1];
% ai = [0.2, -0.9, -0.6, 0.4, -1.0, 0.1, 1.1, 0.2, -0.9, 0.1, 1.2, -1.2];

iter = 200;
paso = 0.003;
x = -0.8:paso:1.2;
y = -0.4:paso:0.6;

status = zeros(numel(y), numel(x));

for j = 1:numel(y)
    for i = 1:numel(x)
        xn = zeros(1,iter);
        yn = zeros(1,iter);
        yn(1) = y(j);
        xn(1) = x(i);
        for k = 2:iter
            xn(k) = ai(1) + ai(2)*xn(k-1) + ai(3)*xn(k-1)*xn(k-1) + ai(4)*xn(k-1)*yn(k-1) + ai(5)*yn(k-1) + ai(6)*yn(k-1)*yn(k-1);
            yn(k) = ai(7) + ai(8)*xn(k-1) + ai(9)*xn(k-1)*xn(k-1) + ai(10)*xn(k-1)*yn(k-1) + ai(11)*yn(k-1) + ai(12)*yn(k-1)*yn(k-1);
        end  
        if any(abs(xn) > 100) || any(abs(yn) > 100) || any(diff(xn) == 0) || any(diff(yn) == 0)
            status(j,i) = NaN;
        else
            status(j,i) = -1;
        end
    end
end

factor = 120;
figure('Position', [50 50 8*factor 6*factor]);
hold on;
s = mesh(x,y,status,"EdgeColor","#b0acac","FaceColor","#b0acac" );

data = load("output_chaotic_map1.txt");
x = data(:,1);
y = data(:,2);

% factor = 120;
% figure('Position', [50 50 8*factor 6*factor]);
plot(x,y,'.k',"MarkerSize",0.1);
grid on; 
% grid minor;
% axis([-1 1 -1 1]);
% axis([-4 1 -1 2]);
% axis([-0.5 1.5 -1 1]);
% axis([-2.5 1 -1 1]);
axis square;
xlabel('$x_{n}$','Interpreter','latex'); 
% pos = get(gca, 'YLabel').Position;
ylabel('$y_{n}$','Interpreter','latex');
% ylabel('$y_{n}$','Interpreter','latex','rotation',0,'Position', pos + [-0.05 0 0]);
set(gca,'TickLabelInterpreter','latex', 'FontSize', 12);

toc