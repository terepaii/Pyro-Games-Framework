#ifndef INGAMESTATE_H
#define INGAMESTATE_H

#include "Interfaces\ISqualiensState.h"

/**
* Concrete game state. This is when the player is playing the game, not in any
* menus or other screens
*/
class InGameState : public ISqualiensState
{
public:
    InGameState();
    virtual ~InGameState();

    virtual void onSet(Squaliens& game);
    virtual void update(Squaliens& game);
    virtual void draw(Squaliens& game);
};

#endif //INGAMESTATE_H