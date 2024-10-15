/*Menu Inicial: o programa começa exibindo um menu com as seguintes opções:
1 - Nova Simulação
2 - Sair do Programa
O usuário deve escolher a opção desejada. A opção 1 inicia uma nova simulação, enquanto a
opção 2 encerra o programa.
2. Entrada de Dados: se o usuário escolher a opção 1, o programa solicita as seguintes
informações:
o População inicial de bactérias (inteiro positivo).
o Taxa de crescimento (percentual inteiro que indica o aumento da população em cada ciclo).
o Número de ciclos (inteiro que representa quantos ciclos de crescimento serão simulados).
3. Simulação do Crescimento: A cada ciclo, o programa calcula a nova população usando a
fórmula:
newPopulation = nowPopulation+(nowPopulation*(growthRate/100))
4. Condições Ambientais: após calcular a nova população em cada ciclo, o programa verifica se
uma condição ambiental adversa ou favorável ocorre. A condição é determinada aleatoriamente
e aplicada com base nas seguintes probabilidades e impactos:
Condição Ambiental Probabilidade (%) Impacto na População (%)
Alta Temperatura 20% -30%
Falta de Nutrientes 15% -25%
Excesso de Umidade 10% -20%
Radiação Ultravioleta 5% -50%
Condição Favorável 10% +20%
O programa sorteia um número aleatório em cada ciclo para determinar se uma dessas condições
ocorre. Se nenhuma condição adversa ou favorável for sorteada, a população cresce apenas de
acordo com a taxa de crescimento fornecida pelo usuário.
5. Loop de Simulação: o loop de simulação continua até atingir o número total de ciclos definidos
pelo usuário.
6. Exibição de Resultados: o programa exibe a população atual ao final de cada ciclo e também
notifica se uma condição ambiental afetou a população nesse ciclo.
7. Validação de dados: o programa deve impedir que a população fique negativa. Se a população
atingir zero, a simulação termina antecipadamente. Neste caso, é mostrada uma mensagem para
o usuário dizendo que a população morreu e que a simulação não pôde continuar.*/
#include <iostream>
int main(){
    return 0;
}