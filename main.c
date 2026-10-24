
#include<stdio.h>

#include<ctype.h>
#include "main.h"

#define MAX_BUFF_SIZE 100

 char word[MAX_BUFF_SIZE];
 
int main(int argc, char *argv[])
{
  
    //validate the command line argument
    if(argv[1] == NULL)
    {
        printf("Invalid input\nFile not passed\n");
        return -1;
    }
    //declare a character array
    char ch;
    int ret;
    
    //declare the file pointer
    FILE *fptr;
    int i = 0;
    //open the file in read mode
    fptr = fopen(argv[1], "r");
    //file check: file not opened successfully print error,and stop execution
    if(fptr == NULL)
    {
        printf("Failed to open file\n");
        return -1;
    }
    else
    {
        printf("Open:%-20s: success\n", argv[1]);
    }
    if((ch=fgetc(fptr)) == EOF)
    {
        printf("File is empty\n");
        return 0;
    }
    else
    {
        printf("Parsing:%-20s: Started\n", argv[1]);
        rewind(fptr);
        while((ch=fgetc(fptr))!= EOF)
        {
            if(isalnum(ch) || ch == '.' || ch == '_' || ch == '"' || ch == '\'')
            {
                    word[i++] = ch;
            }
            else
            {
                if(i != 0)
                {
                    word[i] = '\0';
                    i = 0;
                
                //printf("%s\n", word);
                if(is_keyword(word))
                {
                        printf("%-20s : Keyword\n", word);
                }
                else if((ret = (is_literal(word)))!= 0)
                {
                        if(ret == 1)
                        {
                            printf("%-20s: Integer Constant\n", word);
                        }
                        else
                        {
                            printf("%-20s: Floating value\n", word);
                        }
                }
                else if(is_character(word))
                {
                        printf("%-20s: Character literal\n", word);
                }
                else if(is_string(word))
                {
                        printf("%-20s: String literal\n", word);
                }
                else
                        printf("%-20s: Identifier\n", word);
                memset(word, 0, sizeof(word));
            }    
            }
             
        
            if(ch == '#')
            {//check the preprocessor directive
                word[0] = '#';

                if (fscanf(fptr,"%[^\n]", word + 1) == 1)
                {
                    printf("%s : Preprocessor directive\n", word);
                }

                memset(word, 0, sizeof(word));
                continue;
            }
             else if(ch == ';')
            {
                printf("%-20c: Semicolon\n", ch);
            } 
            else if(is_symbol(ch))
            {
                printf("%-20c: Symbol\n", ch);
            }
             else if(is_operator(ch))
            {
                printf("%-20c: operator\n", ch);
            }
            
       
             
            
        }
    }
     printf("\nParsing: %s\t: Done", argv[1]);
    //close the file 
    fclose(fptr);
    return 0;
    

} 