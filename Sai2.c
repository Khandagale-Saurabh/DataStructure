#include"stdio.h"
#include"conio.h"

int main()
{
    int sum=0;
    int i;
    int a[10];
    int a1[12];
         
    for(i=0;i<10;i++)
    
    {
        printf("Plz enter 10 number");
         scanf("%d",&a[i]);

    }
  for(i=0;i<10;i++)
    {
        printf("Enterd Number  := %d \n",a[i]);
    }
    
    for(i=0;i<10;i++)
    {
       sum=sum+a[i];
    }
    int avg;
    printf("Sum =: %d",sum);
    avg =sum/10;
    printf("Sum =: %d",avg);
    printf("-----------------------------------------------------------------");
    printf("Plz enter  number to be search ");
    int sear,count=0;
    scanf("%d",&sear);
    printf("Number to be search = %d" ,sear);
        for(i=0;i<10;i++)
        {
            if(a[i]==sear)
            {
               count++;
               printf("\n Number is present at %d   location" ,a[i]);
            }   
            
            
        }
        printf(" \n your numbrt was present at %d  times in an array=", count);

 printf("-----------------------------------------------------------------");
      int temp;
    int j;
for(i=0;i<10;i++)
{
     for(j=i+1;j<10;j++)
     {
          if(a[i]>a[j])
          {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
          }
     }    
}


                      for(i=0;i<10;i++)
    {
        printf("Enterd Number  := %d \n",a[i]);
    }       
}
