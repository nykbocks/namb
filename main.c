#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "./include/File.h"
#include "./include/Lexer.h"
void tokenizer(){
	char lexed_buf[2048] = {0};
	for(int i = 0;i <= strlen(buffer);i++){
	  lexed_buf[i] = buffer[i];
	  if(strcmp(lexed_buf,"exit") == 0){
	    Token_t exit_token;
	    i++;
	    exit_token.token_type = EXIT_T;
	    exit_token.token_value = 0;
	    lex_add_token(exit_token);
	    Token_t exit_int_token;
	    exit_int_token.token_type = INT_T;
	    memset(lexed_buf, 0, sizeof(lexed_buf) * sizeof(char));
	    if(atoi(&buffer[i]) == 0){
	    printf("Error: 'exit' did not found a number. ");
	    }
	    exit_int_token.token_value = atoi(&buffer[i]);
	    lex_add_token(exit_int_token);
	  }
	  if(strcmp(&lexed_buf[i],";") == 0){
	    Token_t semi;
	    semi.token_type = SEMI_T;
	    semi.token_value = 0;
	    lex_add_token(semi);
	  }
	}
}
int main(int argc,char *argv[]){
        if(argc < 2){
        	printf("ex.: $> namb main.nb out\n");
        	return -1;
        } 

        read_file(argv[1]);
	tokenizer();
	FILE *output = fopen("out.asm","w");
	char out_asm[CAPACITY*8] =
	  "section .text\n"
	  "global _start\n"
	  "_start:\n\t";
	
	if(LEXER_TOKENS[0].token_type == EXIT_T){
	  strcat(out_asm,"mov rax,60\n\tmov rdi,");
	  //out_asm[strlen(out_asm)] = LEXER_TOKENS[0].token_value;
	  char buf[30];
	  sprintf(buf,"%d",LEXER_TOKENS[1].token_value);
	  strcat(out_asm,buf);
	  strcat(out_asm,"\n\tsyscall\n");
	  fprintf(output,"%s",out_asm);
	  fclose(output);
	}
	system("nasm -felf64 out.asm -o out.o");
	system("ld out.o -o out");
	system("rm out.asm out.o");
	
        return 0;
}
