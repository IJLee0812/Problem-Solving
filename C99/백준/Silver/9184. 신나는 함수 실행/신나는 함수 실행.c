#include <stdio.h>

int a, b, c, tmp[25][25][25];

int w(int a, int b, int c){   
    
    if (a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20){
        tmp[20][20][20] = w(20, 20, 20);
		return tmp[20][20][20];
    }
    else if (a < b && b < c){
        if (tmp[a][b][c] != 0){
			return tmp[a][b][c];
		}
        else{
            tmp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
			return tmp[a][b][c];
		}
    }
    else{
        if (tmp[a][b][c] != 0){
			return tmp[a][b][c];
		}
        else{
            tmp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
			return tmp[a][b][c];
		}
    }
    
}

int main(void){
        
    while (1){
        
        scanf("%d %d %d", &a, &b, &c);
        
        if (a == -1 && b == -1 && c == -1){
            break;
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}
