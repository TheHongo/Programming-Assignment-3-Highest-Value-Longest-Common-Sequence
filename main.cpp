#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>

std::string INPUT_FILE = "input.in";
std::string OUTPUT_FILE = "output.out";

std::string walkBackwards(std::string A, std::string B){
    return "test";
}

std::pair<int, std::string> solve(std::string filename){
    return std::pair<int, std::string>(0, walkBackwards("", ""));
}

int main(){
    std::pair<int, std::string> res = solve(INPUT_FILE);
    std::cout << "Max Value: " << res.first << std::endl;
    std::cout << "Optimal Subsequence: " << res.second << std::endl;
}