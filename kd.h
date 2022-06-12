
//#include "list.h"
#ifndef KD_H
#define KD_H

#include <stdio.h>
#include "hash.h"

typedef struct kdnode
{
   float lati;
   float longi;
   char cc[3];

   struct kdnode* left;
   struct kdnode* right;
   struct kdnode* parent;


}kdnode;

typedef kdnode* KDTree;

void init_kd(KDTree *t);
void traverse_kd(KDTree t);
void  insert_kd(KDTree * t,  int cp , char ccode[], float latitude, float longitude);

void  delete_kd(KDTree *t);
void  check_availability(KDTree *t );
void  search (KDTree *t);
void  findMin_in_cp(KDTree *t);






/**
typedef struct Row_record
{
    char ccode[3];
    float latitude;
    float longitude;
    char cname[50];
    char ip[16];
    int avail;
    int ldeg;

}Row_record;

**/
#endif