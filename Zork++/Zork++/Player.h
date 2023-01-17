#pragma once
#include "Item.h";
#include "Room.h";
#include<iostream>
#include<iterator>
#include <list>

using namespace std;

class Player
{
public:
	 Room CurrentRoom;
	 string Name;
	 int Moves;
	 int Score;
	 float Health;
	 list<Item> _inventory;
};

