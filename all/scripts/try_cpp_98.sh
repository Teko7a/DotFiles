# !/bin/bash

g++ $1 -std=c++98 -O2
if [ $? -eq 0 ]; then
  echo -e '\033[32m\033[1m[OK!]\033[0m C++98 test passed. Good Luck! \033[0m'
else
  echo -e '\033[31m\033[1m[FAILED!]\033[0m C++98 test failed.\033[0m'
fi
\rm -f a.out
