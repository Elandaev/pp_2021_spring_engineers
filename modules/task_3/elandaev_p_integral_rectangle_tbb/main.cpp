// Copyright 2021 Elandaev Pavel
#include <gtest/gtest.h>
#include <math.h>
#include "../../modules/task_3/elandaev_p_integral_rectangle_tbb/rectangle.h"
// #include <tbb/tick_count.h>

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

//TEST(INTEGRAL, Wrong_Interval_tbb) {
//    std::vector<double> start = {6};
//    std::vector<double> end = {4};
//    double step = 10000;
//    ASSERT_ANY_THROW(RecIntTbb(start, end, f1, step));
//}

//TEST(INTEGRAL, Step_Biggest_tbb) {
//    std::vector<double> start = {2};
//    std::vector<double> end = {4};
//    double step = 4;
//    ASSERT_ANY_THROW(RecIntTbb(start, end, f1, step));
//}
//
//TEST(INTEGRAL, Step_negative_tbb) {
//    std::vector<double> start = {2};
//    std::vector<double> end = {40};
//    double step = 0;
//    ASSERT_ANY_THROW(RecIntTbb(start, end, f1, step));
//}

TEST(INTEGRAL, Integral_func_const_tbb) {
    std::vector<double> start = {2};
    std::vector<double> end = {4};
    double step = 100;
    ASSERT_EQ(20, RecIntTbb(start, end, f1, step));
}

//TEST(INTEGRAL, Integral_func_2_tbb) {
//    std::vector<double> start = {-2};
//    std::vector<double> end = {4};
//    double step = 10000;
//    ASSERT_NEAR(24, RecIntTbb(start, end, f2, step), 0.1);
//}

//TEST(INTEGRAL, Integral_func_3_tbb) {
//    std::vector<double> start = {0};
//    std::vector<double> end = {12};
//    double step = 10000;
//    ASSERT_NEAR(12.1561460, RecIntTbb(start, end, f3, step), 0.1);
//}
//
//TEST(INTEGRAL, Integral_func_4_tbb) {
//    std::vector<double> start = {-4};
//    std::vector<double> end = {3};
//    double step = 10000;
//    ASSERT_NEAR(-0.276417, RecIntTbb(start, end, f4, step), 0.1);
//}

//TEST(INTEGRAL, Integral_func_7_tbb) {
//    std::vector<double> start = {1, 1};
//    std::vector<double> end = {2, 1.5};
//    double step = 10000;
//    ASSERT_NEAR(0.9375, RecIntTbb(start, end, f7, step), 0.1);
//}

// TEST(INTEGRAL, Integral_func_6_omp) {
//    std::vector<double> start = {1, 1, 0};
//    std::vector<double> end = {2, 1.6, 3};
//    double step = 0.01;
//    ASSERT_NEAR(0.680477, RecIntTbb(start, end, f6, step), 0.01);
//}



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

//TEST(INTEGRAL, Integral_func_7) {
//    std::vector<double> start = {1, 1};
//    std::vector<double> end = {2, 1.5};
//    double step = 10000;
//    ASSERT_NEAR(0.9375, RecIntTbb(start, end, f7, step), 0.1);
//}

// TEST(INTEGRAL, Integral_func_6) {
//    std::vector<double> start = {1, 1, 0};
//    std::vector<double> end = {2, 1.6, 3};
//    double step = 0.01;
//
//    double star = omp_get_wtime();
//    double m = RecIntTbb(start, end, f6, step);
//    double en = omp_get_wtime();
//    std::cout << "tbb time: " << en - star  << '\n';
//
//    star = omp_get_wtime();
//    double k = RecInt(start, end, f6, step);
//    en = omp_get_wtime();
//    std::cout << "seq time: " << en - star << '\n';
//
//    ASSERT_NEAR(k, m, 0.01);
//}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
