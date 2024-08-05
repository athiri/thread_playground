#include <cmath>
#include <iostream>
#include <cstdlib>
bool isPalindrome(int x) {
        int xcpy = x;
        //deal with edge cases
        if (x < 0) return false;
        //get last dig 
        long res = 0;
        int lastdig = 0;
        int ind = 0;
        while (x > 9){
            x /= 10;
            ind+=1;
        }
        x = xcpy;
        while (x > 9 && ind >= 0){
            //
            lastdig = x % 10;
            x /= 10;
            res += lastdig * pow(10,ind);
            ind -= 1;
        }
        res += x*pow(10,ind);
        if (res == xcpy){
            return true;
        } else {
            return false;
        }
}

int main(int argc, char **argv){
   for (int i = 0; i < atoi(argv[argc-1]); ++i){
       int test =i;
       if (isPalindrome(test)){
           std::cout << i << " is a palindrome" << std::endl;
       } else {
	   //std::cout << "Test failed" << std::endl;
       }
   }
   return 0;
}
