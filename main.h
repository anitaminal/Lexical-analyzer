
#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<string.h>
#include<ctype.h>


int process_word(char *word);
int is_keyword(char *word);

int is_literal(char *word);
int is_operator(char ch);

int is_character(char *word);
int is_string(char *word);

int is_operator(char ch);
int is_symbol(char ch);

#endif
