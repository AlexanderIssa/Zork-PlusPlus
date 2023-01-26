#include "Game.h"

using namespace std;

namespace Zork
{

    int Game::compare_case_insensitive(string s1, string s2) {
        //convert s1 and s2 into lower case strings
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if (s1.compare(s2) == 0)
            return 1; //The strings are same
        return 0; //not matched
    }

    void from_json(const json& j, Game& g) {
        j.at("World").get_to(g.world);
        for (auto room : g.world.Rooms)
        {
            if (room.Name == j.at("StartingLocation"))
            {
                g.world.StartingRoom = room;
            }
        }
        // psuedo code, somehow check to see if starting room is null or empty, if it is then starting location is bad
        /*if (g.world.StartingRoom == null/empty)
        {
            cout << "Invalid starting location!\n";
            Application.Quit();
        }*/
    };

    void to_json(json& j, const Game& g) {
        j = json{ {"World", g.world} };
        j = json{ {"StartingLocation"}, g.player.CurrentRoom };
    };

    void Game::ToCommand(string commandString)
    {
        //static unordered_map<string, Commands::commands> const table = { {"quit",Commands::commands::Quit} };
        //auto it = table.find(commandString);
        //if (it != table.end()) {
        //    return it->Commands::commands;
        //}
        //else { error() }

        //std::map<std::string, Commands::commands> xmap = boost::assign::map_list_of("A", A)("B", B)("C", C);

        //map<string, Commands::commands> commandsMap;
        //commandsMap["quit"] = Commands::commands::Q;

        if (compare_case_insensitive(commandString, "quit") || compare_case_insensitive(commandString, "q"))
        {
            command = gCommand::Quit;
        }
        else if (compare_case_insensitive(commandString, "look") || compare_case_insensitive(commandString, "l"))
        {
            command = gCommand::Look;
        }
        else
        {
            command = gCommand::Unknown;
        }
    };

    void Game::Run()
    {
        IsRunning = true;

        cout << "Current Room Info: " << player.CurrentRoom.Name << "\n" << player.CurrentRoom.Description << "\n";
    };

    void Game::ProcessInput(string inputString)
    {
        //cout << inputString << "\n";

        ToCommand(inputString);
        switch (command)
        {
        case gCommand::Quit:
            IsRunning = false;
            break;

        case gCommand::Look:
            cout << player.CurrentRoom.Description << "\n";
            break;

        case gCommand::Unknown:
            cout << "Unknown Command." << "\n";
            break;

        default:
            break;
        }
    };
}
