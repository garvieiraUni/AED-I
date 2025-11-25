#include <stdio.h>

int main(){
    int n, i, x, k;

    while(1){
        scanf("%d", &n);
        if(n == 0) break;

        while(1){
            scanf("%d", &x);
            if(x == 0){
                printf("\n");
                break;
            }

            int out[1000];
            out[0] = x;
            for(i = 1; i < n; i++)
                scanf("%d", &out[i]);

            int st[1000], t = 0;
            int in = 1;
            int ok = 1;

            for(i = 0; i < n; i++){
                while(in <= n && (t == 0 || st[t-1] != out[i])){
                    st[t++] = in;
                    in++;
                }
                if(st[t-1] == out[i]) t--;
                else{
                    ok = 0;
                    break;
                }
            }

            if(ok) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
