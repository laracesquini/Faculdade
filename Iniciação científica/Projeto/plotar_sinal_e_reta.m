data_text = fileread('dados.txt');
data_strings = strsplit(data_text, ',');
data = str2double(data_strings);

figure;
plot(data);
hold on; % Manter o gráfico atual

% Coeficientes da reta
a = 0.000014; 
b = -0.000749;  

reta_y = a * (1:length(data)/2) + b; % pega valores para x de 1 até metade do sinal 

% Adicionar a reta ao gráfico
plot(reta_y)

title('Sinal de Áudio e Reta');
xlabel('Amostras');
ylabel('Amplitude');
grid on;

legend('Sinal', 'Reta');
