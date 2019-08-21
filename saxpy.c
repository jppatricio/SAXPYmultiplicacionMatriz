#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void getWalltime(double * wcTime){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (tp.tv_sec + tp.tv_usec / 1000000.0);
}

int main(int argc, char* argv[]){
    printf("PARA 1000*1000\n\n");
    int i, j, k, n=1000;
    int **matrizA;
    int **matrizB;
    int **matrizC;

    //Para todas las combinaciones
    double S1, E1;
    double S2, E2;
    double S3, E3;
    double S4, E4;
    double S5, E5;
    double S6, E6;

    //Inicializando Matrices
    matrizA = (int **) malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++){
        *(matrizA + i) =  malloc(n* sizeof(int *));
    }
    matrizB = (int **) malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++){
        *(matrizB + i) = malloc(n* sizeof(int *));
    }
    matrizC= (int **) malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++){
        *(matrizC + i) = malloc(n* sizeof(int *));
    }

    //Llenando matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrizA[i][j] = rand() %6;
            matrizB[i][j] = rand() %6;
        }
    }
    // Combinaciones:
    // IJK
    // IKJ
    // JIK
    // JKI
    // KIJ
    // KJI

    //Llenando matriz IJK
    getWalltime(&S1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    getWalltime(&E1);
    printf("TIEMPO PARA IJK: %f \n\n", (E1-S1));

    //Llenando matriz IKJ
    getWalltime(&S2);
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            for(int j = 0; j < n; j++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    getWalltime(&E2);
    printf("TIEMPO PARA IKJ: %f \n\n", (E2-S2));

    //Llenando matriz JIK
    getWalltime(&S3);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            for(int k = 0; k < n; k++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    getWalltime(&E3);
    printf("TIEMPO PARA JIK: %f \n\n", (E3-S3));

    //Llenando matriz JKI
    getWalltime(&S4);
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    getWalltime(&E4);
    printf("TIEMPO PARA JKI: %f \n\n", (E4-S4));

    //Llenando matriz KIJ
    getWalltime(&S5);
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    getWalltime(&E5);
    printf("TIEMPO PARA KIJ: %f \n\n", (E5-S5));

    //Llenando matriz KJI
    getWalltime(&S6);
    for(int k = 0; k < n; k++){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    getWalltime(&E6);
    printf("TIEMPO PARA KJI: %f \n\n", (E6-S6));

    //FREE MEMORY
    free(matrizA);
    free(matrizB);
    free(matrizC);
}