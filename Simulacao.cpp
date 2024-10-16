#include <iostream>
#include <time.h>
#include "Simulacao.h"

bool innitialMenu(){
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
        std::cout<<"Ate a proxima!"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"Opcao invalida, digite a opcao novamente"<<std::endl;
        innitialMenu();
    }
return 0;
}

int growthSimulationMain(){
    unsigned int growthRate, ambienceCondition;
    int cycles, currentPopulation = 0, newPopulation;

    std::cout<<"Digite a quantidade de ciclos da simulacao"<<std::endl;
    std::cin>>cycles;
    std::cout<<"Digite a populacao inicial de Bacterias"<<std::endl;
    std::cin>>currentPopulation;
    std::cout<<"Digite a taxa de crescimento"<<std::endl;
    std::cin>>growthRate;

    for(int i=1; i<=cycles; i++)
    {

        newPopulation = currentPopulation+(currentPopulation*(growthRate/100.0));
        currentPopulation = newPopulation;

        ambienceCondition = ambienceConditionDraw(&currentPopulation);

        if(currentPopulation <= 0){

            std::cout<<"A populacao chegou a zero no ciclo "<<i<<", esta simulacao sera encerrada."<<std::endl;
            return 0;

        }else{
            if(i<cycles){
                printCurrentPopulation(&currentPopulation, i, 0);
                printAmbienceCondition(ambienceCondition);

            }else{
                printCurrentPopulation(&currentPopulation, i, 1);
            }


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
                std::cout<<"[Alta Temperatura reduziu a populacao em 30% :( ]"<<std::endl;
                break;
                case 1:
                std::cout<<"[Falta de Nutrientes reduziu a populacao em 25% :( ]"<<std::endl;
                break;
                case 2:
                std::cout<<"[Excesso de Umidade reduziu a populacao em 20% :( ]"<<std::endl;
                break;
                case 3:
                std::cout<<"[Radiacao Ultravioleta (rara) reduziu a populacao em 50% :O ]"<<std::endl;
                break;
                case 4:
                std::cout<<"[Condicao favoravel aumentou a populacao em 20% :) ]"<<std::endl;
                break;
                default:
                std::cout<<"[Nenhuma condicao ambiental aconteceu neste ciclo. ]"<<std::endl;

            }
}

void printCurrentPopulation(int *pop, int index, bool lastCycleControl){
    if(lastCycleControl){
        std::cout<<"A populacao no ciclo "<<index<<" eh igual a: "<<*pop<<"    "<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Simulacao concluida: Populacao Final: "<<*pop<<"    "<<std::endl;
    }else{
        std::cout<<"A populacao no ciclo "<<index<<" eh igual a: "<<*pop<<"    ";
    }

}

int main(){
    bool endOfProgram = 0;
    srand((unsigned int)time(0));//seta a seed da função rand

    //incia o programa
    do{
        endOfProgram = innitialMenu();
    }
    while(endOfProgram == 0);

    return 0;

}