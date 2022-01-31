#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*x*x-x-1
int main()
{
float x0,x1,x2,y0,y1,y2,e,step;

printf("ENTER THE INITIAL ROOTS OF THE EQUATION \n");
scanf("%f%f",&x0,&x1);
printf("ENTER TOLERANCE VALUE \n");
scanf("%f",&e);

y0=f(x0);
y1=f(x1);
step=1;
 if(y0*y1>0)
 {
 printf("inital roots are unsutable \n");
 }
 else
 {
 while((fabs(x1-x0))>e)
{
 x2=(x0+x1)/2;
 y2=f(x2);
printf("%f\t%f\t\n",step, x2);
  if(y0*y2<0)
  {
x1=x2;
}
if(y1*y2<0)
 {
 x0=x2;
 
 }
 step+=1;
}
 printf("solution converges to roots \n");
 printf("the roots of given equation is %f",x2);

}
// return(0);
}