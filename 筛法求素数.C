#include<stdio.h>
#include<stdlib.h>
 
#define N 1000
 
int main(void)
{
    int i,j;
    int prime[N+1];
 
    for(i=2;i<=N;i++)
        prime[i]=1;
    for(i=2;i*i<N;i++)// 只能被1和自己整除的数才是质数，只要判断到此数的平方根即可 
    {
        if(prime[i]==1)
        {
            for(j=2*i;j<=N;j++)//对上述范围内的每一个数字，找出其倍数，并将相应的数组项 =0，表示不是质数
            {
                if(j%i==0)
                    prime[j]=0;
            }
        }
    }
 
    for(i=2;i<N;i++)
    {
        if(prime[i]==1)
        {
            printf("%4d",i);
            if(i%16==0)
                printf("\n");
        }
    }
    printf("\n");
    return 0;
}
