#ifndef STARTSCREENSTATE_H
#define STARTSCREENSTATE_H

#include "Interfaces\ISqualiensState.h"

/**
* Concrete game state. This state is the initial state of the game and simply
* acts as a start screen so the player isn't immediately thrown into the game
*/
class StartScreenState : public ISqualiensState
{
public:
    StartScreenState();
    virtual ~StartScreenState();

    virtual void onSet(Squaliens& game);
    virtual void update(Squaliens& game);
    virtual void draw(Squaliens& game);
};

#endif //STARTSCREENSTATE_H