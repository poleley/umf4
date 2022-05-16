#ifndef UMF4_LIN_ALG_H
#define UMF4_LIN_ALG_H

#include "struct.h"
#include "utils.h"
#include <vector>
#include <cmath>

vector<double> operator- (
        const vector<double> &v1,
        const vector<double> &v2
) {

    vector<double> res(v1.size());

    for (int i = 0; i < res.size(); i++) {
        res[i] = v1[i] - v2[i];
    }

    return res;
}

vector<double> operator+ (
        const vector<double> &v1,
        const vector<double> &v2
) {

    vector<double> res(v1.size());

    for (int i = 0; i < res.size(); i++) {
        res[i] = v1[i] + v2[i];
    }

    return res;
}

vector<double> operator*(
        double coef,
        const vector<double> &x
) {
    vector<double> res(x.size());
    for (int i = 0; i < res.size(); i++) {
        res[i] = coef * x[i];
    }
    return res;
}

vector<double> mult_A_on_x(const matrix &A, const vector<double> &x) {
    vector<double> res(x.size());

    for (int i = 0; i < x.size(); i++) {
        res[i] = A.di[i] * x[i];
        for (int j = A.ig[i]; j < A.ig[i + 1]; j++) {
            res[i] += A.ggl[j] * x[A.jg[j]];
            res[A.jg[j]] += A.ggu[j] * x[i];
        }
    }
    return res;
}

vector<double> mult_At_on_x(const matrix &A, const vector<double> &x) {
        vector<double> res(x.size());
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = A.di[i] * x[i];
            int i0 = A.ig[i];
            int i1 = A.ig[i + 1];
            for (int k = i0; k < i1; k++)
            {
                int j = A.jg[k];
                res[j] += A.ggl[k] * x[i];
                res[i] += A.ggu[k] * x[j];
            }
        }
        return res;
}

double dot_prod(
        const vector<double> &x1,
        const vector<double> &x2
) {
    double res = 0.0;
    for (int i = 0; i < x1.size(); i++) {
        res += x1[i] * x2[i];
    }
    return res;
}

double norm(const vector<double> &x) {
    return sqrt(dot_prod(x, x));
}

#endif //UMF4_LIN_ALG_H
