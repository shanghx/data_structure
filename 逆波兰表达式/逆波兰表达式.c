#include"Stack.h"
void PostfixExpression(const char *str)
{
	Stack s; //定义一个栈用来保存数据
	StackInit(&s, 100);  //这块是重点，初始化不能忘记(因为栈是动态栈，初始化栈才会给詹=栈开辟空间)
	//i时循环变量，data是每次字符转化后的数字，sum是表达式中的数，result是两数计算后的结果
	int i = 0,data=0,sum=0,result=0;
	//两个操作数
	int count1 = 0, count2 = 0;
	//判断字符串是否为空
	if (str == NULL)
		return;
	//实现部分
	while (str[i] != '\0')
	{	
		//如果是一个数字字符，进入循环
		if (str[i] >= '0'&&str[i] <= '9')
		{
			sum = 0;//每次进入循环前赋初值
			while (str[i] != ' ')
			{
				//转换每个字符为数字
				data = str[i] - '0';
				sum = data + sum * 10;
				i++;//之后指针后移
			}
			//循环跳出说明当前字符是空格，并且它的前一个字符一定是数字字符，此时就可以把当前sum的值压入栈中
			StackPush(&s, sum);
			i++;//指针后移到下个字符
		}
		else 
			//如果不是字符，那么只有是操作符或者是空格了，并且如果是空格，该空格前一个字符一定是操作符
			if(str[i]=='+'|| str[i] == '-' || str[i] == '*' || str[i] == '/'  )
		{
				//分别取栈中的两个操作数，并且出栈
			count2= StackTop(&s);StackPop(&s);
			count1 = StackTop(&s); StackPop(&s);
			//执行不同的算术操作
			switch (str[i])
			{
				case '+':
				{
					result = count1 + count2;//得到结果之后压栈
					StackPush(&s, result);
					i++; continue;//指针再后移
				}
				//下同
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
		//运行到这一步，就只有一种可能，当前字符是空格，并且它前一个字符一定是操作数，此时只需要指针后移即可
			else i++;
	}
	//外层循环跳出，该字符串读取结束，打印当前栈顶的值即可
	printf("%d\n", StackTop(&s));
	return;
}