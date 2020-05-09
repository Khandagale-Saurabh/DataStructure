#include<stdio.h>
#include<conio.h>
#include<iostream>
class sai
{
    private:
      int a,b;
      public:
       void f1()
       {
           a=10;
           std::cout<<" BEfore ->A=" <<a;
           std::cout<<"enter value of A;";
          std:: cin>>a;
           std::cout<<"After -> A=" <<a;
           
       }
        
};

int   main()
{
 sai a;
 a.f1();
}