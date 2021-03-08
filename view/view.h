/*!
 * \file view.h
 *
 * \brief Definition of the class diaballik::View.
 */
#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "../model/game.h"

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik {
/*!
 * \brief The View class, represent the console view.
 */
class View
{
public :

    /*!
     * \brief Display the title of the game and the first player to play.
     * \param player the player who plays first to display.
     */
    void initalise(Player player)const;

    /*!
     * \brief Display an error message.
     * \param message the error message to display.
     */
    void displayError(const std::string message)const;

    /*!
     * \brief Display a message.
     * \param message the message to display.
     */
    void displayMessage(const std::string message)const;

    /*!
     * \brief Ask to the user the size of the board.
     */
    void askSize()const;

    /*!
     * \brief Ask to the user his name.
     * \param i the first or second player.
     */
    void askName(int i)const;

    /*!
     * \brief Ask to the user the type of the board.
     */
    void askVariante()const;

    /*!
     * \brief Ask to the user the type of action.
     */
    void askAction()const;

    /*!
     * \brief Display the current player.
     * \param player the player to display.
     */
    void displayCurrentPlayer(Player player)const;

    /*!
     * \brief Display the actions which the player can still do.
     * \param moves the number of moves he can do.
     * \param throwed true if he can throw the ball, otherwise false.
     */
    void displayActionsLeft(int moves,bool throwed);

    /*!
     * \brief Display the board.
     * \param board the board to display.
     */
    void displayBoard(Board board)const;

    /*!
     * \brief Display the winner and how he wins.
     * \param winner the player who wins the game.
     * \param antiJeu true if the player wins because there were antiJeu, otherwise false.
     */
    void displayWinner(Player winner, bool antiJeu)const;

};
}
#endif // VIEW_H
