/*!
 * \file game.h
 *
 * \brief Definition of the class diaballik::Game.
 */
#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"
#include "action.h"
#include "../observer/observable.h"

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik {

/*!
 * \brief The Game class represent the game Diaballik.
 */
class Game :public Observable{

    /*!
     * \brief board_ the board of the game.
     */
    Board board_;

    /*!
     * \brief current_ the current player of the game.
     */
    Player * current_;

    /*!
     * \brief opponent_ the opponent player of the game.
     */
    Player * opponent_;

    /*!
     * \brief nbMoves_ the number of moves remaining.
     */
    int nbMoves_;

    /*!
     * \brief throwed_ the number of throws remaining.
     */
    bool throwed_;


public :

    /*!
     * \brief Constructor of the game.
     * \param currentName the name of the current player.
     * \param opponentName the name of the opponent player.
     * \param size the size of the board.
     * \param isVariant the type of board.
     * True for the variant, otherwise false for the classic board.
     */
    Game(std::string currentName, std::string opponentName, int size, bool isVariant);

    /*!
     *\brief Destructor of Game, destroy both player.
     */
    ~Game();

    /*!
     * \brief Verify if the game is ended. The game is over when a player throws the ball in the opposite side.
     * \return true if the game is over, otherwise false.
     */
    bool isOver();

    /*!
     * \brief Verify if there is a context of anti game.
     * A context of anti game happends when the opponent player has a wall with his pieces and the current player has
     * 3 pieces next to ennemy pieces.
     * \return true if there is a context of anti game so the current player can't go through the wall, otherwise false so when the wall do not
     * exist or the current player has a piece behind the wall.
     */
    bool isAntiJeu();

    /*!
     * \brief Verify if the current player can still play.
     * A player can still play if he has enough moves or throws.
     * \return true if he can, otherwise false.
     */
    bool canPlay();

    /*!
     * \brief Execute an action of the game. It can be a MOVE or a THROW.
     * \param action the type of the action.
     * \param posStart the start position of the action.
     * \param posEnd the end position of the action.
     */
    void play(Action action, Position posStart, Position posEnd);

    /*!
     * \brief End the turn if the player has no more moves or throws or if the player ask it and did at least one move.
     */
    void endTurn();

    /*!
     * \brief Getter of the board.
     * \return the board of the game.
     */
    Board board();

    /*!
     * \brief Getter of the current player.
     * \return the current player of the game.
     */
    Player current();
    /*!
     * \brief nbMoves, numbers of moves left for the current player.
     * \return the number of moves left.
     */
    int nbMoves();
    /*!
     * \brief throwed, say if the player has already throw the ball.
     * \return true if thee player has already throw the ball.
     */
    bool throwed();
private :

    void throwBall(Position posStart, Position posEnd);
    void move(Position posStart, Position posEnd);
    bool canMove(Position posStart, Position posEnd,Direction dir);
    bool hasFinished(int i);
    bool isLegal(Position posStart,Position posEnd);
    void setThrowed(bool hasThrow);
    void setMoves(int nbMoves);
    void swapPlayer();
    Direction calculPente(Position posStart, Position posEnd);
};
}
#endif // GAME_H
