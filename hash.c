
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


int find_key_index(char key[]);

void init_hash(Hash *h )
{ 
    h->size=677 ;
   for(int i=0; i< h->size ;i++)
      h->records[i] = NULL;

}


int find_key_index(char key[])
{
     int  block_num = key[0] - 64;
     int disp = key[1] - 64;
     int index = (block_num - 1) *26 + disp;
     printf(" return key index = %d\n",index);
     return index;
}

void insert_hash(Hash *h, Row_record* x)
{    
     char key[3];    // | N | Z | \0 |     3  char code
     key[0]= (*x).ccode[0];
     key[1]= (*x).ccode[1];
     key[2]= (*x).ccode[3];

      Row_record* x2 = x;
      
       int index = find_key_index(key);
     if(x2->latitude == 0.0 || x2->longitude == 0.0 || x2->ccode ==NULL || x2->ip==NULL || x2->cname==NULL )
           {  
               return;
           }
           if(index <0 || index > h->size)
           {
              return;
           }
      
   
             h->records[index] = x;
              h->records[index] = x;
             
             //printf("*x = %p ",*x);
             printf(" \nInserted in hash -- %s  %f %f %s %s %d %d ",
               h->records[index]->ccode , 
               h->records[index]->latitude ,
               h->records[index]->longitude ,
               h->records[index]->cname ,
               h->records[index]->ip , 
               h->records[index]->avail ,
               h->records[index]->ldeg);
               

     return;

}
/*
void insert_hash(Hash *h, Row_record** x)
{    
     char key[3];    // | N | Z | \0 |     3  char code
     key[0]= (**x).ccode[0];
     key[1]= (**x).ccode[1];
     key[2]= (**x).ccode[3];
      Row_record* x2 = *x;
       int index = find_key_index(key);
     if(x2->latitude == 0.0 || x2->longitude == 0.0 || x2->ccode ==NULL || x2->ip==NULL || x2->cname==NULL )
           {  
               return;
           }
           if(index <0 || index > h->size)
           {
              return;
           }
      
   
             h->records[index] = *x;
              h->records[index] = *x;
             
            // printf("*x = %p ",*x);
             printf(" \n %s  %f %f %s %s %d %d \n",
               h->records[index]->ccode , 
               h->records[index]->latitude ,
               h->records[index]->longitude ,
               h->records[index]->cname ,
               h->records[index]->ip , 
               h->records[index]->avail ,
               h->records[index]->ldeg);
               

     return;

}
*/

 Row_record* search_hash(Hash *h , char key[])
{    
    int i = find_key_index(key) ;
    if(h->records[i] == NULL)
       return NULL;
    else
       return (h->records[i]);
    
}
void delete_hash(Hash *h ,char key[])
{
   int i = find_key_index(key);
    if(h->records[i] == NULL)
       return ;
    else
       h->records[i] = NULL ;

}


void display_hash(Hash h)
{  
    printf("hash  is\n");
       char pp[3] ;
       strcpy(pp,"AL");
       int opp= find_key_index(pp);
       printf("key index = %d\n ",opp);
       /*
       printf(" load degree of AL = %d\n", h.records[opp]->ldeg);
        printf(" ccode of AL = %s\n", h.records[opp]->ccode);
         printf("  latitude of AL = %f\n", h.records[opp]->latitude);
          printf(" longitude of AL = %f\n", h.records[opp]->longitude);
           printf(" cname  of AL = %s\n", h.records[opp]->cname);
            printf(" ip of AL = %s\n", h.records[opp]->ip);
             printf(" avail of AL = %d\n", h.records[opp]->avail);
              printf(" load degree of AL = %d\n", h.records[opp]->ldeg);

              */

      
   for (int i = 0 ; i < h.size ; i++)
    {
       Row_record  *r = h.records[i];
       if(r!=NULL) 
        {  printf("  %s  %f %f %s %s %d %d \n",
              

               h.records[i]->ccode , 
               h.records[i]->latitude ,
               h.records[i]->longitude ,
               h.records[i]->cname ,
               h.records[i]->ip , 
               h.records[i]->avail , 
               h.records[i]->ldeg);
               
        }
    }  
    

    }


/**
 // main for testing hash 
int main(void)
 {
     Row_record r1;
     Row_record r2;
     Row_record r3;
     Row_record r4;

     strcpy(r1.ccode,"AA"); strcpy(r1.cname,"aaa")  ; strcpy(r1.ip,"11") ;  r1.avail =91; r1.ldeg = 41.0; r1.latitude = 81.0; r1.longitude =71.0;
     strcpy(r2.ccode,"AB"); strcpy(r2.cname , "abbb") ;strcpy(r2.ip,"12") ;  r2.avail =92; r2.ldeg = 42.0; r2.latitude = 82.0; r2.longitude =72.0;
     strcpy(r3.ccode,"ZZ");  strcpy(r3.cname, "zzzz") ;strcpy(r3.ip,"66") ; r3.avail =93;  r3.ldeg = 43.0; r3.latitude = 83.0; r3.longitude =73.0;
     strcpy(r4.ccode ,"BA"); strcpy(r4.cname ,"bbaa") ;strcpy(r4.ip,"21") ; r4.avail =94; r4.ldeg = 44.0; r4.latitude = 84.0; r4.longitude =74.0;

    
     Hash h1;
     init_hash(&h1);
     insert_hash(&h1, &r1);
     insert_hash(&h1, &r2);
     insert_hash(&h1, &r3);
     insert_hash(&h1, &r4);
     delete_hash(&h1,"AW");
      printf("hash is ------ \n");
     display_hash(&h1);
     Row_record* s = search_hash(&h1,"AW");
     if(s==NULL)
     printf("not found \n"); else printf("found  \n");
   
     return 0;



 }

 **/
