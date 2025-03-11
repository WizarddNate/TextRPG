#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "Room.hpp"

void Player::Start()
{
    m_character = 'P';
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

    //cheak for gold
    if (room->GetLocation(tryPos) == 'G'){
        m_goldCount++;
        room->ClearLocation(tryPos);
        printf("You collected +1 Gold\n");
    }
    //Check for treasur chest
    if(room->GetLocation(tryPos) == 'X'){
        m_goldCount = m_goldCount + 13;
        room->ClearLocation(tryPos);
        printf("You opened the Treasure Chest and collected +13 Gold\n");
    }

    //open door unlocked door
    if (room->GetLocation(tryPos) == 'D')
    {
        room->OpenDoor(tryPos);
        return;
    }
    //open locked door
    if (room->GetLocation(tryPos) == 'L')
    {
        //end if statement if you don't have the key
        if (m_keyCount <= 0)
        {
            printf("it's locked.\n");
            return;
        }

        room->SetLocation(tryPos, 'D');
        printf("your key unlocks the door with a satisfying click.\n");
        //m_position = tryPos;
        m_keyCount--;
    }

    if (room->GetLocation(tryPos) == ' ') 
        m_position = tryPos;
    
    //printf("%c\n", directionInput);

    //cout << playerStats.exp << " " << playerStats.level << " " << playerStats.gold << "\n";
}
