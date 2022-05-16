#ifndef UMF4_STRUCT_H
#define UMF4_STRUCT_H

#include <vector>

using namespace std;

struct matrix {
    vector<int> ig;
    vector<int> jg;
    vector<double> ggl;
    vector<double> ggu;
    vector<double> di;
};

struct params {
    int n;
    int maxIter;
    double eps;
    double delta;
};

#endif //UMF4_STRUCT_H
