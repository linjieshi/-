/*������ת��Ϊʮ���ơ��˽��ơ�ʮ�����ƶ�ջʵ��*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define STACK_INIT_SIZE 20//�����ջ�������
#define STACKINCREMENT 10//����ÿ��׷�ӵĳ���

typedef char ElemType;//��ջ����
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)//����һ���յĶ�ջ
{
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		return;
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)//ѹջ����
{
	if (s->top - s->base >= s->stackSize)//�ж϶�ջ�Ƿ���
	{
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));//�������׷�ӿռ�
		if (!s->base)
		{
			return;//�ж��Ƿ�׷�ӳɹ�
		}
	}
	*(s->top) = e;//ѹ���µ�����Ԫ��e
	s->top++;//ͷָ��++
}

void Pop(sqStack *s, ElemType *e)//������ջ�ڵ�����Ԫ��
{
	if (s->top == s->base)//�ж϶�ջ�Ƿ�Ϊ��
	{
		return;
	}
	*e = *--(s->top);
}

int stackLen(sqStack s)//�����ջ��ǰ������
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
		return c + 48;//�ַ�0~9ת��
	}
}
int main()
{   /*
	//������ת��Ϊʮ����
	ElemType c;//��������
	sqStack s;//��ջ����
	int len, i, sum = 0;

	InitStack(&s);//����һ����ջΪs�Ŀ�ջ

	printf("�������������������#���ű�ʾ������\n");
	scanf_s("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf_s("%c", &c);
	}
	getchar();//��'\n'�ӻ�����ȥ��
	len = stackLen(s);
	printf("ջ�ĵ�ǰ�����ǣ�%d\n", len);
	for (i = 0; i < len; i++)
	{
		Pop(&s, &c);
		sum = sum + (c - 48)*pow(2, i);
	}
	printf("ת��Ϊʮ�������ǣ�%d\n", sum);
	
	//������ת��Ϊ�˽���
	ElemType c;
	sqStack s, soct;
	int len, lenoct, i, temp = 0;
	InitStack(&s);
	InitStack(&soct);

	printf("���������������'#'����\n");
	scanf_s("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf_s("%c", &c);
	}
	getchar();//��'\n'�ӻ�����ȥ��
	len = stackLen(s);
	printf("������ջ��ǰ������:%d\n", len);

	int count = 0;
	for (int i = 0; i < len; i++)
	{
		Pop(&s, &c);
		temp = temp + (c - 48)*pow(2, count);
		count++;
		if (count == 3 || s.top == s.base)
		{
			Push(&soct,temp);//��λ����ջ��
			temp = 0;
			count = 0;
		}
	}
	lenoct = stackLen(soct);
	printf("�˽���ջ��ǰ������:%d\n", lenoct);

	printf("������ת��Ϊ�˽�����:");
	for (i = 0; i < lenoct; i++)
	{
		Pop(&soct, &c);
		printf("%d", c);
	}
	printf("\n");
	*/
	//������ת��Ϊʮ������
	ElemType c;
	sqStack s, shex;
	int len, lenhex, i;
	double temp = 0;

	InitStack(&s);
	InitStack(&shex);
	printf("���������������'#'����\n");
	scanf_s("%c", &c);
	while (c != '#')
	{
		Push(&s, c);
		scanf_s("%c", &c);
	}
	getchar();

	int count = 0;
	len = stackLen(s);
	printf("������ջ��ǰ�����ǣ�%d\n", len);
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
	printf("ʮ������ջ��ǰ�����ǣ�%d \n",lenhex);

	printf("������ת��Ϊʮ������Ϊ��");
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