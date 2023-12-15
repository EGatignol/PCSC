#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include "polynomial_1_to_n.hh"
#include "bissection.hh"
#include "classic_chord.hh"
#include "fixed_point.hh"
#include "newton.hh"
#include "result_method.hh"
#include "PlotConvergence.h"
#include <gtest/gtest.h>

// Déclarations globales
std::vector<std::vector<double>> coeffs_F1 = {{-1, 7, 1}};
Polynomial1ToN F1(coeffs_F1, 1, 1);

std::vector<std::vector<double>> coeffs_F2 = {{2, 0, 0, 1, 0, 1}, {-1, 0, 1}};
Polynomial1ToN F2(coeffs_F2, 2, 1);

Eigen::VectorXd X_initial_F1(1);
Eigen::VectorXd X_previous_F1(1);
std::pair<double, double> Inter_init_F1(-0.2, 8.1);

Eigen::VectorXd X_initial_F2(1);

TEST(FixedPointTestConv, valueNearZero) {
    X_initial_F1 << 3;
    X_previous_F1 << 6;

    FixedPoint FixedPoint_F1(X_initial_F1, false, 10e-10, 100);
    FixedPoint FixedPoint_F1_Aitken(X_initial_F1, true, 10e-10, 100);

    ResultMethod Results_FixedPoint_F1 = FixedPoint_F1.MethodFindRoot(F1);
    ResultMethod Results_FixedPoint_F1_Aitken = FixedPoint_F1_Aitken.MethodFindRoot(F1);

    double final_approx_FixedPoint_F1 = Results_FixedPoint_F1.fvalue[Results_FixedPoint_F1.fvalue.size() - 1].norm();
    double final_approx_FixedPoint_F1_Aitken = Results_FixedPoint_F1_Aitken.fvalue[Results_FixedPoint_F1_Aitken.fvalue.size() -
                                                                           1].norm();

    ASSERT_NEAR(final_approx_FixedPoint_F1, 0.0, 1e-10);
    ASSERT_NEAR(final_approx_FixedPoint_F1_Aitken, 0.0, 1e-10);
}

TEST(NewtonTestConv, valueNearZero) {
    X_initial_F1 << 3;
    X_initial_F2 << -8.3;

    Newton Newton_F1(X_initial_F1, false, 10e-10, 100);
    Newton Newton_F1_Aitken(X_initial_F1, true, 10e-10, 100);
    Newton Newton_F2(X_initial_F2, false, 10e-10, 100);
    Newton Newton_F2_Aitken(X_initial_F2, true, 10e-10, 100);

    ResultMethod Results_Newton_F1 = Newton_F1.MethodFindRoot(F1);
    ResultMethod Results_Newton_F1_Aitken = Newton_F1_Aitken.MethodFindRoot(F1);
    ResultMethod Results_Newton_F2 = Newton_F2.MethodFindRoot(F2);
    ResultMethod Results_Newton_F2_Aitken = Newton_F2_Aitken.MethodFindRoot(F2);

    double final_approx_Newton_F1 = Results_Newton_F1.fvalue[Results_Newton_F1.fvalue.size() - 1].norm();
    double final_approx_Newton_F1_Aitken = Results_Newton_F1_Aitken.fvalue[Results_Newton_F1_Aitken.fvalue.size() -
                                                                           1].norm();
    double final_approx_Newton_F2 = Results_Newton_F2.fvalue[Results_Newton_F2.fvalue.size() - 1].norm();
    double final_approx_Newton_F2_Aitken = Results_Newton_F2_Aitken.fvalue[Results_Newton_F2_Aitken.fvalue.size() -
                                                                           1].norm();

    ASSERT_NEAR(final_approx_Newton_F1, 0.0, 1e-10);
    ASSERT_NEAR(final_approx_Newton_F1_Aitken, 0.0, 1e-10);
    ASSERT_NEAR(final_approx_Newton_F2, 0.0, 1e-10);
    ASSERT_NEAR(final_approx_Newton_F2_Aitken, 0.0, 1e-10);
}

TEST(ClassicChordTestConv, valueNearZero) {
    X_previous_F1 << 6;
    X_initial_F1 << 3;

    ClassicChord Classic_Chord_F1(X_previous_F1, X_initial_F1, false, 10e-10, 100);
    ClassicChord Classic_Chord_F1_Aitken(X_previous_F1, X_initial_F1, true, 10e-10, 100);

    ResultMethod Results_Classic_Chord_F1 = Classic_Chord_F1.MethodFindRoot(F1);
    ResultMethod Results_Classic_Chord_F1_Aitken = Classic_Chord_F1_Aitken.MethodFindRoot(F1);

    double final_approx_Classic_Chord_F1 = Results_Classic_Chord_F1.fvalue[Results_Classic_Chord_F1.fvalue.size() -
                                                                           1].norm();
    double final_approx_Classic_Chord_F1_Aitken = Results_Classic_Chord_F1_Aitken.fvalue[
            Results_Classic_Chord_F1_Aitken.fvalue.size() - 1].norm();

    ASSERT_NEAR(final_approx_Classic_Chord_F1, 0.0, 1e-10);
    ASSERT_NEAR(final_approx_Classic_Chord_F1_Aitken, 0.0, 1e-10);
}

TEST(BissectionTestConv, valueNearZero) {
    Bissection Bisection_F1(Inter_init_F1, 10e-10, 100);

    ResultMethod Results_Bisection_F1= Bisection_F1.MethodFindRoot(F1);

    double final_approx_Bisection_F1 = Results_Bisection_F1.fvalue[Results_Bisection_F1.fvalue.size() -
                                                                           1].norm();

    ASSERT_NEAR(final_approx_Bisection_F1, 0.0, 1e-10);
}

TEST(DimensionFixedPoint, throwsException) {
    X_initial_F1 << 3;

    FixedPoint Fixed_Point_F1(X_initial_F1, false, 10e-10, 100);

    ASSERT_THROW(Fixed_Point_F1.MethodFindRoot(F2), std::invalid_argument);
}

TEST(DimensionClassicChord, throwsException) {
    X_previous_F1 << 6;
    X_initial_F1 << 3;
    X_initial_F2 << -8.3;

    ClassicChord Classic_Chord_F1(X_previous_F1, X_initial_F1, false, 10e-10, 100);

    ASSERT_THROW(Classic_Chord_F1.NextX(F2,X_initial_F1), std::invalid_argument);
}

TEST(DimensionMethodBisection, throwsException) {

    Bissection Bisection_F1(Inter_init_F1, 10e-10, 100);

    ASSERT_THROW(Bisection_F1.MethodFindRoot(F2), std::invalid_argument);
}