#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>

std::string INPUT_FILE = "input.in";
std::string OUTPUT_FILE = "output.out";

std::string walkBackwards(std::string A, std::string B, std::vector<std::vector<int> > mt, std::unordered_map<char, int> mp){
    return "test";
}

std::pair<int, std::string> solve(std::string filename){
    std::ifstream fin(filename);

    int k;
    fin >> k;
    std::unordered_map<char, int> mp; 
    //"helper functions"
    while (k--){
        char x;
        int v;

        fin >> x >> v;
        mp[x] = v;
    }

    std::string A, B;

    fin >> A >> B;

    std::vector<std::vector<int> > mt(A.size() + 1, std::vector<int>(B.size() + 1, 0)); //memoization table

    //actual dp implementation 
    for (int i=1; i < A.size()+1; i++){
        for (int j = 1; j < B.size()+1; j++){
            mt[i][j] = std::max(mt[i-1][j], mt[i][j-1]);
            if (A[i - 1] == B[j - 1]){
                mt[i][j] = std::max(mt[i][j], mt[i-1][j-1] + mp[A[i-1]]);
            }
        }
    }

    return std::pair<int, std::string>(mt[A.size()][B.size()], walkBackwards(A, B, mt, mp));
}

int main(){
    std::pair<int, std::string> res = solve(INPUT_FILE);
    std::cout << "Max Value: " << res.first << std::endl;
    std::cout << "Optimal Subsequence: " << res.second << std::endl;
}