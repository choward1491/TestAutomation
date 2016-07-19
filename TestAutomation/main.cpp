//
//  main.cpp
//  TestAutomation
//
//  Created by Christian J Howard on 7/13/16.
//  Copyright © 2016 Christian Howard. All rights reserved.
//

#define UNIT_TEST
#include "UnitTest.hpp"

class SomeClass {
public:
    int add( int x, int y){ return x + y; }
private:
    FRIEND_TEST(Addition_With_Positive_Numbers)
    FRIEND_TEST(Addition_With_Negative_Numbers)
};

// Sample Test Number 1
TEST(Math,Addition_With_Positive_Numbers) {
    SomeClass sc;
    return 3 == sc.add(1,2);
 }

// Sample Test Number 2
TEST(Math,Addition_With_Negative_Numbers) {
    SomeClass sc;
    return -5 == sc.add(-1,-4);
}

// Sample Test Number 3
TEST(Math,Addition_With_Negative_Numbers2) {
    SomeClass sc;
    return -5 == sc.add(-1,-3);
}

// Sample Test Number 4
TEST(Math2,Addition_With_Mixed_Signs) {
    SomeClass sc;
    return 2 == sc.add(-1,3);
}



int main(int argc, const char * argv[]) {
    // insert code here...

    TestAutomator::automator.runTests();
    
    return 0;
}
