#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main (int argc, char** argv) {
    // program counter
    unsigned pc = 0;
    // data counter
    unsigned dc = 0;

    // data array
    unsigned data_array[30000] = {0};
    // loop stack for nested loops
    stack <unsigned> loop;

    string program;
    getline(cin, program);
    
    // loop forever
    // we can have potential infinite loops
    while (1) {
        // we have finished processing the program
        if (pc >= program.size())   break;

        // get the next command 
        char cmd = program[pc];

        switch (cmd) {
            case '+':
                {
                    data_array[dc]++;

                    break;
                }
            case '-':
                {
                    data_array[dc]--;

                    break;
                }
            case '>':
                {
                    dc++;

                    break;
                }
            case '<':
                {
                    dc--;

                    break;
                }
            case '.':
                {
                    char asc = static_cast<char>(data_array[dc]);
                    cout << asc;

                    break;
                }
            case ',':
                {
                    char ch;
                    cin >> ch;
                    data_array[dc] = static_cast<unsigned>(ch);

                    break;
                }
            case '[':
                {
                    if (data_array[dc] == 0) {
                        while (program[pc] != ']') {
                            pc++;
                        }

                        continue;
                    } else {
                        loop.push(pc);
                    }

                    break;
                }
            case ']':
                {
                    if (data_array[dc] != 0) {
                        pc = loop.top();
                        loop.pop();
                        continue;
                    }
                    loop.pop();

                    break;
                }
        }

        // next command
        pc++;
    }

    // the last new line
    cout << endl;

    return 0;
}

