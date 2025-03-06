#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "Room.hpp"

void Player::Start()
{
    m_character = 'P';
    CharStats playerStats;

    //these stats are the same for everyone at the beginning
    playerStats.level = 1;
    playerStats.exp = 0;
    playerStats.gold = 0; 

    //all of the players stats
    char StatsInput;
    StatsInput = request_char("Select your class! F for fighter, C for cleric, W for wizard, R for rouge.");

    switch(StatsInput) {
        case 'F':
            playerStats.strength = 4;
            playerStats.dexterity = 2;
            playerStats.wit = 0;
            playerStats.wisdom = 1;
            playerStats.health = 12;

            printf("%c\n","you are a fighter! Stats:", "%c\n",
                    "strength: ", playerStats.strength, "%c\n",
                    "dexterity: ", playerStats.dexterity, "%c\n",
                    "wit: ", playerStats.wit, "%c\n",
                    "wisdom", playerStats.wisdom, "%c\n",
                    "health: ", playerStats.health, "%c\n",
                    "You are strong, but not vested in the arcane arts. Do not hesitate with your sword." "%c\n");
            break;

        case 'C':
            playerStats.strength = 0;
            playerStats.dexterity = 2;
            playerStats.wit = 2;
            playerStats.wisdom = 4;
            playerStats.health = 12;

        printf("%c\n","you are a Cleric! Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You sheild yourself from the dark forces who hunt you. Banish them with your magic." "%c\n");
            break;
        
        case 'W':
            playerStats.strength = 0;
            playerStats.dexterity = 3;
            playerStats.wit = 4;
            playerStats.wisdom = 2;
            playerStats.health = 12;

            printf("%c\n","you are a Wizard! Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You are vested in the arcane arts. Blast away your enemies with your spellbook before they can touch you." "%c\n");
            break;
        
        case 'R':
            playerStats.strength = 3;
            playerStats.dexterity = 4;
            playerStats.wit = 2;
            playerStats.wisdom = 0;
            playerStats.health = 12;

            printf("%c\n","you are a Rouge! Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You become one with the shadows. Strike your enemies before they see you." "%c\n");
            break;
        
        default:
            playerStats.strength = 3;
            playerStats.dexterity = 4;
            playerStats.wit = 2;
            playerStats.wisdom = 0;
            playerStats.health = 12;

            printf("you are secret class X! It SUCKS. Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You're not good at much of anything. Good luck bozo!" "%c\n");
            break;
      }
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
