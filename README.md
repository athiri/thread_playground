Simple program to exhibit threading starvation.
The program bruteforces palindromes btn 0 and the user input
The threaded version will spin a new thread for each
number checked
Build instructions

git clone https://github.com/athiri/thread_playground.git
chmod +x build.sh
time ./single_pali <limit>
time ./thread_pali <numthreads>

#Notice how a large(> 10000) numthread affects runtime

