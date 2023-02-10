#include<string>
#include<iostream>

int main() {
    const std::string s = "hello";
    for (auto &c : s)
    {
        
        std::cout<<c<<std::endl;
    }
    
    return 0;
}
