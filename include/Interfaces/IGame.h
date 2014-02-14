#ifndef IGAME_H
#define IGAME_H

/**
* Interface that defines a basic game with a run (game loop), update and draw
* As this is the top most layer, there is nothing to call these functions so
* it is up to the client developer to do so.
*/
class IGame
{
public:
	virtual void run() = 0;

protected:
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif // IGAME_H