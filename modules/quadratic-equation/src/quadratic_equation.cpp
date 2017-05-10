// Copyright 2017 Pletnev Nikita

#include "include/quadratic_equation.h"
#include <math.h>
#include <string>
#include <vector>


QuadraticEquation::QuadraticEquation() : coef_a_(1), coef_b_(0), coef_c_(0) {}

QuadraticEquation::QuadraticEquation(
    const double coef_a, const double coef_b, const double coef_c) {
    SetCoefA(coef_a);
    SetCoefB(coef_b);
    SetCoefC(coef_c);
}

double QuadraticEquation::Discriminant() const {
    return coef_b_*coef_b_ - 4 * coef_a_*coef_c_;
}

void QuadraticEquation::SetCoefA(const double coef_a) {
    if (coef_a != 0)
        coef_a_ = coef_a;
    else
        throw std::string("The coefficient A can not be 0");
}

void QuadraticEquation::SetCoefB(const double coef_b) {
    coef_b_ = coef_b;
}

void QuadraticEquation::SetCoefC(const double coef_c) {
    coef_c_ = coef_c;
}

void QuadraticEquation::SetCoefficients(
    const double coef_a, const double coef_b, const double coef_c) {
    SetCoefA(coef_a);
    SetCoefB(coef_b);
    SetCoefC(coef_c);
}

double QuadraticEquation::GetCoefA(void) const {
    return coef_a_;
}

double QuadraticEquation::GetCoefB(void) const {
    return coef_b_;
}

double QuadraticEquation::GetCoefC(void) const {
    return coef_c_;
}

std::vector<double> QuadraticEquation::GetCoefficients(void) const {
    std::vector<double> result(3);
    result[0] = coef_a_;
    result[1] = coef_b_;
    result[2] = coef_c_;
    return result;
}

int QuadraticEquation::NumOfSolutions(void) const {
    int result = 1;
    if (Discriminant() < 0) result = 0;
    if (Discriminant() > 0) result = 2;
    return result;
}

double QuadraticEquation::GetX1(void) const {
    double result = 0;
    if (NumOfSolutions() > 0)
        result = (-coef_b_ + sqrt(Discriminant())) / 2 * coef_a_;
    return result;
}

double QuadraticEquation::GetX2(void) const {
    double result = 0;
    if (NumOfSolutions() < 2)
        result = GetX1();
    else
        result = (-coef_b_ - sqrt(Discriminant())) / 2 * coef_a_;
    return result;
}

