#include "Stack_array.h"
using namespace std;


int main(){

    Stack<int> stk;
    char expression[1000], buffer[1000];
    cin.getline(expression, 1000);
    int sz = strlen(expression);
    int j = 0;
    for (int i = 0; i < sz; ++i) {
        if (isOperand(expression[i])) {
            buffer[j] = expression[i];
            j++;
        }
        else if (expression[i] == ' ' && j > 0) {
            buffer[j] = '\0';
            int x = atoi(buffer);
            stk.push(x);
            j = 0;
        }
        else if (isOperator(expression[i])) {
            if (j > 0) {
                buffer[j] = '\0';
                int x = atoi(buffer);
                stk.push(x);
                j = 0;
            }
            int op2 = stk.getTop();
            stk.pop();
            int op1 = stk.getTop();
            stk.pop();
            stk.push(calculation(op1, op2, expression[i]));
        }
    }
    cout << "Result: " << stk.getTop() << "\n";

    return 0;
}
