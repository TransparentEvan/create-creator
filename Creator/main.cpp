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
void print_question(FILE *f, )

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