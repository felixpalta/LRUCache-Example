#include <lib.h>
#include <iostream>
#include <iterator>

std::list<int> v = { 0, 1, 2, 3, 4 };


void PrintList(ShiftableList<int> & ls){
    for (auto i : ls)
        std::cout << i << " ";
     std::cout << std::endl;
}

int main()
{

}
