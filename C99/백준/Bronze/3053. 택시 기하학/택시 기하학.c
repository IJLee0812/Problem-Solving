#include <stdio.h> 
#define PI 3.14159265359 
int main(void) { 
    int r; 
    double result1, result2; 
    scanf("%d", &r); 
    result1 = (double)r * r * PI; 
    result2 = (double)r * r * 2;  
    printf("%.6lf\n%.6lf", result1, result2); return 0;
}
