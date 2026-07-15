/* Wed Jul 15 02:02:33 PM IDT 2026 */
/* By: vnammour */
#include <stdio.h>
#include <stdlib.h> // for free
#include <string.h>
#include "ds/stack.h"

#define N 1024
const unsigned intsize = (unsigned)(32) << (~((unsigned)(0)) >> 63);
const int maxint = (1 << (intsize-1)) - 1;
const int minint = -1 <<(intsize - 1);
bool isOperator(int c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

bool isDigit(int c) {
    return c >= '0' && c <= '9';
}

bool isSpace(int c) {
    return c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r';
}

int comp(int a, int b) {
    if (a < b) return -1;
    else if (a > b) return 1;
    return 0;
}

int a2i(char *s) {
    if (s == 0) return 0;
    while (isSpace(*s)) ++s;
    int sign = *s == '-' ? -1 : 1;
    if (*s == '-' || *s == '+') ++s;
    unsigned num = 0, base = 10;
    unsigned max = sign == 1 ? (unsigned) maxint : (unsigned) minint;
    int t;
    for (int i = 0; s[i] != '\0'; i++) {
        t = s[i] - '0';
        if (num > max/base) break;
        num *= base;
        if (num > max - t) break;
        num += t;
    }
    --num;
    num *= sign;
    int result = sign == 1 ? ++num : --num;
    return result;
}


int mul(int a, int b) {
    return a * b;
}

bool checkerror(int err) {
    if (err) {
        printf("%s\n", errstring(err));
        return true;
    }
    return false;
}

bool polishcalc(Stack *stack, const char *s, int *res, char *errmsg) {
    if (s == NULL) return false;
    const char *p;
    int num;
    while (*s) {
        p = s;
        bool cond = (*s == '-' || *s == '+') && isDigit(s[1]) || isDigit(*s);
        if (cond) {
            while (isDigit(*++s));
            char *temp = strndup(p,s-p);
            num = a2i(temp);
            free(temp);
            push(stack,num);
            --s; // because s will be incremented at end.
        } else if (isOperator(*s)) {
            if (length(stack) < 2) return false;
            int a = pop(stack), b = pop(stack);
            switch(*s) {
            case '+': push(stack,a + b); break;
            case '-': push(stack,b - a); break;
            case '*': push(stack,a * b); break;
            case '/': case '%':
                if (a == 0) { strcpy(errmsg, "NaN"); return false; }
                if (*s == '/') push(stack, b/a);
                else push(stack, b % a);
                break;
            default: break;
            }
        } else if (!isSpace(*s)) return false;
        ++s;
    }
    *res = pop(stack);
    return length(stack) == 0;
}

int main(int argc, char *argv[])
{
    Stack *s = new(N);
    char line[N];
    char errmsg[32];
    errmsg[0] = '\0';
    bool ok = true;
    int sign = 1;
    int num = 0;
    while (fgets(line,N,stdin) != 0) {
        ok = polishcalc(s,line,&num, errmsg);
        if (ok) printf("%d\n", num);
        else {
            printf("invalid input\n");
            if (strlen(errmsg) > 0) printf(">%s<\n", errmsg);
            errmsg[0] = '\0';
        }
        reset(s);
    }
}
