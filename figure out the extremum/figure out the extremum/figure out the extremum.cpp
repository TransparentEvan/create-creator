//ȡֵ����ͺ�������233
//�ȳ��������ֵ
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const double W = 0.729;

struct node
{
	float present;
	float vNow;
	float pbest;
}bird[30];

float gbest;

float obj_fun(float x)
{
	return;
}

void update(node now)//�� v��ʾ�����ٶȣ�p��ʾ����λ��
{
	now.vNow = now.vNow * W + 2 * rand() * (pbest - now.present) + 2 * rand() * (gbest - now.present);
	now.present = now.present + now.vNow;
}

int main()
{
	int i;
	for (i = 0; i < 30; i++)
	{
		bird[i].present = ( rand() / 31 );
		bird[i].vNow = ( rand() / 6 ) ;
	}
	for (int j = 0; j < 100; j++)
	{
		for (i = 0; i < 30; i++)
		{
			update(bird[i]);
			if (obj_fun(bird[i].pbest) < obj_fun(bird[i].present))
			{
				bird[i].pbest = bird[i].present;
			}
			if (obj_fun(bird[i].pbest) > obj_fun(gbest))
			{
				gbest = bird[i].pbest;
			}
		}
	}
	printf("%.2f\n", obj_fun( gbest ));
	return 0;
}