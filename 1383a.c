#include <stdio.h>

void zera_vet(int *vet) {
    for (int i = 0; i < 9; i++) {
        vet[i] = i + 1;
    }
}

int main() {
    int n, i, j, mat[9][9], vef[9], val, instancia = 1;
    scanf("%d", &n);

    while (n > 0) {
        n--;
        val = 1;

        // lê a matriz 9x9
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        // verifica linhas
        for (i = 0; i < 9 && val; i++) {
            zera_vet(vef);
            for (j = 0; j < 9; j++) {
                if (vef[mat[i][j] - 1] == 0) {
                    val = 0;
                    break;
                }
                vef[mat[i][j] - 1] = 0;
            }
        }

        // verifica colunas
        for (i = 0; i < 9 && val; i++) {
            zera_vet(vef);
            for (j = 0; j < 9; j++) {
                if (vef[mat[j][i] - 1] == 0) {
                    val = 0;
                    break;
                }
                vef[mat[j][i] - 1] = 0;
            }
        }

        // verifica submatrizes 3x3
        for (i = 0; i < 9 && val; i += 3) {
            for (j = 0; j < 9 && val; j += 3) {
                zera_vet(vef);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        int num = mat[i + k][j + l];
                        if (vef[num - 1] == 0) {
                            val = 0;
                            break;
                        }
                        vef[num - 1] = 0;
                    }
                    if (!val) break;
                }
            }
        }

        printf("Instancia %d\n", instancia++);
        printf("%s\n\n", val ? "SIM" : "NAO");
    }

    return 0;
}
