#include <stdio.h>
int sol = 0;
int main(){
  int num; scanf("%d", &num);
  int numr = num;
  int zari = 0; 
  while (num){
    num /= 10;
    zari++;
  }
  int ind = zari-1, numarr[zari];
  while (numr){
    numarr[ind] = numr % 10;
    numr /= 10;
    ind--;
  } 
  int criteria = 0;
  for (int rep = 0 ; rep < zari-1 ; rep++){ // 자리수-1 만큼.
    int left = 1, right = 1;
    for (int i = 0 ; i <= criteria ; ++i){
      left *= numarr[i];
    }
    for (int i = criteria + 1 ; i <= zari-1 ; ++i){
      right *= numarr[i];
    }
    if (left == right){
      sol = 1;
      break;
    }
    criteria++;
  }
  if (sol == 1) printf("YES\n");
  else printf("NO\n");
  return 0;
}