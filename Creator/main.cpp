#include<stdio.h>
#include "string.h"
//内容均已字符串形式存储
struct chapter
{
	char _chaptername[100];
	char _question[10][100];	//第一维为问题编号，第二维为问题内容
	char _answer[10][100];//与问题对应 
};
struct subject
{
	char _subjectname[100];
	struct chapter section[10];
};
struct homework
{
	int num;//表示第几次作业
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
void print_chapter(FILE *f, struct chapter s, int *a,int *b)//a为第几章,b为第几个问题的计数器
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
		<name> 函数 </name>
		<question1> 下列哪些是函数 </questong1>
		<answer> 都不是函数 </answer>
	</chapter1>
</subject1>
<subject2 name = "c language">
	<chapter1>
		<name> 变量 </name>
		<question1> 下列那些变量声明是合法的 </question1>
		<answer> 都是合法的 </answer>
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