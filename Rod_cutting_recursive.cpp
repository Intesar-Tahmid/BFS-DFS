// Recursive solution
#include <bits/stdc++.h>
using namespace std;

int rod_cutting_recursion(int price[], int index, int n)
{
    if (index == 0)
        return n * price[0];
    int notCut = rod_cutting_recursion(price, index - 1, n);
    int cut = INT_MIN;
    int rod_length = index + 1;

    if (rod_length <= n)
        cut = price[index] + rod_cutting_recursion(price, index, n - rod_length);
    return max(notCut, cut);
}
int main()
{
    
   int price[] = {0, 10, 24, 30, 40, 45};

   int n = 6;
    int profit = rod_cutting_recursion(price, 5, 6);
    cout << profit << endl;
   
}
