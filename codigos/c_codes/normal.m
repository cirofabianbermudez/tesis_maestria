clear; close all; clc;

data = load("output_chaotic_mod_binary.txt");

x = data(:,1);
y = data(:,2);
z = x*256+y;
%%
div = 30;
% d = [0 5000];
subplot(3,1,1); histogram(x,div,"FaceColor","#b0acac",'DisplayName','$s_n$ 8 MSB bits'); grid on; grid minor;
% ylim(d);
set(gca,'TickLabelInterpreter','latex', 'FontSize', 12);
legend('Location','northeast','Interpreter','latex','FontSize', 12);

subplot(3,1,2); histogram(y,div,"FaceColor","#b0acac",'DisplayName','$s_n$ 8 LSB bits'); grid on; grid minor;
% ylim(d);
set(gca,'TickLabelInterpreter','latex', 'FontSize', 12);
legend('Location','northeast','Interpreter','latex','FontSize', 12);

subplot(3,1,3); histogram(z,div,"FaceColor","#b0acac",'DisplayName','$s_n$ 16 bits'); grid on; grid minor;
% ylim(d);
set(gca,'TickLabelInterpreter','latex', 'FontSize', 12);
legend('Location','northeast','Interpreter','latex','FontSize', 12);


% xlabel('Observaci\''on','Interpreter','latex'); 
% ylabel('Probabilidad','Interpreter','latex');
% set(gca,'TickLabelInterpreter','latex', 'FontSize', 12);
% legend('Location','northeast','Interpreter','latex','FontSize', 12);
grid on; grid minor;
set(gcf,'renderer','Painters')