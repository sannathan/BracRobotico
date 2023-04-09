#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

void confirma(int j1, int j2, int j3, int j5, int client){

    extApi_sleepMs(5000);

    // volta para posicao inicial
    simxSetJointTargetPosition(client, j2, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(client, j1, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(client, j3, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(client, j5, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

    // aperta confirma
    simxSetJointTargetPosition(client, j1, -0.4, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);
    simxSetJointTargetPosition(client, j3, 0.7, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);
    simxSetJointTargetPosition(client, j5, -1.1, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);
    simxSetJointTargetPosition(client, j2, -1.2, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(15000);

    // volta para posicao inicial
    simxSetJointTargetPosition(client, j2, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(client, j1, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(client, j3, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);
    simxSetJointTargetPosition(client, j5, 0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);

}

int main(int argc, char* argv[])
{

    //variaveis para handler das juntas
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

    char valor = 'a';
    int i = 0;
    char votos[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
    

    FILE* arquivo = NULL;

    arquivo = fopen("votos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo na escrita.\n");
        return 1;
    }

    for(i = 0; i < strlen(votos); i++){
        fprintf(arquivo, "%c\n", votos[i]);
    }
    fclose(arquivo);

    arquivo = fopen("votos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo na leitura.\n");
        return 1;
    }

    while (fscanf(arquivo, " %c", &valor) != EOF) {

        printf("%c\n", valor);

        if (valor == '0') {

            // aperta no botao 0
            simxSetJointTargetPosition(clientID, junta_1, -0.28, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.3, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -0.97, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.90, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '1') {

            // aperta no botao 1
            simxSetJointTargetPosition(clientID, junta_1, -0.20, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.1, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -1, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.97, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '2') {

            // aperta no botao 2
            simxSetJointTargetPosition(clientID, junta_1, -0.27, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.05, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -1.03, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.98, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '3') {

            //aperta no botao 3
            simxSetJointTargetPosition(clientID, junta_1, -0.33, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.02, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -1.05, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.95, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '4') {

            // aperta no botao 4
            simxSetJointTargetPosition(clientID, junta_1, -0.20, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.16, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -1.1, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 1.25, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);


        }
        else if (valor == '5') {

            // aperta no botao 5
            simxSetJointTargetPosition(clientID, junta_1, -0.27, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.111, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -1.03, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.98, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '6') {

            // aperta no botao 6
            simxSetJointTargetPosition(clientID, junta_1, -0.33, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.06, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -1.05, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.98, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '7') {

            // aperta no botao 7
            simxSetJointTargetPosition(clientID, junta_1, -0.20, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.27, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -0.89, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.7, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '8') {

            // aperta no botao 8
            simxSetJointTargetPosition(clientID, junta_1, -0.28, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.25, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -0.97, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.90, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else if (valor == '9') {

            // aperta no botao 9
            simxSetJointTargetPosition(clientID, junta_1, -0.33, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_3, -0.17, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_5, 1.08, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);
            simxSetJointTargetPosition(clientID, junta_2, -1.027, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);
            simxSetJointTargetPosition(clientID, junta_5, 0.98, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(5000);

            confirma(junta_1, junta_2, junta_3, junta_5, clientID);

        }
        else {
            printf("errou feio.\n");
        }

        
    }

    fclose(arquivo);
     
    // Fecha a conexao 
    simxFinish(clientID);
    printf("parei a conexão chelly");

    return(0);
}
