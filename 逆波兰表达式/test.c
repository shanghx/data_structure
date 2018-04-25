#include"Stack.h"
int main()
{
	char str[] = "12 3 4 + * 6 - 8 2 / +";
	PostfixExpression(&str);
	system("pause");
	return 0;
}
