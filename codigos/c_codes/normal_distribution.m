clear; close all; clc;

data = load("output_chaotic_mod_binary.txt");

s = sum(data,2);
p = sum(data,2)/6;
histogram(s,'Normalization','pdf',"DisplayName","Experimental", "FaceColor","#b0acac")
hold on
r = 7;
y = 8-r:0.1:8+r;
mu = 16*0.5;
sigma = sqrt(16*0.5*(1-0.5));
f = exp(-(y-mu).^2./(2*sigma^2))./(sigma*sqrt(2*pi));
plot(y,f,'k','LineWidth',1.5, "DisplayName","Ideal");

xlabel('Observaci\''on','Interpreter','latex'); 
ylabel('Probabilidad','Interpreter','latex');
set(gca,'TickLabelInterpreter','latex', 'FontSize', 12);
legend('Location','northeast','Interpreter','latex','FontSize', 12);
grid on; grid minor;
set(gcf,'renderer','Painters')