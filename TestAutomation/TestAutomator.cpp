//
//  TestAutomator.cpp
//  TestAutomation
//
//  Created by Christian J Howard on 7/13/16.
//
//  The MIT License (MIT)
//    Copyright © 2016 Christian Howard. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#include <stdio.h>

#include "TestAutomator.hpp"
#include "UnitTest.hpp"

// define singleton test automator
TestAutomator TestAutomator::automator;

// define constructor
TestAutomator::TestAutomator():unit_tests(0){
    successful_tests = 0;
}

// define destructor
TestAutomator::~TestAutomator(){
    for(int i = 0; i < unit_tests.size(); i++ ){
        unit_tests[i] = 0;
    }
}

// define method to run the tests
void TestAutomator::runTests(){
    successful_tests = 0;
    
    // run the tests
    for(int i =0; i < unit_tests.size(); i++ ){
        test_result[i] = unit_tests[i]->runTest();
        bool success = test_result[i];
        if( success ){
            printf("\033[1;32m[\xE2\x9C\x93]\033[0m - %s\n",unit_tests[i]->getName().c_str());
            successful_tests++;
        }else{
            printf("\033[1;31m[ ]\033[0m - %s\n",unit_tests[i]->getName().c_str());
        }
    }
    
    // output statistics
    outputStatistics();
    
}

// define method to output statistics
void TestAutomator::outputStatistics(){
    double percentSuccess = 100.0*static_cast<double>(successful_tests)/static_cast<double>(unit_tests.size());
    printf("%0.1lf%% of Unit Tests Passed.\n",percentSuccess);
    printf("There was %i successes and %i failures\n",successful_tests, (int)unit_tests.size() - successful_tests);
}

void TestAutomator::addTest( UnitTest* test ){
    unit_tests.push_back(test);
    test_result.push_back(false);
}


//std::vector<UnitTest*> unit_tests;

