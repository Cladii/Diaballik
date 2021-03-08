/*!
 * \file playerColor.h
 *
 * \brief Definition of the enumeration diaballik::PlayerColor.
 */
#ifndef PLAYER_COLOR_H
#define PLAYER_COLOR_H

#include <string>

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik
{

/*!
 * \brief The PlayerColor enum represents a color in the game.
 */
enum class PlayerColor
{
    /*!
     *\brief WHITE represents a white Piece or Player.
     */
    WHITE,

    /*!
     *\brief BLACK represents a black Piece or Player.
     */
    BLACK
};

/*!
 * \brief Convert the playerColor to a String.
 * \param color the playerColor to convert;
 * \return the string of the playerColor.
 */
inline std::string to_string(PlayerColor color);

/*!
 * \brief operator <<to inject a playerColor into an output stream.
 * \param out an output stream where the playerColor is injected.
 * \param color a playerColor to inject in an output stream.
 * \return the output stream after the injection.
 */
inline std::ostream & operator<<(std::ostream & out, PlayerColor color);

inline std::string to_string(PlayerColor color)
{
    switch(color)
    {
    case PlayerColor::WHITE: return "W";
    case PlayerColor::BLACK: return "B";
    }
    return "";
}

inline std::ostream & operator<<(std::ostream & out, PlayerColor color)
{
    return out << to_string(color);
}
}

#endif // PLAYER_COLOR_H
