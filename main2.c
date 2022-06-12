#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include "hash.h"


#define MAXCHAR 500
int tointeger(char s[], int size);
int find_key_index(char key[]);
Row_record* p;

int main()
{

    FILE *fp;
    char line[MAXCHAR];
    char *token;
    Hash h1; init_hash(&h1);
   // Row_record arr[250];

    fp = fopen("country1.csv","r");

    int i = 0;
    while (feof(fp) != true)
    {
        fgets(line, MAXCHAR, fp);
        printf("Row: %s", line);

        token = strtok(line, ",");
        
        int ctr = 1;  // 7 columns
        Row_record r;

        while(token != NULL)
        {   
            printf("Token: %s\n", token);
           

            if(ctr==1)
            {  // ccode[]
                strcpy(r.ccode,token);

            }
            if(ctr==2)
            {
                
                float val = atof(token);
                r.latitude = val;

            }
            if(ctr==3)
            { 
                float val = atof(token);
                r.longitude = val;

            }
            if(ctr==4)
            { 
                strcpy(r.cname,token);
                    
            }
            if(ctr==5)
            {  
                strcpy(r.ip,token);

            }
            if(ctr==6)
            {
                int  val = atoi(token);
                 r.avail = val;
            }
            if(ctr==7)
            {
                
                int  val = atoi(token);
                 r.ldeg = val;
                // Row_record* p = &r;
                p= &r;
                 insert_hash(&h1,&p);
                 int ky= find_key_index(r.ccode);
                 printf("inserted %s ",h1.records[ky]->ccode);

            }
           
             token = strtok(NULL, ",");
            ctr++;


        }
       

    }
    
  
  
    
       printf("HASH IS ----------\n");
       
   for (int i = 0 ; i < h1.size ; i++)
    {
       Row_record  *r = h1.records[i];
       if(r!=NULL) 
        {  printf(" \n %s  %f %f %s %s %d %d \n",
              

               h1.records[i]->ccode , 
               h1.records[i]->latitude ,
               h1.records[i]->longitude ,
               h1.records[i]->cname ,
               h1.records[i]->ip , 
               h1.records[i]->avail , 
               h1.records[i]->ldeg);
               
        }
    }  
       display_hash(h1);
       
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
