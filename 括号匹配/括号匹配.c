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
					printf("���Ŵ���ƥ�䲻��ȷ!!!\n");
					return;
				}
				else
				{
					printf("�����Ŷ���������!!!\n");
					return;
				}	
			}
		}
	}
	if (StackEmpty(&s))
	{
		printf("����ƥ��ɹ�!!!\n");
		return;
	}
	else
	{
		{
			printf("�����Ŷ���������!!!\n");
			return;
		}
	}
	return;	
}