#ifndef ISQUALIENSSTATE_H_
#define ISQUALIENSSTATE_H_

class Squaliens;

/**
* Using the state pattern, this is the state interface for the concrete game
* that can handle the update and draw logic
*/
class ISqualiensState
{
public:
    virtual ~ISqualiensState() {}

    /**
    * An init function that should be called when setting the state of the concrete game.
    * This is for any intialization logic but is seperate from the constructor
    * incase states are created before hand without being immediately set
    */
    virtual void onSet(Squaliens& game) {}

    /**
    * Update logic of the game in this particular state
    */
    virtual void update(Squaliens& game) = 0;

    /**
    * The drawing of the particulate game state
    */
    virtual void draw(Squaliens& game) = 0;

protected:
    ISqualiensState() {}
};

#endif //ISQUALIENSSTATE_H