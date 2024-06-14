#include <iostream> // input and output handling
#include <fstream> //file handling
#include <string>  //string handling 
#include <cstdlib>

using std::strcmp;
using std::istream;
using std::ifstream;
using std::cerr;
using std::endl;
using std::cout;
#define LINES 7
#define MAX_LENG 256

void usage(){
    cout << "Usgae: ./head_new [-h] [-n N] [file.txt]" << endl;
    cout << "Usage: head_new [-h] [-n N] [file.txt]"<< endl;
    std::cout << "Options: "<< endl;
    std::cout << "  -h " << endl;
    std::cout << "  -n N " << endl;


}

int main(int argc, char *argv[]){
    int lines=  LINES;
    const char *filename = nullptr;
    istream *input = &std::cin;
    ifstream file;

    //pasing arguments passed in the commandline 

    for (int i =1; i<argc; i++){
        if(std:: strcmp(argv[i], "-h")==0){
            usage();
            return 0;

        }
        else if (strcmp(argv[i], "-n")==0){
            if(i+ 1< argc){
                lines = std::atoi(argv[++i]);
                if(lines <= 0) {
                    cerr << "Eror: NUmber of lines should be >0" << endl;
                    return 1;

                }

            }else {
                cerr << "Eror: -n no number written" << endl;
                return 1;
            }
        }
        else {
            filename = argv[i];
        }
    }
    //opening file 
    if (filename != nullptr){
        file.open(filename);
        if(!file.is_open()){
            cerr << "error openign file:" << endl;
            return 1;
        }
        input = &file;
    }
    std::string line;
    for(int i=0; i< lines && std::getline(*input, line); i++){
        cout << line << endl;
    }
    if (file.is_open()){
        file.close();
    }
    return 0;

}