#include <stdio.h>
int main(void){
    int H, M;
    scanf("%d %d", &H, &M);
    if ((0 < H) && (H <= 23)){
        if (M >= 45)
            printf("%d %d", H, M-45);
        else
            printf("%d %d", H-1, M-45+60);
    }
    else if (H == 0){
        if (M >= 45)
            printf("%d %d", 0, M-45);
        else
            printf("%d %d", 23, M-45+60);
    }
}