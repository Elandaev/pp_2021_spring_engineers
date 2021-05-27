// Copyright 2021 Elandaev Pavel
#include <math.h>
#include <gtest/gtest.h>
#include "../../modules/task_3/elandaev_p_integral_rectangle_tbb/rectangle.h"
#include <tbb/tick_count.h>

double f1(const std::vector<double> &x) {
    double res = 10;
    return res;
}

double f2(const std::vector<double> &x) {
    double res = x[0] * x[0];
    return res;
}

double f3(const std::vector<double> &x) {
    double res = sin(x[0]) + 1;
    return res;
}

double f4(const std::vector<double> &x) {
    double res = sin(x[0]) * cos(x[0]);
    return res;
}

double f5(const std::vector<double> &x) {
    double res = sin(x[0]) * cos(x[0]) * x[0] * x[0];
    return res;
}

double f6(const std::vector<double> &x) {
    double res = sin(x[0]) * cos(x[1]) * x[2];
    return res;
}

double f7(const std::vector<double> &x) {
    double res = x[0] * x[1];
    return res;
}

TEST(INTEGRAL, Integral_func_const_tbb) {
    std::vector<double> start = {2};
    std::vector<double> end = {4};
    double step = 100;
    ASSERT_EQ(20, RecIntTbb(start, end, f1, step));
}

TEST(INTEGRAL, Integral_func_5) {
    std::vector<double> start = {0};
    std::vector<double> end = {2};
    double step = 10000;

    tbb::tick_count star = tbb::tick_count::now();
    double m = RecIntTbb(start, end, f5, step);
    tbb::tick_count en = tbb::tick_count::now();
    std::cout << "seq time: " << static_cast<double>((en - star).seconds()) << '\n';

    tbb::tick_count starseq = tbb::tick_count::now();
    double k = RecInt(start, end, f5, 0.01);
    tbb::tick_count enseq = tbb::tick_count::now();
    std::cout << "tbb time: " << static_cast<double>((enseq - starseq).seconds()) << '\n';


    ASSERT_NEAR(k, m, 0.1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
