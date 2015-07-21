using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PsoPlanning.Pso;

// function x^3 - x^2 + x;
namespace PsoApp
{
    class Program
    {
        public const int VMAX = 5;
        public const int POS_RIGHT = 200;
        public const int POS_LEFT = -200;
        public const double W = 0.729;
        public const int c = 2;
        public class Particle<double , double > : BaseParticle <double, double>
        {
            public override void AfterVelocityUpdated()
            {
                //<summary>
                // check if the V is bigger than the VMAX
                //</summary>
                int i;
                for( i = 0 ; i < CurVelocity.Length ; i ++ )
                    if(CurVelocity[i] > VMAX )
                    {
                        CurVelocity[i] = VMAX;
                    }
                throw new NotImplementedException();
             }
            public override void AfterPositionUpdated()
            {
                int i;
                //check if the position is out of the bound
                for( i = 0 ; i < CurPosition.Length ; i ++ )
                {
                    if( CurPosition[i] > POS_RIGHT )
                    {
                        CurPosition[i] = POS_RIGHT;
                    }
                    else if( CurPosition[i] < POS_LEFT )
                    {
                        CurPosition[i] = POS_LEFT;
                    }
                }
                throw new NotImplementedException();
            }
            public override void UpdatePosition()
            {
                int i;
                for (i = 0; i < CurVelocity.Length; i++)
                {
                    CurPosition[i] = CurPosition[i] + CurVelocity[i];
                }
                throw new NotImplementedException();
            }
            public override int CalFitness()
            {
                
                throw new NotImplementedException();
            }
            public override void UpdateVelocity( BaseParticle<double, double> bestParticle )
            {
                 
                throw new NotImplementedException();

            }
        }
        static void Main(string[] args)
        {

         }
    }
}
