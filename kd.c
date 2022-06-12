
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kd.h"

kdnode* prev;


void init_kd(KDTree *t)
{
     *t=NULL;
      prev= *t;

}




void  insert_kd(KDTree *t,  int cp , char ccode[], float latitude, float longitude)
{
     
  if(*t==NULL)
  {
      kdnode* nn= (kdnode*)malloc(sizeof(kdnode));
      nn->left = NULL;
      nn->right = NULL;
      nn->parent = prev;
      nn->lati =latitude;
      nn->longi = longitude;
      strcpy(nn->cc,ccode);
      
  
     if(prev!=NULL)
    {
         if(cp == 2)
        {
           if(latitude < prev->lati)
                 prev->left = nn;
             else
                prev->right = nn;
        }
         if(cp == 1)
         {
            if(longitude < prev->longi)
                 prev->left = nn;
            else
                 prev->right = nn;
       
        }

     }
      else      // prev is null means first time inserting
      {
          *t=nn;
       }

       return;
  }

     prev =*t;
        if(cp==1)
        {
        if ((*t)->lati == latitude)
            return;
         else if( latitude  <  (*t)->lati)
               insert_kd( &((*t)->left), 2, ccode, latitude, longitude);
         else
             insert_kd(&((*t)->right), 2 ,ccode, latitude, longitude);
        }

         if (cp == 2) 
         {
             if((*t)->longi == longitude)
                 return;

            else if( longitude  <  (*t)->longi)
                 insert_kd( &((*t)->left), 1, ccode, latitude, longitude);
            else
                insert_kd( &((*t)->right), 1,ccode, latitude, longitude);
         }
            

     

}

void traverse_kd(KDTree t)
{

    if(t==NULL)
      return;

    traverse_kd(t->left);
    printf(" %s %f %f \n",t->cc, t->lati, t->longi);
    traverse_kd(t->right);

}


/**
int main(void)
{

 KDTree k; init_kd(&k);
 char c1[3];  strcpy(c1,"A");
 char c2[3];  strcpy(c2,"B");
 char c3[3];  strcpy(c3,"C");
 char c4[3];  strcpy(c4,"D");
 char c5[3];  strcpy(c5,"E");
 char c6[3];  strcpy(c6,"F");
 char c7[3];  strcpy(c7,"G");
 char c8[3];  strcpy(c8,"H");
 char c9[3];   strcpy(c9,"I");
 insert_kd(&k, 1,c1, 6.0 ,2.0);
 insert_kd(&k, 1,c2, 7.0 ,2.0);
 insert_kd(&k, 1,c3, 2.0 ,9.0);
 insert_kd(&k, 1,c4, 3.0 ,6.0);
 insert_kd(&k, 1,c5, 4.0 ,8.0);
 insert_kd(&k, 1,c6, 8.0 ,4.0);
 insert_kd(&k, 1,c7, 5.0 ,3.0);
 insert_kd(&k, 1,c8, 1.0 ,5.0);
 insert_kd(&k, 1,c9, 9.0 ,5.0);
 
  traverse_kd(k);



}
**/
void  delete_kd(KDTree *t);
void  check_availability(KDTree *t );
void  search (KDTree *t);
void  findMin_in_cp(KDTree *t);