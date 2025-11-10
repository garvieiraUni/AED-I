#include <stdio.h>
#include <stdlib.h>
typedef struct cel{
    int conteudo;
    struct cel * pai;
    struct cel *dir;
    struct cel *esq;
} no;

no * Cria(int x){
    no *p;
    p = malloc(sizeof(no));
    p->conteudo = x;
    p->pai = NULL;
    p->dir = NULL;
    p->esq = NULL;
    return p;
}

void Adiciona(no * r, int x){
    no *p, *q, *nova;
    nova = malloc(sizeof(no));
    p = r;
    while(p!=NULL){
        q=p;
        if(x >= p->conteudo)
            p = p->dir;
        else
            p = p->esq;
    }
    if(x >= q->conteudo) q->dir=nova;
    else q->esq=nova;
    nova->conteudo=x;
    nova->pai=q;
    nova->dir=NULL;
    nova->esq=NULL;
}

void libera(no * r){
    if(r != NULL){
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

void in(no * r){
  if(r != NULL){
    in(r->esq);
    printf(" %d", r->conteudo);
    in(r->dir);
  }
}

void pre(no * r){
    if (r != NULL){
        printf(" %d", r->conteudo);
        pre(r->esq);
        pre(r->dir);
    }
}

void Post(no * r){
    if(r != NULL){
        Post(r->esq);
        Post(r->dir);
        printf(" %d", r->conteudo);
    }
}   
 
int main() {
    no * raiz;
    int n, i, x,c,k;
    scanf("%d", &c);
    for(k=0; k<c; k++){
        scanf("%d", &n);
        scanf("%d", &x);
        raiz = Cria(x);
        for(i=1; i<n; i++){
            scanf("%d", &x);
            Adiciona(raiz, x);
        }
        printf("Case %d:\n", (k+1));
        printf("Pre.:");
        pre(raiz);
        printf("\nIn..:");
        in(raiz);
        printf("\nPost:");
        Post(raiz);
        libera(raiz);
        printf("\n\n");
    }
    return 0;
}
