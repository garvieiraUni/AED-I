#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char mina[1000];
    
    scanf("%d", &n);
    getchar(); // consome o \n depois do número
    
    while(n-- > 0) {
        int cont = 0;
        int stack = 0; // conta os '<'
        
        fgets(mina, sizeof(mina), stdin);
        int len = strlen(mina);
        
        for(i=0; i<len; i++) {
            if(mina[i] == '<') {
                stack++;
            }
            else if(mina[i] == '>' && stack > 0) {
                stack--;
                cont++;
            }
        }
        
        printf("%d\n", cont);
    }
    return 0;
}
