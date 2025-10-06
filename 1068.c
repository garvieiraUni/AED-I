#include <stdio.h>
#include <string.h>

int main(){
    char exp[1000], pilha[1000];
    int i, p, vef;

    while(fgets(exp, sizeof(exp), stdin) != NULL){
        p = 0;
        vef = 1;

        for(i=0; exp[i]!='\0'; i++){
            if(exp[i]=='(')
                pilha[p++] = '(';
            else if(exp[i]==')'){
                if(p==0){
                    vef = 0;
                    break;
                }
                p--;
            }
        }

        if(vef==1 && p==0)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}

