
Just a basic example how to use google test

First to clone google test

git clone https:://github.com/google/googletest.git

google test are under test directory

Example is a library , these functionality gets tested through google test cases.


for more description go to 

https://github.com/google/googletest/blob/master/googletest/docs/primer.md


to run:

mkdir build
cd build
cmake ..
make 


// to run only 1 test case use
./ExampleTest --gtest_Filter=*SUM