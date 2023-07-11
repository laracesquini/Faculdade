#include <stdio.h>
#include <math.h>

double dist(double, double);
double veloc(double, double);
double tempo(double, double);
double dist2(double, double, double);
double Vfinal(double, double, double);
double Vini(double, double, double);
double tempo2(double, double, double);


int main()
{
    int N, O, i;
    double v, t, d, a;

    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%d", &O);

        if(O==1)
        {
            scanf("%lf", &v);
            scanf("%lf", &t);
            printf("%.2lf\n", dist(v, t));
        }
        else if(O==2)
        {
            scanf("%lf", &d);
            scanf("%lf", &t);
            printf("%.2lf\n", veloc(d, t));
        }
        else if(O==3)
        {
            scanf("%lf", &d);
            scanf("%lf", &v);
            printf("%.2lf\n", tempo(d, v));
        }
        else if(O==4)
        {
            scanf("%lf", &v);
            scanf("%lf", &a);
            scanf("%lf", &t);
            printf("%.2lf\n", dist2(v, a, t));
        }
        else if(O==5)
        {
            scanf("%lf", &v);
            scanf("%lf", &a);
            scanf("%lf", &t);
            printf("%.2lf\n", Vfinal(v, a, t));
        }
        else if(O==6)
        {
            scanf("%lf", &d);
            scanf("%lf", &a);
            scanf("%lf", &t);
            printf("%.2lf\n", Vini(d, a, t));
        }
        else
        {
            scanf("%lf", &d);
            scanf("%lf", &v);
            scanf("%lf", &a);
            printf("%.2lf\n", tempo2(d, v, a));
        }
    }
}

double dist(double V, double T)
{
    double D;
    D = V*T;
    return D;
}
double veloc(double D, double T)
{
    double V;
    V = D/T;
    return V;
}
double tempo(double D, double V)
{
    double T;
    T = D/V;
    return T;
}
double dist2(double V, double A, double T)
{
    double D;
    D = (V*T)+(A*T*T)/2;
    return D;
}
double Vfinal(double Vini, double A, double T)
{
    double V;
    V = Vini+(A*T);
    return V;
}
double Vini(double D, double A, double T)
{
    double V;
    V = (D-(A*T*T)/2)/T;
    return V;
}
double tempo2(double D, double V, double A)
{
    double T, Vf;
    Vf = sqrt((V*V) + (2*D*A));
    T = (Vf - V)/A;
    return T;
}
