clear; close all; clc;
data = load("output_chaotic_fixed.txt");
x = data(:,1);
y = data(:,2);

factor = 120;
figure('Position', [50 50 8*factor 6*factor]);
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

% min(x) 
% max(x)
% 
% min(y) 
% max(y)
