#pragma once
#include <string>
#include "GameInstance.h"

namespace shgame
{
    class Client
    {
    private:
        shgame::logic::GameInstance* game;

    public:
        Client();

    protected:
        string hidden_name;
    };
}

