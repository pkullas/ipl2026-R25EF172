#include<stdio.h>
void printBits(int n);
void count1Bits(int n);
int main()
{
  
  int n;
  printf("Enter a number: ");
  scanf("%d",&n);
  printBits(n);
  count1Bits(n);
}
void printBits(int n)
{
  int i;
  for(i=31;i>=0;i--)
  {
    printf("%d",(n>>i)&1);
  }
  printf("\n");
}
void count1Bits(int n)
{
  int count=0;
  while(n)
  {
    count+=n&1;
    n>>=1;
  }
  printf("Number of 1 bits: %d\n",count);
}