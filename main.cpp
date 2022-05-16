#include <iostream>
#include "utils.h"
#include "BSG.h"

using namespace std;

int main() {
    int test_num;
    cout << "Enter test_num:";
    cin >> test_num;
    cout << endl;

    params params{};
    matrix matrix;
    vector<double> b;

    input(test_num, matrix, params, b);
    BSG(matrix, b, params);



    return 0;
}
