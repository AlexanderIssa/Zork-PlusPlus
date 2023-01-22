#include "Game.h"
#include "Item.h";
#include "Room.h";
#include "Player.h";

using namespace std;

namespace Zork
{
    void from_json(const json& j, Game& g) {
        //j.get_to(g);
        //j.at("Player").get_to(g.player.Name);
        j.at("World").get_to(g.world);
    };

    void to_json(json& j, const Game& g) {
        //j = json{ {"Player", g.player.Name} };
        //j = json{ {"World", g.world} };
    };

    void Run()
    {

    }
}
