#include "func.h"
using namespace std;
optional<double> meanlength(const vector<double>& aaa)
{
    if(aaa.empty())
    {
        return nullopt;
    }
    double s = 0.0;
    for(double m : aaa)
    {
        s+=m;
    }
    double ave=s/aaa.size();
    return ave; 
}
int cgo(const vector<double>& bbb, double thret)
{
    int count =0;
    for(double m : bbb){
        if(m>= thret)
        {
            count++;
        }
    }
    return count;
}
