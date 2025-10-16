#ifndef MYLIB_H
#define MYLIB_H
#include <cmath>
#include <cstdlib>

#ifdef EXTERNC
extern "C" {
#endif

double findPi(long nthrows);
double magnitude(double re, double im);
  int mandel_test(double c_re, double c_im, int NTRIALS);
void mandel(double *img, double re1, double re2, double im1, double im2,
	    int nr, int ni, int NTRIALS=255);
  
#ifdef EXTERNC
}
#endif

extern "C" double HSVolume(int d, long long N, double r)
{
    std::srand(42);

    long long hits = 0;
    for (long long i = 0; i < N; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < d; ++j)
        {
            double x = 2.0 * rand() / double(RAND_MAX) - 1.0; // uniform in [-1,1]
            sum += x * x;
        }
        if (sum <= 1.0) hits++;
    }

    // cube volume = (2r)^d
    double Vcube = std::pow(2.0 * r, d);
    double V = (double)hits / N * Vcube;
    return V;
}

extern "C" long long count3d_cpp(int n) {
    long long count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                ++count;
    return count;
}
  
#endif // block to ensure header is only compiled once
