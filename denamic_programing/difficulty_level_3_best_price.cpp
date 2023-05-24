#include <iostream>
#include <vector>

using namespace std;

//maximum price for cut pieces. prices[i] - price for resource with i + 1 weight.
int maxPrice(const vector<int>& prices) {
    vector<vector<int>> p(prices.size() + 1, vector<int>(prices.size(), 0));
    
    for(int i = 0; i < prices.size(); ++i) {
        p[1][i] = prices[0];
    }
    for(int i = 0; i < prices.size(); ++i) {
        p[i + 1][0] = prices[i];
    }
    
    int res = 0;
	
	//p[weight, number of cuts] = max(p[w - z, n -  1] + p[z, n - 1]) for 1 <= z < w;
	
    for(int i = 2; i < p.size(); ++i) {
        for(int j = 1; j < prices.size(); ++j) {
            
            for(int z = 1; z < i; ++z) {
                p[i][j] = max(p[i][j], p[i - z][j - 1] + p[z][j - 1]);
                res = max(res, p[i][j]);
            }
        }
    }
    
    return res;
}

int main()
{
    cout<<maxPrice({1,5,8,9,10,17,17,20});

    return 0;
}