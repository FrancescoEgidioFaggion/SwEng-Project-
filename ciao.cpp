#include <iostream>
#include <vector>

int main(){


    std::vector<std::vector<int> >C(2, std::vector<int>(2, 0));

    std::cout << C[0][0] << C[0][1]<< std::endl;
    std::cout << C[1][0] << C[1][1]<< std::endl;
}