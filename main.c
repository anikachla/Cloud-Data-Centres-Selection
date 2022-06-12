#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include "hash.h"
#include "kd.h"
#include "nearest.h"


#define MAXCHAR 500
int tointeger(char s[], int size);


int main()
{

    FILE *fp;
    char line[MAXCHAR];
    char *token;
    Row_record arr[250];

    fp = fopen("country1.csv","r");

    int i = 0;
    while (feof(fp) != true)
    {
        fgets(line, MAXCHAR, fp);
        printf("Row: %s", line);

        token = strtok(line, ",");
        
        int ctr = 1;  // 7 columns

        while(token != NULL)
        {   
            printf("Token: %s\n", token);
           

            if(ctr==1)
            {  // ccode[]
                strcpy(arr[i].ccode,token);

            }
            if(ctr==2)
            {
                
                float val = atof(token);
                arr[i].latitude = val;

            }
            if(ctr==3)
            { 
                float val = atof(token);
                arr[i].longitude = val;

            }
            if(ctr==4)
            { 
                strcpy(arr[i].cname,token);
                    
            }
            if(ctr==5)
            {  
                strcpy(arr[i].ip,token);

            }
            if(ctr==6)
            {
                int  val = atoi(token);
                 arr[i].avail = val;
            }
            if(ctr==7)
            {
                
                int  val = atoi(token);
                 arr[i].ldeg = val;

            }
           
             token = strtok(NULL, ",");
            ctr++;


        }
        i++;

    }
    
  
   //  display array[] of row record structs. print  each arr[i] 's struct.field 
   printf(" Displaying what is read from file ----------------------------------------\n");
    for(int m = 0; m <=i ;m++)
    {
      
       printf("  %d %s %f %f %s %s %d %d \n",m,
               arr[m].ccode,
               arr[m].latitude,
               arr[m].longitude,
               arr[m].cname,
               arr[m].ip,
               arr[m].avail,
               arr[m].ldeg);
    }
    printf("\narray print done \n");

    Hash h1;
    init_hash(&h1);
    Row_record* rptr; 
     Row_record r;
    for(int j = 0; j <= i ;j++)
    {
       r = arr[j];
       
        // Row_record *rptr= &r;
            rptr= &r;
            
         if(r.latitude == 0.0 || r.longitude == 0.0 || r.ccode ==NULL )
           {  
               continue;
           }
       
           else 
           { 
             
           //  insert_hash(&h1 ,(&r));
              insert_hash(&h1,&(arr[j]));
            }
       
   }
       printf("HASH IS ----------\n");
       display_hash(h1);
       
       printf("KDTREE IS in main rn --");
       KDTree k; init_kd(&k);
       insertion_of_data(&h1, &k );
       printf("\ndone done");
       return 0;

     

}
  

int tointeger(char s[], int size)
{
    int num=0;
    for(int i=0 ;i<size ; i++)
    {   int d= s[i] - '0';
        num = num*10 + d;
    }
    return num;
}
