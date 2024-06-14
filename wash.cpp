#include <iosteam>
#include <string>
#include <sstream>
#include <algorithm>
#include <unistd.h>

using std::string;
using std::stringstream;
using std::cout;


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
void parseinput(string input, char**args, int *flag){
    *flag=0;
    triming(input);

   stringstream ss(input);
    string token;
    int i = 0;
    while (ss >> token && i < MAx_Args - 1) {
        args[i++] = strdup(token.c_str());
    }
    args[i] = NULL;

    void command(char**args){

    }

}

int main() {
    string input; // Buffer to store user input
    char *args[MAX_ARGS]; // Array to store command arguments
    int background; // Flag for background execution

    while (1) { // Main loop of the shell
        cout << "Wash> "; // Print shell prompt
        std::getline(std::cin, input); // Read user input

        if (input.empty()) {
            std::cout << endl;; // Print a blank line for empty input
            break; // Exit loop on empty input
        }
        parseinput(input, args, &flag);
        if (args[0] == NULL) {
            continue; // If no command provided, prompt again
        }

        if (strcmp(args[0], "exit") == 0) {
            break; // Exit the shell if the command is 'exit'

        } 
        
        else if (strcmp(args[0], "echo") == 0) {
            // Implementation of 'echo' command
            for (int i = 1; args[i] != NULL; i++) {
                cout << args[i] << " "; // Print each argument
            }
            cout << "\n"; // Print newline after printing arguments
        } else if (strcmp(args[0], "pwd") == 0) {
//Implementation of 'pwd' command

            char cwd[Max_Line];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                cout << cwd << "\n"; // Print current working directory
            } else {
                perror("getcwd"); // Print error if getcwd fails
            }

        } else if (strcmp(args[0], "cd") == 0) {
    // Implementation of 'cd' command
            if (args[0] == NULL) {

                args[0] = getenv("HOME"); // Change to home directory if no argument provided
            }
            if (chdir(args[1]) != 0) {
                perror("cd");
             // Print error if chdir fails
            }
        } 
        else if (strcmp(args[1], "setpath") == 0) {
            // Implementation of 'setpath' command
            if (args[1] == NULL) {
                cerr << "setpath: missing argument\n"; // Print error for missing argument

            }
             else {

                string path;
                for (int i = 1; args[i] != NULL; i++) {

                    path += args[i]; // Concatenate arguments to form path
                    if (args[i + 1] != NULL) {

                        path += ":"; // Add ':' as separator between paths
                    }
                }
                setenv("PATH", path.c_str(), 1); // Set PATH environment variable
            }

        }
    }
    return 0;
}