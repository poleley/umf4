#ifndef UMF4_BSG_H
#define UMF4_BSG_H

#include "lin_alg.h"
#include "utils.h"

bool stop(const matrix &matrix,
          const vector<double> &b,
          const vector<double> &x,
          const vector<double> &x_prev,
          const params &params,
          int i
) {
    if (i > params.maxIter)
        return true;

    if (norm(x - x_prev) / norm(x) < params.delta)
        return true;

    if (norm(mult_A_on_x(matrix, x) - b) / norm(b) < params.eps)
        return true;

    return false;
}

void BSG(matrix &matrix, vector<double> b, params params) {
    ofstream fout;

    int i = 0;
    double alpha, beta, pr_prev, pr;
    vector<double> x, x_prev, r, z, p, s, Az, Ats;

    resize_vectors(x_prev, r, z, p, s, params.n);

    x = init_guess(params.n);

    r = b - mult_A_on_x(matrix, x);
    p = z = s = r;

    do {
        x_prev = x;
        pr_prev = dot_prod(p, r);
        Az = mult_A_on_x(matrix, z);
        Ats = mult_At_on_x(matrix, s);

        alpha = pr_prev / dot_prod(s, Az);

        x = x + alpha * z;
        r = r - alpha * Az;
        p = p - alpha * Ats;

        beta = dot_prod(p, r) / pr_prev;

        z = r + beta * z;
        s = p + beta * s;

        i++;
    } while (!stop(matrix, b, x, x_prev, params, i));
}

#endif //UMF4_BSG_H
