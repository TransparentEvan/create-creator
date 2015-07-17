using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//函数 x^3 - x^2 + x 
//区间 -30，30
//先尝试输出极值
//刚刚入手c# 写的乱七八糟
namespace figure_out_the_extremum_csharp
{
    class Program
    {
        public float gbest;
        public const double W = 0.729;//权重
        public const int c1 = 2;//学习因子
        public const int c2 = 2;
        public struct node
            {
    	       static float present;
	           static float vNow;
	            float pbest;
            };
        public static node[] bird = new node[30];
        public static void update( )//以 v表示当期速度，p表示当期位置
            {
	           now.vNow = now.vNow * W + 2 * rand() * (now.pbest - now.present) + 2 * rand() * (gbest - now.present);
	           now.present = now.present + now.vNow;
            } 
       float obj_fun(float x)
          {
	            return x*x*x - x*x + x;
          }
    }
    void Main(string[] args)
            {
               float ans;
               int i;
               ans = obj_fun ( Program.gbest );  
               Console.WriteLine("{0}",ans);
               Console.ReadLine();
            }
}

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
}