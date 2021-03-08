/*!
 * \file action.h
 *
 * \brief Definition of the enumeration diaballik::Action.
 */
#ifndef ACTION_H
#define ACTION_H

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik
{

/*!
 * \brief The Action enum represents an action of the game.
 */
enum class Action
{
    /*!
     *\brief THROW represents a throw of ball from one piece to another.
     */
    THROW,

    /*!
     *\brief MOVE represents a move of a piece.
     */
    MOVE,

    /*!
     *\brief PASS represents an end of turn.
     */
    PASS
};
}
#endif // ACTION_H
