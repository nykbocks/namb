#include "../include/File.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *buffer = NULL;
int see_i = 0;
void read_file(char *name){
        char *temp = (char*)malloc(CAPACITY*8);
        FILE *open_file = fopen(name,"r");
        int i = 0;
        buffer = (char*)malloc(CAPACITY*8);
        while(fgets(temp,2048,open_file)){
           strcat(buffer,temp); 
        };
        free(temp);
       	fclose(open_file);
}

char see_next(){
  char see = buffer[see_i+1];
  return see;
}
void take(){
  see_i++;
}
