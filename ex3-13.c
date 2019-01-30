#include<stdio.h>
#define N 1024

int main(){
	int i, a[N], b[N], c[N];
	for(i=0; i<N; i++){
		a[i] = 0;
		b[i] = c[i] = i;
	}
	#pragma acc kernels
	{
		#pragma acc loop
		for(i=0; i < N; i++){
			a[i] = b[i] + c[i];
		}
		#pragma acc loop
		for(i = 1; i < N ; i++){
			b[i] = b[i-1];
		}

	}
	printf("b[2] = %d \n", b[2]);
	return 0;
}
