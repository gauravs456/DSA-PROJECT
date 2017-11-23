#include<stdio.h>
#include<conio.h>
#include<math.h>
float fun(float x, float y)
{
	return(0.1*x*x+0.1*y*y);
}
int  main()
{
	int i,j,N;
	float x0,y0,x,h,y,k[20][20],Y[20],n,p,a;
//	clrscr();
	

	printf("\n Enter the initial value of X:");
	scanf("%f",&x0);
	printf("\n Enter the initial value of Y:");
	scanf("%f",&y0);
	printf("\n Enter the given value of X:");
	scanf("%f",&x);
	printf("\n Enter the value of step size h:");
	scanf("%f",&h);
	n=(x-x0)/h;
        N=(int)n;
	printf("\nNumber of iterations is:%d\n",N);

	for(i=1;i<=N;i++)
	{
		k[i][1]=h*fun(x0,y0);
		k[i][2]=h*fun(x0+0.5*h,y0+0.5*k[i][1]);
		k[i][3]=h*fun(x0+0.5*h,y0+0.5*k[i][2]);
		k[i][4]=h*fun(x0+h,y0+k[i][3]);
		k[i][5]=(1.0/6.0)*(k[i][1]+2*k[i][2]+2*k[i][3]+k[i][4]);
		x0=x0+h;
		y=y0+k[i][5];
		Y[i]=y;
		y0=y;
	}

	printf("\nk1\t\tk2\t\tk3\t\tk4\t\tk\t\tY\n");
	x0=x0-n*h;
	p=h;

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=5;j++)
		{
                        printf("%f\t",k[i][j]);
		}
		a=x0+h;
		printf("\tY(%f)=%f",a,Y[i]);
		printf("\n");
		h=h+p;
	}


	printf("\nThe final value of Y:\t%f",y);

	getch();
}

