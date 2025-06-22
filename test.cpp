#include<string>
#include<iostream>
#include <cctype>
#include <algorithm>
std::string str_toupper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
                // static_cast<int(*)(int)>(std::toupper)         // wrong
                // [](int c){ return std::toupper(c); }           // wrong
                // [](char c){ return std::toupper(c); }          // wrong
                   [](unsigned char c){ return std::toupper(c); } // correct
                  );
    return s;
}//nie działa dla polskich znaczków
int main()
{
    std::string chuj="chujchujchuj";
    //std::cout<<toupper(chuj)<<"\n";
    for (int i=0;i<15;i++)
    {
        std::cout<<std::toupper(chuj[i])<<"\n";
    }
}