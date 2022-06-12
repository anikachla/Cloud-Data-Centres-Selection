#include <stdbool.h>

typedef struct lf_node
{ float data;
  struct lf_node *prev;
  struct lf_ode *next; 
 }node;

typedef lf_node* float_List;


void init_float_list(_float_list *L);
void append(float_list *L,float d);
void display(float_list L);

typedef struct ls_node
{ char *data;
  struct ls_node *prev;
  struct ls_ode *next; 
 }node;

typedef ls_node* str_List;


void init_float_list(str_list *L);
void append(str_list *L, char* d);
void display(str_list L);

