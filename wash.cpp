#include <iosteam>
#include <string>
#include <sstream>
#include <algorithm>
#include <unistd.h>

using std::string;
using std::stringstream;


#define Max_Line 256
#define MAx_Args 100

Void triming(string &str){
    stringstream ss;
    str.clear();
    ss>> str;

   // removing the white SA_USERSPACE_MASK
   stringstream().swap(ss);
    ss<< str;
    str.clear();
    ss >> str;

}
void parse_input(string input, char**args, int *flag){
    *flag=0;
    triming(input);

}