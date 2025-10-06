#include <stdio.h>
#include <stdlib.h>

void zera_vet(int *vet) {
    for (int i = 0; i < 9; i++) {
        vet[i] = i + 1;
    }
}

int main() {
    int n, i, j, **mat, *vef, val, instancia = 1;
    scanf("%d", &n);

    while (n > 0) {
        n--;
        val = 1;

        // aloca a matriz
        mat = (int **)malloc(9 * sizeof(int *));
        for (i = 0; i < 9; i++) {
            mat[i] = (int *)malloc(9 * sizeof(int));
        }
        vef = (int *)malloc(9 * sizeof(int));

        // lê a matriz
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        // verifica linhas
        for (i = 0; i < 9; i++) {
            zera_vet(vef);
            for (j = 0; j < 9; j++) {
                if (vef[mat[i][j] - 1] == 0) 
                  val = 0;
                vef[mat[i][j] - 1] = 0;
            }
        }

        // verifica colunas
        for (i = 0; i < 9; i++) {
            zera_vet(vef);
            for (j = 0; j < 9; j++) {
                if (vef[mat[j][i] - 1] == 0) 
                  val = 0;
                vef[mat[j][i] - 1] = 0;
            }
        }

        // verifica submatrizes 3x3
        for (i = 0; i < 9; i += 3) {
            for (j = 0; j < 9; j += 3) {
                zera_vet(vef);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (vef[mat[i + k][j + l] - 1] == 0) 
                          val = 0;
                        vef[mat[i + k][j + l] - 1] = 0;
                    }
                }
            }
        }

        printf("Instancia %d\n", instancia++);
        printf("%s\n\n", val ? "SIM" : "NAO");

        // libera a matriz
        for (i = 0; i < 9; i++)
          free(mat[i]);
        free(mat);
        free(vef);
    }

    return 0;
}
