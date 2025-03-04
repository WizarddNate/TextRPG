#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "Room.hpp"

void Player::Start()
{
    m_character = 'P';
    Stats playerStats;

    //temp stats
    playerStats.strength = 2; //determines basic attack
    playerStats.dexterity = 3; //determines basic defense
    playerStats.wit = 1; //determines special attack
    playerStats.wisdom = 2; //determines special defense

    playerStats.health = 10;
    playerStats.level = 1;
    playerStats.exp = 0;
    playerStats.gold = 0;

}

void Player::Update()
{
    char directionInput;
    
    do {
        directionInput = request_char("wasd and Enter to move");
    } while (directionInput != 'w' &&
             directionInput != 'a' &&
             directionInput != 's' &&
             directionInput != 'd');
    
    Vector2D direction(0.0f);

    switch (directionInput)
    {
    case 'w':
        direction = {0.0f, -1.0f};
        break;
    case 'a':
        direction = {-1.0f, 0.0f};
        break;
    case 's':
        direction = {0.0f, 1.0f};
        break;
    case 'd':
        direction = {1.0f, 0.0f};
        break;
    default:
        direction = {0.0f, 1.0f};
        break;
    }

    Vector2D tryPos = m_position + direction;

    // check for a key
    if (room->GetLocation(tryPos) == 'K')
    {
        m_keyCount++;
        room->ClearLocation(tryPos);
    }

    //open door unlocked door
    if (room->GetLocation(tryPos) == 'D')
    {
        room->OpenDoor(tryPos);
    }
    //open locked door
    if (room->GetLocation(tryPos) == 'L')
    {
        //end if statement if you don't have the key
        if (m_keyCount <= 0)
        {
            printf("it's locked.");
            return;
        }

        room->SetLocation(tryPos, 'D');
        printf("your key unlocks the door with a satisfying click.");
        m_position = tryPos;
        m_keyCount--;
    }

    if (room->GetLocation(tryPos) == ' ') 
        m_position = tryPos;
    
    printf("%c\n", directionInput);

    //cout << playerStats.exp << " " << playerStats.level << " " << playerStats.gold << "\n";
}
