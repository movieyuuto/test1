#include<stdio.h>
#include<math.h>
int main(void)
{
  int n;
  double x;
  double sum = 0.0;
  double sum1=1.0,sum2=1.0,sum3 = 1.0;
  printf("Input n\n");
  scanf("%d",&n);
  printf("Input x\n");
  scanf("%lf",&x);
  for(int k=0;k<=n;k++)
  {
    for(int i=0;i<2*k;i++)
    {
      sum1 = sum1*x;
    }
    for(int i=1;i<=2*k;i++)
    {
    sum2 =sum2*i;
    }
    sum = sum+(sum1/sum2);
  }
  for(int b=1;b<=x;b++)
  {
    sum3 =sum3*(exp(1.0)+1/exp(1.0))/2;
  }
  printf("Calculated value = %.10lf\n",sum);
  printf("Correct answer= %.10lf\n",sum3);

return 0;
}
