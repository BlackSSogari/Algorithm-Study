#pragma once

#include <stdlib.h>

typedef enum
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLE = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
}SYMBOL;

int				IsNumber(char Cipher);
unsigned int	GetNextToken(char* Expression, char* Token, int* TYPE);
int				GetPriority(char Operator, int InStack);
int				IsPrior(char OperatorInStack, char OperatorInToken);
void			GetPostfix(char* InfixExpression, char* PostfixExpression);
double			Calculate(char* PostfixExpression);