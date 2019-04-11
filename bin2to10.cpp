/*二进制转换为十进制、八进制、十六进制堆栈实现*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define STACK_INIT_SIZE 20//定义堆栈最大容量
#define STACKINCREMENT 10//定义每次追加的长度

typedef char ElemType;//堆栈定义
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)//建立一个空的堆栈
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		return;
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)//压栈操作
{
	if (s->top - s->base >= s->stackSize)//判断堆栈是否满
	{
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));//如果满了追加空间
		if (!s->base)
		{
			return;//判断是否追加成功
		}
	}
	*(s->top) = e;//压入新的数据元素e
	s->top++;//头指针++
}

void Pop(sqStack *s, ElemType *e)//弹出堆栈内的数据元素
{
	if (s->top == s->base)//判断堆栈是否为空
	{
		return;
	}
	*e = *--(s->top);
}

int stackLen(sqStack s)//计算堆栈当前的容量
{
	return(s.top - s.base);
}

char ToHexChar(char c)
{
	switch (c)
	{
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	default:
		return c + 48;//字符0~9转换
	}
}
int main()
{   /*
	//二进制转换为十进制
	ElemType c;//数据类型
	sqStack s;//堆栈名称
	int len, i, sum = 0;

	InitStack(&s);//建立一个堆栈为s的空栈

	printf("请输入二进制数，输入#符号表示结束！\n");
	scanf_s("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf_s("%c", &c);
	}
	getchar();//把'\n'从缓冲区去掉
	len = stackLen(s);
	printf("栈的当前容量是：%d\n", len);
	for (i = 0; i < len; i++)
	{
		Pop(&s, &c);
		sum = sum + (c - 48)*pow(2, i);
	}
	printf("转化为十进制数是：%d\n", sum);
	
	//二进制转换为八进制
	ElemType c;
	sqStack s, soct;
	int len, lenoct, i, temp = 0;
	InitStack(&s);
	InitStack(&soct);

	printf("输入二进制数，以'#'结束\n");
	scanf_s("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf_s("%c", &c);
	}
	getchar();//把'\n'从缓冲区去掉
	len = stackLen(s);
	printf("二进制栈当前容量是:%d\n", len);

	int count = 0;
	for (int i = 0; i < len; i++)
	{
		Pop(&s, &c);
		temp = temp + (c - 48)*pow(2, count);
		count++;
		if (count == 3 || s.top == s.base)
		{
			Push(&soct,temp);//低位放在栈底
			temp = 0;
			count = 0;
		}
	}
	lenoct = stackLen(soct);
	printf("八进制栈当前容量是:%d\n", lenoct);

	printf("二进制转换为八进制是:");
	for (i = 0; i < lenoct; i++)
	{
		Pop(&soct, &c);
		printf("%d", c);
	}
	printf("\n");
	*/
	//二进制转换为十六进制
	ElemType c;
	sqStack s, shex;
	int len, lenhex, i;
	double temp = 0;

	InitStack(&s);
	InitStack(&shex);
	printf("输入二进制数，以'#'结束\n");
	scanf_s("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf_s("%c", &c);
	}
	getchar();

	int count = 0;
	len = stackLen(s);
	printf("二进制栈当前容量是：%d\n", len);
	for (i = 0; i < len; i++)
	{
		Pop(&s, &c);
		temp = temp + (c - 48)*pow(2, count);
		count++;
	}
	if (count == 4 || s.top == s.base)
	{
		Push(&shex, temp);
		count = 0;
		temp = 0;
	}
	lenhex = stackLen(shex);
	printf("十六进制栈当前容量是：%d \n",lenhex);

	printf("二进制转换为十六进制为：");
	char tempChar;
	for (i = 0; i < lenhex; i++)
	{
		Pop(&shex, &c);
		tempChar = ToHexChar(c);
		printf("%c", tempChar);
	}
	printf("\n");
	
	system("pause");
	return 0;
}