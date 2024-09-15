#ifndef _FILE_H
#define _FILE_H
#define CAPACITY 2048
#include <stdio.h>
#include <stdlib.h>
extern char *buffer;
extern FILE *open_file;
extern char *temp;
extern int see_i;
char see_next();
void take();
void read_file(char *name);
#endif
