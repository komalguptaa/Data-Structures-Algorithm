#include <stdio.h>
#include <stdlib.h>
     void display(int a[],int m)
     {
         int i;

     for( i=0;i<m;i++)
     {
       printf("%d ",a[i]);
        }

     }
     void selection(int a[],int m)
     {
         int i,j;
        for(i=0;i<m-1;i++)
     {
         for(j=(i+1);j<m;j++)
            if(a[i]>a[j])
         {
             int t=a[i];
             a[i]=a[j];
             a[j]=t;
         }
     }
     }
     
      int main()
     {
     int m;
     int i;
     printf("Enter the value of m  \n");
     scanf("%d",&m);
     int a[m];
     printf("enter the  values \n");
     for(i=0;i<m;i++)
     {
      scanf("%d",&a[i]);
     }
     
	 printf("The  original matrix is :\n");
      display(a,m);
      selection(a,m);
       printf("\nThe  matrix after selection sort is :\n");
       display(a,m);
   }
