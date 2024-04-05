//grade.cpp
#include "grade.h"
#include "median.h"
#include "student_info.h"
#include <vector>
#include <stdexcept>

double grade(double mt, double ft, double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}