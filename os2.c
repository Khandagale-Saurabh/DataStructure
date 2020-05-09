#include<stdio.h>
int main()
{
    FILE *fp;
    char ch,i;
    char ch2;
    char ch1;
    fp = fopen("C:/Users/saurabh/Desktop/CORE_JAVA/sai.txt","rb");
    if(fp==NULL)
    {
      perror("Not present");
    }
    else
    {
        ch1=fgetc(fp);
        do{
           ch=fgetc(fp);

           printf("%c",ch);
           

          }while(ch!=EOF);
          ch2=ch;
        for(i=ch2;i>=0;i--)
        {
             printf("%c",ch);
        }
    }
}    