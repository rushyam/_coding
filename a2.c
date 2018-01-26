#include <stdio.h>
#include <time.h>
extern void registerme ( );
extern void startgame ( int );
extern int guess ( int );
extern void verifysoln ( int );
int playgame1()
{
	int i;
	for(i=0;i<=100000000;i++)
	{
		if(guess(i) == 1)
			return i;
	}
}
int playgame3(int l,int r)
{
	printf("rushyam\n");
	int a = guess(l);
	int b = guess(r);
	if(a == 1)
		return l;
	if(b == 1)
		return r;
	int m = (l+r)/2; 
	if(b == 3)
		return playgame3(l,m);
	if(b == 2)
		return playgame3(m,r);
}
int playgame2()
{
	int i;
	for(i=0;i<=100000000;i++)
	{
		if(guess(i) == 1)
			return i;
	}
}

int playgame4(int l,int r,int s)
{
	int a,b;
	if(s==0)
	{	
		printf("rushyam\n");
		a=guess(l);
		b=guess(r);
		if(a == 1)
			return l;
		if(b == 1)
			return r;
		int m = (l+r)/2;
		if(b == 2)
			return playgame4(m,r,1);
		if(b == 3)
			return playgame4(l,m,0);
	}
	if(s == 1)
	{
		printf("rushyam\n");
		a = guess(l);
		if(a == 1)
			return l;
		int m = (l+r)/2;
		if(a == 2)
			return playgame4(l,m,-1);
		if(a == 3)
			return playgame4(m,r,0);
	}
	if(s == -1)
	{
		printf("rushyam\n");
		b =guess(r);
		if(b == 1)
			return r;
		int m = (l+r)/2;
		if(b == 2)
			return playgame4(m, r ,1);
		if(b == 3)
			return playgame4(l,m,0);	
	}
}
int main()
{
	clock_t c1, c2;
	int a;
	int i;
	registerme();
	// for(i=1;i<5;i++)
	// {
	// 	startgame(i);
	// 	c1 = clock();
	// 	if(i == 1)
	// 		a = playgame1();
	// 	if(i == 2)
	// 		a = playgame2();
	// 	if(i == 3)
	// 		a = playgame3(0,100000000);
	// 	if(i == 4)
	// 	 	a = playgame3(0,100000000);
	// 	c2 = clock();
	// 	printf("\n+++ Game %d\n a%d = %d\n", i,i,a);
	// 	printf(" Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
	// 	verifysoln(a);
	// }
	
	// startgame(1);
	// c1 = clock();
	// a = playgame1();
	// c2 = clock();
	// printf("\n+++ Game %d\n a%d = %d\n", i,i,a);
	// printf(" Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
	// verifysoln(a);
		
	// startgame(2);
	// c1 = clock();
	// a = playgame2();
	// c2 = clock();
	// printf("\n+++ Game %d\n a%d = %d\n", i,i,a);
	// printf(" Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
	// verifysoln(a);
	
	startgame(3);
	c1 = clock();
	a = playgame3(0,100000000);
	c2 = clock();
	printf("\n+++ Game %d\n a%d = %d\n", i,i,a);
	printf(" Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
	verifysoln(a);
	
	startgame(4);
	c1 = clock();
	a = playgame3(0,100000000);
	c2 = clock();
	printf("\n+++ Game %d\n a%d = %d\n", i,i,a);
	printf(" Time taken = %lf sec\n", (double)(c2-c1)/(double)CLOCKS_PER_SEC);
	verifysoln(a);
	
	return 0;
}