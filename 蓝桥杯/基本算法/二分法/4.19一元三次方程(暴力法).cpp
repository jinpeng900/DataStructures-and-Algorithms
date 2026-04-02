#include<bits/stdc++.h>
using namespace std;

double a , b , c , d;
double y(double x) {return a*x*x*x+b*x*x+c*x+d;}

int main()
{
    cin >> a >> b >> c >> d;
    for(double i = -100 ; i <= 100 ; i += 0.01)
    {
        double j = i + 0.01;
        double y1 = y(i) , y2 = y(j);
        if (y1 * y2 <= 0) printf("%.2lf " , (i+j) / 2);
    }
}