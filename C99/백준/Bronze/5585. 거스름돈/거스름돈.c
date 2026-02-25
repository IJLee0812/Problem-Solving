int main(){
	int i=0,n,r=0,k;scanf("%d", &n);k=1000-n;
	int m[6]={500,100,50,10,5,1};
	while(k!=0){
		while(k-m[i]>=0){
			r++;
			k-=m[i];
		}
		i++;
	}
	printf("%d",r);
	return 0;
}