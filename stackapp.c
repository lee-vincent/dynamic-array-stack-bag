/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
    
    DynArr *opening;
    opening = newDynArr(8);
    char ch;
    while((ch = nextChar(s)) != '\0')   {
        if(ch == '(' || ch == '[' || ch == '{') {
            pushDynArr(opening, ch);
        } else if (ch == ')') {
            if(isEmptyDynArr(opening) || topDynArr(opening) != '(') {
                deleteDynArr(opening);
                return 0;
            } else {
                popDynArr(opening);
            }
        } else if (ch == ']') {
            if(isEmptyDynArr(opening) || topDynArr(opening) != '[') {
                deleteDynArr(opening);
                return 0;
            } else {
                popDynArr(opening);
            }
        } else if(ch == '}') {
            if(isEmptyDynArr(opening) || topDynArr(opening) != '{') {
                deleteDynArr(opening);
                return 0;
            } else {
                popDynArr(opening);
            }
        }
    }
    
    if(isEmptyDynArr(opening)) {
        deleteDynArr(opening);
        return 1;
    } else {
        deleteDynArr(opening);
        return 0;
    }
    
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];
//    char array[] = {'(', '[', '(', '{', '}', '(', ')', ')', ']', /*')',*/ '\0'};
//    char* s = array;
	int res;
    if(s == 0) {
        printf("No string provided");
        exit(EXIT_FAILURE);
    }
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

