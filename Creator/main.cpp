#include<stdio.h>
struct chapter
{
	char _chaptername[100];
	char question[10][100];	//��һάΪ�����ţ��ڶ�άΪ��������
	char _answer[10][100];//�������Ӧ 
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