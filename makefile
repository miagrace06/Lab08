all: records ll
records: records.cpp functions.cpp headers.h structs.h
  g++ records.cpp -o records -std=c++17 -Wall
ll: linkedlists.cpp ll_functions.cpp ll_headers.h
  g++ linkedlists.cpp -o linkedlists -std=c++17 -Wall
clean:
  rm -f *o Results.txt records linkedlists
