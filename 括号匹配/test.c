#include"Stack.h"
int main()
{
	
	char a[] = "(())abc{[(])}";
	char b[] = "(()))abc{[]}";
	char c[] = "(()()abc{[]}";
	char d[] = "(())abc{[]()}";
	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
	system("pause");
	return 0;
}
