#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#define HASH_SIZE 677


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

typedef struct Hash
{
    Row_record* records[HASH_SIZE];    
    int size;

}Hash;

void init_hash(Hash *h );
void insert_hash(Hash *h, Row_record* x);
Row_record* search_hash(Hash *h , char key[]);
void delete_hash(Hash *h ,char key[]);
void display_hash(Hash h);

#endif

