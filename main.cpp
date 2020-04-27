#include <iostream>
#include "test/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    ForwardList<int>* list1 = new ForwardList<int>;
    list1->push_back(0);
    list1->push_back(1);
    list1->push_back(2);
    list1->push_back(3);
    list1->push_back(4);

    auto it = list1->begin();
    ++it;
    cout<<*it;
    ++it;
    ++it;
    cout<<endl<<(it!=list1->end());

    //Tester::execute();
    //return EXIT_SUCCESS;
}
