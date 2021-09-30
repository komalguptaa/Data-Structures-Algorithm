#include <stdio.h>

     void display(int a[],int m)
     {
         int i;

     for( i=0;i<m;i++)
     {
       printf("%d",a[i]);
        }

     }
    
     void bubble(int a[],int m)
     {
        int i,j;
        for(i=0;i<m-1;i++)
     	{
         for(j=0;j<m-i-1;j++)
            if(a[j]<a[j+1])
         {
             int t=a[j];
             a[j]=a[j+1];
             a[j+1]=t;
         }
    	 }
     }


      int main()
     {
     int m;
     int i;
     printf("enter the value of m  \n");
     scanf("%d",&m);
     int a[m];
     printf("enter the  values \n");
     for(i=0;i<m;i++)
     {

      scanf("%d",&a[i]);
     }
       printf("The  original matrix is :\n");
      display(a,m);
      bubble(a,m);
        printf(" \n The  matrix after bubble sort is :\n");
       display(a,m);
       return 0;
     }
