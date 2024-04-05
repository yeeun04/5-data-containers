#pragma once
//grade.h

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, vector<double>&);
double gradew(const Student_info&);

#endif
