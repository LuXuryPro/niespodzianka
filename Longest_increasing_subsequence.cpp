#include<iostream>
#include<vector>
#include<cstdlib>
#include<cmath>

//http://en.wikipedia.org/wiki/Longest_increasing_subsequence
//./a.out 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15
//0, 2, 6, 9, 13, 15

int main(int argc, char**argv)
{
    std::vector<int> v;
    for (int i = 1; i < argc; ++i)
        v.push_back(std::atoi(argv[i]));
    for (int i = 0; i < v.size(); ++i)
        std::cout<<v[i] << " ";
    std::cout<<std::endl<<"===================="<<std::endl;

    std::vector<int> P(v.size());
    std::vector<int> M(v.size());
    int L = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        float lo = 1;
        float hi = L;
        while(lo <= hi)
        {
            int mid = std::ceil((lo+hi)/2);
            if (v[ M[mid] ] < v[i])
                lo = mid + 1 ;
            else
                hi = mid - 1;
        }

        int newL = lo;
        P[i] = M[newL-1];
        M[newL] = i;

        if (newL > L)
            L = newL;
    }
    std::vector<int> S(L);
    int k = M[L];
    for (int i = L-1; i != -1; --i)
    {
        S[i] = v[k];
        k = P[k];
    }
    for (int i = 0; i < S.size(); ++i)
        std::cout<<S[i] << " ";
    std::cout<<std::endl;
}
