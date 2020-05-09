#include<stdio.h>

int main()
{
  FILE *fp;
  char ch;
   fp=fopen("C:/Users/saurabh/Desktop/CORE_JAVA/sai1.txt","rb");
   if (fp == NULL)
   {
    printf("Failed");
   }
 else
 {
      printf("OPEN in read mode");
      do
      {
          ch=fgetc(fp);
          printf("%c",ch);
      } while (ch!=EOF);
      
    /*  while(ch=(fgetc(fp))!=EOF)
      {
          printf("%c",ch);
          printf("%d",ch);
      } */
 }
 
}