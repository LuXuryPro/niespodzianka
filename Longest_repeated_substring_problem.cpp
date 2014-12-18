#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<string>

//http://en.wikipedia.org/wiki/Longest_repeated_substring_problem
//./a.out banana
//an

int main(int argc, char**argv)
{
    std::string seq = argv[1];

    int longest_len = 0;
    int longest_pos = 0;
    for (int i = 0; i < seq.size(); ++i)
    {
        for (int j = 1; j <seq.size()/2 + 1; ++j)
        {
            std::string subseq = seq.substr(i, j);
            if (seq.find(subseq, i + subseq.size()) != std::string::npos)
            {
                if (j > longest_len)
                {
                    longest_len = j;
                    longest_pos = i;
                }
            }
            else
                break;
        }
    }
    std::cout <<"Pos "<< longest_pos  <<std::endl;
    std::cout <<"Len "<< longest_len  <<std::endl;
    std::cout << seq.substr(longest_pos,longest_len) <<std::endl;
    return 0;
}
