clear; close all; clc;
% Creamos un vector con las letras del alfabeto
abecedario = 'A':'Y';
conv = zeros(size(abecedario));

% map = 'GLXOESFTTPSV';
% map = 'CVQKGHQTPHTE';
% map = 'UWACXDQIGKHF';
% map = 'GIIETPIQRRUL';
map = 'MCRBIPOPHTBN';
% map = 'ODGQCNXODNYA';


% map = 'LUFBBFISGJYS';

format short
% Imprimimos cada letra del alfabeto utilizando un bucle for
numb = -1.2;
for i = 1:length(abecedario)
    conv(i) = numb;
    fprintf('%c & %3.1f \\\\ \n\\hline\n', abecedario(i),numb);
    numb = numb + 0.1;
end

fprintf('{');
for i = 1:length(map)
    temp = conv( abecedario == map(i) );
    fprintf('%3.1f, ', temp);
end
fprintf("}\n");
