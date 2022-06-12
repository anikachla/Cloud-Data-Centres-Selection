#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void init_float_list(float_list *L)
{
    *L= NULL;

}
void append(float_list *L,float d)
{
    lf_node nn = (lf_node*) malloc(sizeof(lf_node));
    nn->prev=NULL;
    nn->next=NULL;
    nn->data= d;

    if(*L==NULL)
     {
         *L= nn;
         return;
     }
      lf_node* ptr=*L;
      while(ptr->next)
      {
          ptr=ptr->next;
      }
      ptr->next=nn;
      nn->prev= ptr;


}
void display(float_list L);




void init_float_list(str_list *L);
void append(str_list *L, char* d);
void display(str_list L);

