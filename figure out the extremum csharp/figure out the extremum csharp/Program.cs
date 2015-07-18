using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//函数 x^3 - x^2 + x 
//区间 -30，30
//先尝试输出极值
//刚刚入手c# 写的乱七八糟
//将原有的结构取消 改成了数组 用下标表示第几个粒子
//从网上找了一个随机数的函数用来产生随机数，只是将int【】 全改成了double【】
//缺少0到1 的随机数产生 以及遍历过程
namespace figure_out_the_extremum_csharp
{
    class Program
    {
        public static double[] present = new double[NUM_OF_BIRD];
	    public static double[] vNow = new double [NUM_OF_BIRD]; 
	    public static double[] pbest = new double [NUM_OF_BIRD];
        public static double gbest = 0;//初值定为0

        public  const int TIME_OF_COUNT = 50;//迭代50次
        public  const int NUM_OF_BIRD = 30;//鸟数
        public const double W = 0.729;//权重
        public const int c = 2;//学习因子

        public static double getPercentOfStudy( )
        {
            Random rd = new Random();
            int a = rd.Next(100);
            double f =( double )( a * 0.01 );
            return f;
        }

        public static double getNum(double[] arrNum,double tmp,int minValue,int maxValue,Random ra)
        {
              int n=0;
              while (n<=arrNum.Length-1)
              {
                    if (arrNum[n] == tmp) //利用循环判断是否有重复
                    {
                        tmp = ra.Next(minValue,maxValue); //重新随机获取。
                        getNum(arrNum, tmp, minValue, maxValue, ra);//递归:如果取出来的数字和已取得的数字有重复就重新随机获取。
                    }
               }
              return tmp;
         }

        public static double[] getRandomNum(int num,int minValue,int maxValue)//num表示数量 ，min表示开头 max 表示结尾
        {
                Random ra=new Random( unchecked ( (int)DateTime.Now.Ticks) );
                double[] arrNum = new double[num];
                double tmp=0;
                for (int i = 0;i <= num-1 ; i++ )
                {
                tmp = ra.Next( minValue, maxValue ); //随机取数
                arrNum[i] = getNum(arrNum, tmp, minValue, maxValue, ra); //取出值赋到数组中
                }
                return arrNum;
         }

        public static void update( int i )//以 v表示当期速度，p表示当期位置
            {
               double r1 = getPercentOfStudy( );
               double r2 = getPercentOfStudy( );
	           vNow[i] = vNow[i] * W + c * r1 * (pbest[i] - present[i]) + c * r2 * (gbest - present[i]);//需插入零一随机函数
	           present[i] = present[i] + vNow[i];
            } 
       
       public static double obj_fun( double x )
          {
	          return x*x*x - x*x + x;
          }
        public static void check( int i )
        {
            if( obj_fun( pbest[i]) > obj_fun( present[i] ) )
            {
                pbest[i] = present[i];
            }
            if( obj_fun( pbest[i] ) > obj_fun( gbest ) )
            {
                gbest = pbest[i];
            }
        }
        static  void Main( string[] args )
         {
            double ans = 0;//答案
            int i;//循环变量
          
            present =  getRandomNum( 30 , -30, 30 );//给present 赋值
            vNow = getRandomNum(30, -5, 5 );//给速度赋值e
            pbest = getRandomNum( 30 ,-30, 30);//pbest 的初值

         for (int j = 0; j < 5; j++)
            {
                //Console.WriteLine(j);
                for (i = 0; i < 30; i++)
                {
                    update(i);
                    check(i);
                  //  Console.WriteLine(i);
                }
            }
            
            ans = obj_fun ( Program.gbest );  
            Console.WriteLine(ans);
            Console.ReadLine();

           }
    }
}
