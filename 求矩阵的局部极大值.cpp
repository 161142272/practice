#include <stdio.h> 
int main () 
{
	int M, N;
	int j, k; 
	int i = M * N; 
	int p=0 ;
	int Num[M][N]={};
	
	scanf ("%d%d",&M, &N);
	

	for (j=1; j <= N;j++) 
		{
		
		for (k=1; k <=M; k ++)
				{
					
				scanf ("%d",Num[M][N]) ;
					
				}
		
		}
	
	
	for (j=1; j <= N;j++) 
		{
		
		for (k=1; k <= M; k ++)
				{
					
			if (Num[j][k] > Num[j-1][k])
					{
							if (Num[j][k] > Num[j+1][k])
							{
									if (Num[j][k] > Num[j][k-1])
									{
											if (Num[j][k] > Num[j][k+1])
											{
													printf("%d %d %d\n",Num[j][k], j, k) ;
													p++; 
											}
									}
							}
					}
				}
		}
		
		if (p==0) 
			{
			printf ("None,%d %d",N, M) ;
			}
	return 0;
}
