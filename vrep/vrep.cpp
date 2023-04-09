#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

int main(int argc, char* argv[])
{

    //variavei para handler das juntas
    int handler = 0;
    int junta_1 = 0;
    int junta_2 = 0;
    int junta_3 = 0;
    int junta_4 = 0;
    int junta_5 = 0;
    int junta_6 = 0;

    //conecta com o coppelia
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);

    extApi_sleepMs(500);

    //verifica conexao com simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }

    //configura o handler de todas as juntas do NiryoOne
    simxChar junta1[150] = "/NiryoOne/Joint";
    simxGetObjectHandle(clientID, junta1, &junta_1, (simxInt)simx_opmode_oneshot_wait);
    simxChar junta2[150] = "/NiryoOne/Joint/Link/Joint";
    simxGetObjectHandle(clientID, junta2, &junta_2, (simxInt)simx_opmode_oneshot_wait);
    simxChar junta3[150] = "/NiryoOne/Joint/Link/Joint/Link/Joint";
    simxGetObjectHandle(clientID, junta3, &junta_3, (simxInt)simx_opmode_oneshot_wait);
    simxChar junta4[150] = "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint";
    simxGetObjectHandle(clientID, junta4, &junta_4, (simxInt)simx_opmode_oneshot_wait);
    simxChar junta5[150] = "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint";
    simxGetObjectHandle(clientID, junta5, &junta_5, (simxInt)simx_opmode_oneshot_wait);
    simxChar junta6[150] = "/NiryoOne/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint/Link/Joint";
    simxGetObjectHandle(clientID, junta6, &junta_6, (simxInt)simx_opmode_oneshot_wait);

   // for (int i = 1; i <= 6; i++) {

    // move o braco ate a tecla 0
        printf("Chelly to testando a junta 1\n");
        simxSetJointTargetPosition(clientID, junta_1, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(3000);
        simxSetJointTargetPosition(clientID, junta_1, (simxFloat)-(PI/10), (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(3000);

        printf("Chelly to testando a junta 3\n");
        simxSetJointTargetPosition(clientID, junta_3, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(3000);
        simxSetJointTargetPosition(clientID, junta_3, (simxFloat)-PI/18, (simxInt)simx_opmode_oneshot_wait);

        printf("Chelly to testando a junta 5\n");
        simxSetJointTargetPosition(clientID, junta_5, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(3000);
        simxSetJointTargetPosition(clientID, junta_5, (simxFloat)-PI/36, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(3000);

        printf("Chelly to testando a junta 2\n");
        simxSetJointTargetPosition(clientID, junta_2, (simxFloat)-PI/3, (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(4000);
        simxSetJointTargetPosition(clientID, junta_2, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
        
        // devolve todas as juntas a posicao inicial
     
    // Fecha a conexao 
    simxFinish(clientID);
    printf("parei a conexão chelly");

    return(0);
}
