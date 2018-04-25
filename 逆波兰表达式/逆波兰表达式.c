#include"Stack.h"
void PostfixExpression(const char *str)
{
	Stack s; //����һ��ջ������������
	StackInit(&s, 100);  //������ص㣬��ʼ����������(��Ϊջ�Ƕ�̬ջ����ʼ��ջ�Ż��ղ=ջ���ٿռ�)
	//iʱѭ��������data��ÿ���ַ�ת��������֣�sum�Ǳ��ʽ�е�����result�����������Ľ��
	int i = 0,data=0,sum=0,result=0;
	//����������
	int count1 = 0, count2 = 0;
	//�ж��ַ����Ƿ�Ϊ��
	if (str == NULL)
		return;
	//ʵ�ֲ���
	while (str[i] != '\0')
	{	
		//�����һ�������ַ�������ѭ��
		if (str[i] >= '0'&&str[i] <= '9')
		{
			sum = 0;//ÿ�ν���ѭ��ǰ����ֵ
			while (str[i] != ' ')
			{
				//ת��ÿ���ַ�Ϊ����
				data = str[i] - '0';
				sum = data + sum * 10;
				i++;//֮��ָ�����
			}
			//ѭ������˵����ǰ�ַ��ǿո񣬲�������ǰһ���ַ�һ���������ַ�����ʱ�Ϳ��԰ѵ�ǰsum��ֵѹ��ջ��
			StackPush(&s, sum);
			i++;//ָ����Ƶ��¸��ַ�
		}
		else 
			//��������ַ�����ôֻ���ǲ����������ǿո��ˣ���������ǿո񣬸ÿո�ǰһ���ַ�һ���ǲ�����
			if(str[i]=='+'|| str[i] == '-' || str[i] == '*' || str[i] == '/'  )
		{
				//�ֱ�ȡջ�е����������������ҳ�ջ
			count2= StackTop(&s);StackPop(&s);
			count1 = StackTop(&s); StackPop(&s);
			//ִ�в�ͬ����������
			switch (str[i])
			{
				case '+':
				{
					result = count1 + count2;//�õ����֮��ѹջ
					StackPush(&s, result);
					i++; continue;//ָ���ٺ���
				}
				//��ͬ
				case '-':
				{
					result = count1 - count2;
					StackPush(&s, result);
					i++; continue;
				}
				case '*':
				{
					result = count1 * count2;
					StackPush(&s, result);
					i++; continue;
				}
				case '/':
				{
					if (count2 == 0)return;
					result = count1 / count2;
					StackPush(&s, result);
					i++; continue;
				}
			}	
		}
		//���е���һ������ֻ��һ�ֿ��ܣ���ǰ�ַ��ǿո񣬲�����ǰһ���ַ�һ���ǲ���������ʱֻ��Ҫָ����Ƽ���
			else i++;
	}
	//���ѭ�����������ַ�����ȡ��������ӡ��ǰջ����ֵ����
	printf("%d\n", StackTop(&s));
	return;
}