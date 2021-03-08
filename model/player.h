/*!
 * \file player.h
 *
 * \brief Definition of the class diaballik::Player.
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "playerColor.h"

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik
{

/*!
 * \brief The Player class represents a player in the game.
 */
class Player
{

    /*!
     * \brief color_ The color of the player.
     */
    const PlayerColor color_;

    /*!
     * \brief name_ The name of the player.
     */
    const std::string name_;

public:

    /*!
     * \brief Constructor of the player.
     * \param color the color of the player.
     * \param name the name of the player.
     */
    inline Player(PlayerColor color, std::string name);

    /*!
     * \brief Getter of the color.
     * \return the color of the player.
     */
    constexpr PlayerColor color() const;

    /*!
     * \brief Getter of the name.
     * \return the name of the player.
     */
    inline const std::string & name() const;

    /*!
     * \brief Convert the player to a String.
     * \return the string of the player.
     */
    inline std::string to_string() const;
};

/*!
 * \brief Convert the player to a String.
 * \param player the player to convert;
 * \return the string of the player.
 */
inline std::string to_string(const Player & player);

/*!
 * \brief operator << to inject a player into an output stream.
 * \param out an output stream where the player is injected.
 * \param player a player to inject in an output stream.
 * \return the output stream after the injection.
 */
inline std::ostream & operator<<(std::ostream & out, const Player & player);

inline Player::Player(PlayerColor color, std::string name):
    color_ {color},
    name_ {name}
{

}

constexpr PlayerColor Player::color() const
{
    return this->color_;
}

const std::string & Player::name() const
{
    return this->name_;
}

std::string Player::to_string() const
{
    return {"Player Name : " + name_ + " ,Color " + diaballik::to_string(color_) };
}

std::string to_string(const Player & player)
{
    return player.to_string();
}

std::ostream & operator<<(std::ostream & out, const Player & player)
{
    out << to_string(player);
    return out;
}
}
#endif // PLAYER_H
