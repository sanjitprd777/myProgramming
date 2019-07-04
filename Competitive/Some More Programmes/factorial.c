#include <stdio.h>
int main()
{
    /*finding the factorial using array, since there is no datatype to hold such a big numbers ... */
    int arr[2000]={0},size=1,num,carry=0,i,j,prod,t;
    scanf("%d",&t);
    while(t--){
    arr[0]=1;
    size=1;
    printf("\nEnter the number : \n");
    scanf("%d",&num);

    for(i=2;i<=num;++i)
    {
        for(j=0;j<size;++j)
        {
            prod=i*arr[j]+carry;  /* Getting the product of next integer with previous number ...*/
            arr[j]=prod%10;       /* Storing the last element of the factorial number...*/
            carry=prod/10;        /* carry after storing last digit of the factorial...*/
        }
        while(carry)              /* If next factorial has more digits then previous one ... */
        {
            arr[size]=carry%10;
            carry/=10;
            size++;
        }
    }
    /*printing values in reverse ... */
    for(i=size-1;i>=0;--i)
        printf("%d",arr[i]);
    }
    return 0;
}
