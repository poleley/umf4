#ifndef UMF4_UTILS_H
#define UMF4_UTILS_H

#include "struct.h"
#include <string>
#include <fstream>

using namespace std;

void input(int test_num, matrix &matrix, params &params, vector<double> &b) {
    ifstream fin;
    string path = to_string(test_num);

    fin.open(path + "/param.txt");
    fin >> params.n >> params.maxIter >> params.eps >> params.delta;
    fin.close();

    matrix.ig.resize(params.n + 1);
    fin.open(path + "/ig.txt");
    for (int &i: matrix.ig) {
        fin >> i;
    }
    fin.close();

    matrix.jg.resize(matrix.ig[params.n]);
    fin.open(path + "/jg.txt");
    for (int &i: matrix.jg) {
        fin >> i;
    }
    fin.close();

    matrix.di.resize(params.n);
    fin.open(path + "/di.txt");
    for (double &i: matrix.di) {
        fin >> i;
    }
    fin.close();

    matrix.ggl.resize(matrix.ig[params.n]);
    fin.open(path + "/gg.txt");
    for (double &i: matrix.ggl) {
        fin >> i;
    }
    fin.close();

    matrix.ggu.resize(matrix.ig[params.n]);
    fin.open(path + "/gg.txt");
    for (double &i: matrix.ggu) {
        fin >> i;
    }
    fin.close();

    b.resize(params.n);
    fin.open(path + "/vector.txt");
    for (double &i: b) {
        fin >> i;
    }
}

vector<double> init_guess(int n) {
    vector<double> x;
    x.resize(n, 1);
    return x;
}

void resize_vectors(
        vector<double> &x_prev,
        vector<double> &r,
        vector<double> &z,
        vector<double> &p,
        vector<double> &s,
        int n
) {
    x_prev.resize(n);
    r.resize(n);
    z.resize(n);
    p.resize(n);
    s.resize(n);
}

#endif //UMF4_UTILS_H
