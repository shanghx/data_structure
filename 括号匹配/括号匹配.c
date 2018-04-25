#include"Stack.h"
void MatchBrackets(const char *str)
{
	Stack s;
	StackInit(&s, 100);
	int i = 0;
	if (str == NULL)
		return;
	while (str[i] != '\0')
	{
		if (str[i] !='('&& str[i] != ')'&&
			str[i] !='['&& str[i] != ']'&&
			str[i] !='{'&& str[i] != '}' )
		{
			i++;
		}
		else if (str[i]=='('|| str[i] == '[' || str[i] == '{'  )
		{
			StackPush(&s, str[i]);
			i++;
		}
		else
		{
			if (str[i] == ')'&& StackTop(&s) == '(' ||
				str[i] == ']'&& StackTop(&s) == '[' ||
				str[i] == '}'&& StackTop(&s) == '{')
			{
				StackPop(&s);
				i++;
			}		
			else
			{ 
				if (StackEmpty(&s) == 0)
				{
					printf("¿®∫≈¥Œ–Ú∆•≈‰≤ª’˝»∑!!!\n");
					return;
				}
				else
				{
					printf("”“¿®∫≈∂‡”‡◊Û¿®∫≈!!!\n");
					return;
				}	
			}
		}
	}
	if (StackEmpty(&s))
	{
		printf("¿®∫≈∆•≈‰≥…π¶!!!\n");
		return;
	}
	else
	{
		{
			printf("◊Û¿®∫≈∂‡”‡”“¿®∫≈!!!\n");
			return;
		}
	}
	return;	
}