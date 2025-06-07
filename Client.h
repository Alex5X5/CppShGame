#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>



class Client
{
public:
    Client();
    void work();
    void set_name(std::string name);
protected:
    std::string hidden_name;
};

