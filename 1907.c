#include <stdio.h>

int n, m;
char g[1100][1100];
int vis[1100][1100];

int stx[2000000], sty[2000000];

void dfs(int sx, int sy) {
    int top = 0;
    stx[top] = sx;
    sty[top] = sy;
    vis[sx][sy] = 1;

    while (top >= 0) {
        int x = stx[top];
        int y = sty[top];
        top--;

        if (x > 0 && !vis[x-1][y] && g[x-1][y] == '.') {
            vis[x-1][y] = 1;
            stx[++top] = x-1;
            sty[top] = y;
        }
        if (x < n-1 && !vis[x+1][y] && g[x+1][y] == '.') {
            vis[x+1][y] = 1;
            stx[++top] = x+1;
            sty[top] = y;
        }
        if (y > 0 && !vis[x][y-1] && g[x][y-1] == '.') {
            vis[x][y-1] = 1;
            stx[++top] = x;
            sty[top] = y-1;
        }
        if (y < m-1 && !vis[x][y+1] && g[x][y+1] == '.') {
            vis[x][y+1] = 1;
            stx[++top] = x;
            sty[top] = y+1;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int i, j;
    for (i = 0; i < n; i++)
        scanf("%s", g[i]);

    int c = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                c++;
            }
        }
    }

    printf("%d\n", c);

    return 0;
}
