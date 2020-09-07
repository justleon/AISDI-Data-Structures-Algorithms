#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "heap.h"

void unit_test()
{
    Heap4<int,int> heap;

    // pusty kopiec
    assert(heap.empty());
    assert(heap.size() == 0);

    /*bool exception_thrown = false;
    try
	{
        heap.peek();
    }
	catch(const std::logic_error&)
	{
        exception_thrown = true;
    }
    assert(exception_thrown);*/

    // dodawanie elementów
    heap.insert(10, 10);	// [10]
    assert(heap.peek().first == 10);

    heap.insert(50, 50);	// [10, 50]
    heap.insert(100, 100);  // [10, 50, 100]
    heap.insert(40, 40);	// [10, 40, 50, 100]
    heap.insert(20, 20);	// [10, 20, 40, 50, 100]
    assert(heap.peek().first == 10);

    heap.insert(5, 5);		// [5, 10, 20, 40, 50, 100]
    assert(heap.peek().first == 5);

    heap.print(std::cout);

    assert(!heap.empty());
    assert(heap.size() == 6);

    // pobieranie elementów
    heap.pop();				// [10, 20, 40, 50, 100]
    heap.print(std::cout);
    assert(heap.peek().first == 10);
    assert(heap.size() == 5);

    heap.pop();				// [20, 40, 50, 100]
    heap.print(std::cout);
    assert(heap.peek().first == 20);

    heap.pop();				// [40, 50, 100]
    heap.print(std::cout);
    assert(heap.peek().first == 40);

    heap.pop();				// [50, 100]
    heap.print(std::cout);
    assert(heap.peek().first == 50);

    heap.pop();				// [100]
    heap.print(std::cout);
    assert(heap.peek().first == 100);

    heap.pop();
    assert(heap.empty());
}

int main()
{
    unit_test();

    std::ofstream results("results.txt");
    Heap4<int, int> test;
    srand(time(NULL));
    for(int i = 0; i < 21; i++)
    {
        test.insert(rand() % 100 + 1, 0);
    }

    results << "WSTAWIANIE LOSOWE\nKOPIEC PO WSTAWIANIU" << std::endl;
    test.print(results);

    test.pop();
    results << "POP 1" << std::endl;
    test.print(results);
    test.pop();
    results << "POP 2" << std::endl;
    test.print(results);
    test.pop();
    results << "POP 3" << std::endl;
    test.print(results);
    std::cout << "Wyniki losowego wstawiania zapisano do pliku results.txt." << std::endl;
}
