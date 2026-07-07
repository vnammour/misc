// # Mon Jul  6 09:44:23 AM IDT 2026
// # By: vnammour 
#include <iostream>
#include <complex>

double square(const double x) {
    return x * x;
}

void copy() {
    const int sz = 10;
    int v1[] = {0,1,2,3,4,5,6,7,8,9};
    int v2[sz];
    for (auto i = 0; i < sz; i++) v2[i] = v1[i];
    for (auto x : v2) std::cout << x<<'\n';
    int v3[] = {11,17,22,25,-1};
    for (auto& x : v3) std::cout<<x<<'\n';
}

bool accept() {
    int tries = 4;
    while (tries--) {
        char answer;
        std::cout <<"Do you want to proceed (y or n)?\n";
        std::cin >> answer;
        switch (answer) {
        case 'y': return true;
        case 'n': return false;
        default:
            std::cout << "I don't understand.\n";
        }
    }
    std::cout << "I'll take that for a no.\n";
    return false;
}

void intval() {
    for (char c; std::cin >> c; )
        std::cout << "The value of '" << c << "' is "<< int{c} <<'\n';
}

void digits() {
    for (int i = 0; i != 10; ++i)
        // std::cout << i;
        std::cout << static_cast<char>('0' + i);
}

int main() {
    std::cout<<"Hello, World!\n";
    std::complex<double> z = 1;
    std::complex<double> x = 1+2j;
    std::cout<<x<<"\n";
    std::cout<<square(1.4)<<"\n";
    int var = 17;
    const int fix = 2;
    const double max = 1.4 * square(var);
    std::cout<<max<<"\n";
    // constexpr double max1 = 1.4 * square(fix);
    // accept();
    // copy();
    intval();
    digits();
    char c = 255;
    int i = c;
    std::cout << "i = "<<i<<'\n';
}

