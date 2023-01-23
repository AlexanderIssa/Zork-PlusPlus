#pragma once
#include "World.h";
#include "Player.h"
#include "Commands.h"
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Zork
{

    class Game
    {
    public:
        World world;
        Player player;
        bool IsRunning;
        string inputString;
        //Commands::commandsEnum gCommand = Commands::commandsEnum::Unknown;
        enum gCommand
        {
            Quit,
            Unknown
        };
        gCommand command;

        Game() = default;

        void Run(Game game);
        void RunProgram(string inputString);
        void ToCommand(string commandString);

    };

    void from_json(const json& j, Game& g);
    void to_json(json& j, const Game& g);
};


