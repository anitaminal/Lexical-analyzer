#include "main.h"

int is_keyword(char word[])
{
    
    char *keywords[32] = {"char", "int", "float", "double", "signed", "unsigned", "short", "long", "const", "volatile", "auto", "register", "extern", "static", "struct", "union", "enum", "void", "typedef", "goto", "return", "continue", "break", "if", "else", "for", "while", "do", "switch", "case", "default", "sizeof"};
    

    for (int k = 0; k < 32; k++)
    {
        if (strcmp(word, keywords[k]) == 0)
            return 1;
    }

    return 0;
}

int is_literal(char word[])
{
    if(word[0] == '\0')
        {
            return 0;
        }
    int dot = 0;
    
    for(int i = 0; word[i] != '\0'; i++)
    {
        
        if(word[i] == '.')
        {
            dot++;
        }
        if(!(isdigit(word[i])))
        {
                return 0;
        }
    }
    if(dot == 0)
    {
        return 1;
    }
    else if(dot >1)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}
int is_character(char *word)
{
    //calculate the length of the word 
    int len = strlen(word);
    //character is assigned as 'a', so minimum 3 chars, and have ' '
    if(len==3 && (word[0]=='\'') && (word[2]=='\''))
    {
        return 1;
    }
    return 0;
}
int is_string(char *word)
{
    int len = strlen(word);
    if((len>=2) && (word[0]=='"') &&(word[len-1]=='"'))
    {
        return 1;
    }
    return 0;
}

int is_operator(char ch)
{
    char operator[10] = {'+', '-', '*', '/', '%', '^', '&', '|', '<', '>'};
    for(int i= 0; i<10; i++)
    {
        if(operator[i] == ch)
        {
            //printf("%-20c: Operator\n", ch);
            return 1;
        }
        return 0;
    }

    
}
int is_symbol(char ch)
{
    char braces[] = { '(', ')', '[', ']', '{', '}', ',', '=', ':'};
    for(int i = 0; i<9; i++)
    {
        if(braces[i] == ch)
        {
            return 1;
        }
    }
    return 0;
}