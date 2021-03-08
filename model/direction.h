/*!
 * \file direction.h
 *
 * \brief Definition of the enumeration diaballik::Direction.
 */
#ifndef DIRECTION_H
#define DIRECTION_H

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik
{

/*!
 * \brief The Direction enum represents a direction on the board.
 */
enum class Direction
{
    /*!
     *\brief The direction UP Position(-1,0).
     */
    UP,

    /*!
     *\brief The direction UP_RIGHT Position(-1,1).
     */
    UP_RIGHT,

    /*!
     *\brief The direction RIGHT Position(0,1).
     */
    RIGHT,

    /*!
     *\brief The direction DOWN_RIGHT Position(1,1).
     */
    DOWN_RIGHT,

    /*!
     *\brief The direction DOWN Position(1,0).
     */
    DOWN,

    /*!
     *\brief The direction DOWN_LEFT Position(1,-1).
     */
    DOWN_LEFT,

    /*!
     *\brief The direction LEFT Position(0,-1).
     */
    LEFT,

    /*!
     *\brief The direction UP_LEFT Position(-1,-1).
     */
    UP_LEFT,
};
}

#endif // DIRECTION_H
