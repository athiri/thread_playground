#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <thread>
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
   std::vector<std::thread> threadpool;
   int numthreads = atoi(argv[argc-1]);
   for (int i = 0; i < numthreads; ++i){
	threadpool.emplace_back([i]{
			if (isPalindrome(i)) std::cout <<"Thread " << std::this_thread::get_id() <<" and "<<  i << " passed\n";});
   }
   for (auto &t : threadpool){
	t.join();	
   }
   return 0;
}
