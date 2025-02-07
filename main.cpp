#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <iterator>

int main(int argc, char* argv[]) {
    std::vector<char> code;

    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << argv[1] << std::endl;
            return 1;
        }
	code.assign(std::istreambuf_iterator<char>(file),
                    std::istreambuf_iterator<char>());
        file.close();
    } else {
        std::cout << "File not specified. Instant interpreter mode enabled. \n(Enter BrainFuck code) \n(Ctrl+D to interpret and exit):" << std::endl;
        code.assign(std::istreambuf_iterator<char>(std::cin),
                    std::istreambuf_iterator<char>());
    }

    std::vector<unsigned char> tape(30000, 0);
    size_t ptr = 0;
    std::stack<size_t> loops;

    for (size_t pc = 0; pc < code.size(); ++pc) {
        switch (code[pc]) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++tape[ptr];
                break;
            case '-':
                --tape[ptr];
                break;
            case '.':
                std::cout << tape[ptr];
                break;
            case ',':
                tape[ptr] = std::cin.get();
                break;
            case '[':
                if (tape[ptr] == 0) {
                    size_t depth = 1;
                    while (depth > 0) {
                        ++pc;
                        if (pc >= code.size()) {
			    std::cerr << "Error: Inconsistency '[' and ']'" << std::endl;	
                            return 1;
                        }
                        if (code[pc] == '[') ++depth;
                        if (code[pc] == ']') --depth;
                    }
                } else {
                    loops.push(pc);
                }
                break;
            case ']':
                if (tape[ptr] != 0) {
                    if (loops.empty()) {
                        std::cerr << "Error: Inconsistency ']' and '['" << std::endl;
                        return 1;
                    }
                    pc = loops.top();
                } else {
                    loops.pop();
                }
                break;
            default:
		break;
        }
    }

    return 0;
}

