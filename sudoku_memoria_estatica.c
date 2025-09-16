#include <stdio.h>
#include <stdlib.h>

int zera_vet(int *vet[9]){
    int i;
    for(i=0;i<9;i++){
        *vet[i]=i+1;
    }
}

int main(){
    int n, i, j, mat[9][9], vef[9], val=1;
    printf("Digite o numero de matrizes: ");
    scanf("%d", &n);
    while(n>0){
        printf("Matriz %d:\n", n);
        n--;

        //pega a matriz
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                printf("Digite o valor da posicao [%d][%d]: ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }

        // verifica linhas
        for(i=0;i<9;i++){
            zera_vet(&vef[9]);
            for(j=0;j<9;j++){
                if(mat[i][j] == vef[mat[i][j]-1])
                    vef[mat[i][j]-1] = 0;
                if(vef[mat[i][j]-1] == 0)
                    val = 0;
            }
        }

        // verifica colunas
        for(i=0;i<9;i++){
            zera_vet(&vef[9]);
            for(j=0;j<9;j++){
                if(mat[j][i] == vef[mat[j][i]-1])
                    vef[mat[j][i]-1] = 0;
                if(vef[mat[j][i]-1] == 0)
                    val = 0;
            }
        }

        // verifica submatrizes
        for(i=0;i<9;i+=3){
            for(j=0;j<9;j+=3){
                zera_vet(&vef[9]);
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(mat[i+k][j+l] == vef[mat[i+k][j+l]-1])
                            vef[mat[i+k][j+l]-1] = 0;
                        if(vef[mat[i+k][j+l]-1] == 0)
                            val = 0;
                    }
                }
            }
        }

        if(val == 1)
            printf("SIM\n");
        else
            printf("NAO\n");
    }
}
