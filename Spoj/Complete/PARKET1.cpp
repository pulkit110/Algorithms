#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int r, b;
    cin >> r >> b;

    int x = sqrt((4-r)*(4-r) - 16*b);

    int l = 4 + r + x;
    int w = 4 + r - x;

    cout << l/4 << " " << w/4;


    return 0;
}