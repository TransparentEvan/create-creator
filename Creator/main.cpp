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

void head(FILE*f,char s[100], int *a)
{
	fprintf(f, "<");
	fputs(s, f);
    fprintf(f, "num=%d", *a);
	fprintf(f, "  >\n");
	fprintf(f, "  ");
}
void end(FILE*f, char s[100])
{
	fprintf(f, "</");
	fputs(s, f);
	fprintf(f, ">\n");
}
void print_question(FILE*f, char s1[1000], char s2[1000], int *b)
{
	fprintf(f, "<question  ");
	fprintf(f, "num=%d>\n", *b);
	fprintf(f, "  ");
	fputs(s1, f);
	fprintf(f, "\n");
	fprintf(f, "  ");
	fputs(s2, f);
}
void print_chapter(FILE *f, struct chapter s, int *a,int *b)//aΪ�ڼ���,bΪ�ڼ�������ļ�����
{
	int num ,i; 
	head(f, s._chaptername, a);
	for (*b = 0;; *b++)
	{
		if (strcmp(s._question[*b], "\0"))  break;
		print_question(f, s._question[*b], s._answer[*b], b);
	}
	end(f, s._chaptername);
}
void print_subject(FILE*f, struct subject s, int*a, int *b, int *c)
{
	head(f, s._subjectname, c);

	end(f, s._subjectname);
}
void print_homework(FILE*f, struct homework s, int*a, int*b, int *c)
{
	head(f, "homework",);
}
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
	int *PROJECT, *SECTION, *QA;
	*PROJECT = 0, *SECTION = 0, *QA = 0;
	if ((fp=fopen("homework.xml", "w"))== NULL)
	{
		printf("Open xml error\n");
		return 0;
	}
	print_homework(fp,computerscience,PROJECT,SECTION,QA );
	fclose(fp);
	return 0;
}