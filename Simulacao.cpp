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
currentPopulation = nowPopulation+(nowPopulation*(growthRate/100))
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
#include <time.h>
#include "Simulacao.h"

void innitialMenu(){
    unsigned int ans1;
    bool endOfSimulation = 1;

    std::cout<<"1 - Nova Simulacao"<<std::endl;
    std::cout<<"2 - Sair do Programa"<<std::endl;
    std::cin>>ans1;

    if(ans1==1&&endOfSimulation==1)
    {
        endOfSimulation = growthSimulationMain();
    }
    else if(ans1==2||endOfSimulation == 0)
    {
        return;
    }
    else
    {
        std::cout<<"Opcao invalida, digite a opcao novamente"<<std::endl;
        innitialMenu();
    }
    
}

int growthSimulationMain(){
    unsigned int growthRate, ambienceCondition;
    int cycles, currentPopulation = 0, newPopulation;

    std::cout<<"Digite a quantidade de ciclos da simulacao"<<std::endl;
    std::cin>>cycles;
    std::cout<<"Digite a populacao inicial"<<std::endl;
    std::cin>>currentPopulation;
    std::cout<<"Digite a taxa de crescimento"<<std::endl;
    std::cin>>growthRate;

    for(int i=1; i<=cycles; i++)
    {
        newPopulation = currentPopulation+(currentPopulation*(growthRate/100.0));
        currentPopulation = newPopulation;

        ambienceCondition = ambienceConditionDraw(&currentPopulation);

        if(currentPopulation <= 0){

            std::cout<<"A populacao chegou a zero, a simulacao sera encerrada."<<std::endl;
            return 0;

        }else{

            printAmbienceCondition(ambienceCondition);
            printCurrentPopulation(&currentPopulation, i);


        }

    }
    return 0;

}

unsigned int ambienceConditionDraw(int *currentPopulation){
    int probabilityMachine = rand()%100+1;

    if(probabilityMachine<=20){

        *currentPopulation -= *currentPopulation*0.3;
        return 0;
        
    }
    else if((probabilityMachine<=35)&&(probabilityMachine>20)){

        *currentPopulation -= *currentPopulation*0.25;
        return 1;
    }
    else if((probabilityMachine<=45)&&(probabilityMachine>35)){

        *currentPopulation -= *currentPopulation*0.2;
        return 2;

    }
    else if((probabilityMachine<=50)&&(probabilityMachine>45)){

        *currentPopulation -= *currentPopulation*0.5;
        return 3;

    }
    else if((probabilityMachine<=60)&&(probabilityMachine>50)){

        *currentPopulation += *currentPopulation*0.2;
        return 4;

    }
    else{
        return 5;
    }
}

void printAmbienceCondition(unsigned int ans){
    switch(ans){
                case 0:
                std::cout<<"Alta Temperatura reduziu a populacao em 30% :("<<std::endl;
                break;
                case 1:
                std::cout<<"Falta de Nutrientes reduziu a populacao em 25% :("<<std::endl;
                break;
                case 2:
                std::cout<<"Excesso de Umidade reduziu a populacao em 20% :("<<std::endl;
                break;
                case 3:
                std::cout<<"Radiacao Ultravioleta (rara) reduziu a populacao em 50% :O"<<std::endl;
                break;
                case 4:
                std::cout<<"Condicao favoravel aumentou a populacao em 20% :)"<<std::endl;
                break;
                default:
                std::cout<<"Nenhuma condicao ambiental aconteceu neste ciclo."<<std::endl;

            }
}

void printCurrentPopulation(int *pop, int index){

    std::cout<<"A populacao no ciclo "<<index<<" eh igual a: "<<*pop<<std::endl;

}

int main(){
    srand((unsigned int)time(0));//seta a seed da função rand

    //incia o programa
    innitialMenu();

    return 0;
    
}