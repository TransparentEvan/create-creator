#include<stdio.h>
#include "string.h"
//���ݾ����ַ�����ʽ�洢
struct chapter
{
	char _chaptername[100];
	char _question[10][100];	//��һάΪ�����ţ��ڶ�άΪ��������
	char _answer[10][100];//�������Ӧ 
};
struct subject
{
	char _subjectname[100];
	struct chapter section[10];
};
struct homework
{
	int num;//��ʾ�ڼ�����ҵ
	subject project[3];
};

struct homework computerscience;
void print_question(FILE *f, )

/*<subject1 name = "math">
	<chapter1>
		<name> ���� </name>
		<question1> ������Щ�Ǻ��� </questong1>
		<answer> �����Ǻ��� </answer>
	</chapter1>
</subject1>
<subject2 name = "c language">
	<chapter1>
		<name> ���� </name>
		<question1> ������Щ���������ǺϷ��� </question1>
		<answer> ���ǺϷ��� </answer>
	</chapter1>
</subject2>*/
int main()
{
	FILE *fp;
	int PROJECT = 0, SECTION = 0, QA = 0;
	if ((fp=fopen("homework.xml", "w"))== NULL)
	{
		printf("Open xml error\n");
		return 0;
	}
	while (PROJECT<3 && SECTION<10 && QA<10)
	{
		
	}
		fclose(fp);
	return 0;
}