/*!
 * \file piece.h
 *
 * \brief Definition of the class diaballik::Piece.
 */
#ifndef PIECE_H
#define PIECE_H

#include "playerColor.h"

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik
{

/*!
 * \brief The Piece class represent a piece on the board.
 */
class Piece
{
    /*!
     * \brief color_ The color of the piece.
     */
    const PlayerColor color_;

    /*!
     * \brief has_ball_ The state of the piece.
     * True if the piece has the ball, otherwise false.
     */
    bool has_ball_;

public:

    /*!
     * \brief Constructor of the piece without ball.
     * \param color the color of the piece.
     */
    constexpr Piece(PlayerColor color);

    /*!
     * \brief Constructor of the piece.
     * \param color the color of the piece.
     * \param has_ball the state of the piece.
     */
    constexpr Piece(PlayerColor color, bool has_ball);

    /*!
     * \brief Getter of the color.
     * \return the color of the piece.
     */
    constexpr PlayerColor color() const;

    /*!
     * \brief Getter of the state.
     * \return true if the piece has the ball, otherwise false.
     */
    constexpr bool has_ball() const;

    /*!
     * \brief Setter of the state.
     * \param has_ball the new state of the piece.
     */
    constexpr void set_has_ball(bool has_ball);

    /*!
     * \brief Convert the piece to a String.
     * \return the string of the piece.
     */
    inline std::string to_string() const;
};

/*!
 * \brief Convert the piece to a String.
 * \param piece the piece to convert;
 * \return the string of the piece.
 */
inline std::string to_string(const Piece & piece);

/*!
 * \brief operator << to inject a piece into an output stream.
 * \param out an output stream where the piece is injected.
 * \param piece a piece to inject in an output stream.
 * \return the output stream after the injection.
 */
inline std::ostream & operator<<(std::ostream & out, const Piece & piece);
bool operator==(Piece p1,Piece p2);


constexpr Piece::Piece(PlayerColor color):
    color_ {color},
    has_ball_ {false}
{

}

constexpr Piece::Piece(PlayerColor color, bool has_ball):
    color_ {color},
    has_ball_ {has_ball}
{

}

constexpr PlayerColor Piece::color() const
{
    return this->color_;
}

constexpr bool Piece::has_ball() const
{
    return this->has_ball_;
}

constexpr void Piece::set_has_ball(bool has_ball)
{
    this->has_ball_ = has_ball;
}

std::string Piece::to_string() const
{
    return {diaballik::to_string(this->color_)+std::to_string(this->has_ball_)};
}

std::string to_string(const Piece & piece)
{
    return piece.to_string();
}

std::ostream & operator<<(std::ostream & out, const Piece & piece)
{
    out << to_string(piece);
    return out;
}
}
#endif // PIECE_H
