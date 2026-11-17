#include<iostream>
#include "func.h"
using namespace std;


int main() 
{
    cout << "开始测试" << endl;

    
    double threshold = 20.0;
    vector<double> data = {10.0, 20.0, 30.0}; 
    vector<double> empty_data;               
    auto result = meanlength(data);
    
    if (!result.has_value() || result.value() != 20.0) {
        cout << "均值计算不对" << endl;
        return -1; 
    }

   
    auto empty_result = meanlength(empty_data);
    if (empty_result.has_value()) {
        cout << "空数组不该算出来均值" << endl;
        return -2; 
    }

   
    int count = cgo(data, threshold);
   
    if (count != 2) {
        cout << "统计个数不对" << endl;
        return -3; 
    }

    
    cout << "全部测试通过" << endl;
    return 0; 
}
