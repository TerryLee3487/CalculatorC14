#include "calc.h"

using namespace std;
void Calc::digit(int digit) {
    display = display * 10 + digit;
}

void Calc::op(char oper) {
    // check is there was previously a operator
    if (this->oper != 0) {
        // if there is a previous operator, calculate the result first
        equals();
        this->oper = oper;
        // clear display
        display = 0;
    } else {
        result = display;
        // set tyhe new operator 
        this->oper = oper;
        // clean out display
        display = 0;
    }
}

void Calc::equals() {
    // check the operator and perform corresponding mathematical operation
    if (oper == '+') {
        result = result + display;
    } else if (oper == '-') {
        result = result - display;
    } else if (oper == '*') {
        result = result * display;
    } else if (oper == '/') {
        if (display == 0) {
            // is try to divide by 0, it produces the error and clear both result and display
            error = true;
            result = 0;
            display = 0;
        } else {
            result = result / display;
            error = false;
        }
    } else {
        // if there is no oper, display is the new result
        result = display;
    }
    // display the new result 
    display = result;
    // clear out oper
    oper = 0;
}

void Calc::memPlus() {
    // add display to memory
    memory = memory + display;
    // Clear error
    error = false;
}

void Calc:: memClear() {
    // reset error
    memory = 0;
    // clear out error
    error = false;
}

void Calc::memRecall() {
    // fetch stored memory
    display = memory;
    // clear out error
    error = false;
}

bool Calc:: isError() const {
    // choose bool according to error
    if (error) {
        return true;
    } else {
        return false;
    }
    
}

void Calc::allClear() {
    // reset everything
    error = false;
    display = 0;
    oper = 0;
    memory = 0;
    result = 0;
}

ostream& operator<<(ostream &out, const Calc &c) {
    // if there is no memory value then just print display 
    if (c.memory == 0) {
        if (c.error) {
            // "E" suffix appears if there is an error
            out << c.display << " E";
        } else {
            out << c.display;
        }
       
    } else {
        // print out memory value as well if exists
        if (c.error) {
            out << c.display << " M: " << c.memory << " E";
        } else {
            out << c.display << " M: " << c.memory;
        }
    }
    return out;
}
