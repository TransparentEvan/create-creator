#include<stdio.h>
struct chapter
{
	char _chaptername[100];
	char question[10][100];	//第一维为问题编号，第二维为问题内容
	char _answer[10][100];//与问题对应 
};
struct subject
{
	char _subjectname[100];
	struct chapter section[10];
};
struct homework
{
	subject project[3];
};

struct subject computerscience[10];

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
	char filename[20] = { "xml" } , tmp_store[100];
	char tmp;
	if ((fopen(filename, "r")) == NULL)
	{
		printf("Open file error\n");
		return 0;
	}
	while ((tmp = fgetc(fp)) != EOF)
	{
		printf("%c", tmp);
	}
		fclose(fp);
	return 0;
}