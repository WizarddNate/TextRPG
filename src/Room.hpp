#pragma once
#include "fogpi/Math.hpp"

#include <string>
#include <vector>

#include "Entity.hpp"
#include "Door.hpp"


class Room {
public:
    void Load(std::string _path);
    void Draw();
    void Update();

    bool StillPlaying() { return true; }

    Entity& GetPlayer() { return *m_player; }
    std::vector<Entity*>& GetMonsters() { return m_monsters; }
    std::vector<Entity*>& GetBoss() { return m_boss; }
    const std::vector<std::vector<char>>& GetMap() { return m_map; }
    char GetLocation(Vector2D _pos);
    void SetLocation(Vector2D _pos, char _char);
    void ClearLocation(Vector2D _pos);
    void OpenDoor(Vector2D _pos);
    
    std::vector<std::vector<char>> m_map;

    int monsterCount = 0;
private:
    Entity *m_player = nullptr;
    std::vector<Entity*> m_monsters;
    std::vector<Entity*> m_boss;
    std::vector<Door> m_doors;
};