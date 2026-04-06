#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <chrono>

std::string INPUT_PATH = "../tests/input/";
std::string OUTPUT_PATH = "../tests/output/";

std::string walkBackwards(std::string A, std::string B, std::vector<std::vector<int> > mt, std::unordered_map<char, int> mp){
    int i = A.size();
    int j = B.size();
    std::string res;
    while (i > 0 && j > 0){
        if (A[i-1] == B[j-1] && mt[i][j] == mt[i-1][j-1] + mp[A[i-1]]){
            res = A[i-1] + res;
            i--;
            j--;
        }
        else if (mt[i][j] == mt[i-1][j]){
            i--;
        }
        else{
            j--;
        }
    }
    return res;
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
    std::string inputFile;
    std::cout << "Enter the input file name: ";
    std::cin >> inputFile;

    auto start = std::chrono::high_resolution_clock::now();

    std::pair<int, std::string> res = solve(INPUT_PATH + inputFile);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << std::endl;

    std:: string outputFile;
    std::cout << "Enter the output file name: ";
    std::cin >> outputFile;

    std::ofstream fout(OUTPUT_PATH + outputFile);
    fout << res.first << std::endl;
    fout << res.second << std::endl;
}