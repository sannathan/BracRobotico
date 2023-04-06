constexpr auto PI = 3.14;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

int main(int argc, char* argv[])
{

    //variavei para handler das juntas
    int handler1 = 0;
    int handler2 = 0;
    int handler3 = 0;
    int handler4 = 0;
    int handler5 = 0;
    int handler6 = 0;

    //conecta com o coppelia
    int clientID1 = simxStart((simxChar*) "127.0.0.1", 19999, true, true, 2000, 5);

    extApi_sleepMs(500);

    //verifica conexao com simulador
    if (clientID1 == -1) { //verificar dps se funciona corretamente
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    } else {
        printf("Conectado ao Coppelia!\n");
    }

    //configura o handler da primeira junta
    simxChar handlerName1[150] = "/NyrioOne/joint_1";
    simxChar handlerName2[150] = "/NyrioOne/joint_2";
    simxChar handlerName3[150] = "/NyrioOne/joint_3";
    simxChar handlerName4[150] = "/NyrioOne/joint_4";
    simxChar handlerName5[150] = "/NyrioOne/joint_5";
    simxChar handlerName6[150] = "/NyrioOne/joint_6";

    simxGetObjectHandle(clientID1, handlerName1, &handler1, (simxInt)simx_opmode_oneshot_wait);
    simxGetObjectHandle(clientID1, handlerName2, &handler2, (simxInt)simx_opmode_oneshot_wait);
    simxGetObjectHandle(clientID1, handlerName3, &handler3, (simxInt)simx_opmode_oneshot_wait);
    simxGetObjectHandle(clientID1, handlerName4, &handler4, (simxInt)simx_opmode_oneshot_wait);
    simxGetObjectHandle(clientID1, handlerName5, &handler5, (simxInt)simx_opmode_oneshot_wait);
    simxGetObjectHandle(clientID1, handlerName6, &handler6, (simxInt)simx_opmode_oneshot_wait);


            //move a junta ate seu ponto maximo
            simxSetJointTargetPosition(clientID1, handler1,-0.3, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);
            simxSetJointTargetPosition(clientID1, handler2, 2*PI, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);
            simxSetJointTargetPosition(clientID1, handler3, 0.3, (simxInt)simx_opmode_oneshot_wait);

    // Fecha a conexao 
    simxFinish(clientID1);

    return(0);
}
