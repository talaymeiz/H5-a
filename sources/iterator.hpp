#include <string>
#include <iostream>

#ifndef ITERATOR_HEADER
#define ITERATOR_HEADER

using namespace std;

namespace ariel{

    const int LEVEL_ORDER = 0;
    const int REVERSE_ORDER = 1;
    const int PREORDER = 2;

    class Iterator{

        private:
            int flag;

        public:
            Iterator(int flag);

            // ++i
            // i++
            // !=
            // ==
            ~Iterator();
    };
}

#endif