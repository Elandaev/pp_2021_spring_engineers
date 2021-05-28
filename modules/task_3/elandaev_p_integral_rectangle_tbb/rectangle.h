// Copyright 2021 Elandaev Pavel
#ifndef MODULES_TASK_3_ELANDAEV_P_INTEGRAL_RECTANGLE_TBB_RECTANGLE_H_
#define MODULES_TASK_3_ELANDAEV_P_INTEGRAL_RECTANGLE_TBB_RECTANGLE_H_

#include <cmath>
#include <vector>
#include <utility>
#include <functional>
#include <iostream>
#include <tbb/tbb.h>

void iterplus(std::vector<int> *B, int it, const std::vector<std::vector<int>> &p);
double RecInt(std::vector<double> start,
              std::vector<double> end,
              std::function<double(std::vector<double>)> f,
              double step);
double RecIntTbb(std::vector<double> start,
    std::vector<double> end,
    std::function<double(std::vector<double>)> f,
    int countstep);
#endif  // MODULES_TASK_3_ELANDAEV_P_INTEGRAL_RECTANGLE_TBB_RECTANGLE_H_
