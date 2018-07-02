// RUN: %check_clang_tidy %s misc-comma-in-subscript-operator %t

void ko() {
    int foo[1];
    int warn = foo[1, 0]; // CHECK-MESSAGES: :[[@LINE]]:16: warning: comma in foo[1, 0] [misc-comma-in-subscript-operator]
    int ok1  = foo[(1, 0)];
    int ok2  = foo[(1, 0)];
}
