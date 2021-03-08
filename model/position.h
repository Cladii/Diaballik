/*!
 * \file position.h
 *
 * \brief Definition of the class diaballik::Position.
 */
#ifndef POSITION_H
#define POSITION_H

#include <string>
#include <ostream>
#include "direction.h"

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik
{

/*!
 * \brief The Position class represent a position on the board.
 */
class Position
{
    /*!
     * \brief row_ The row of the position.
     */
    int row_;

    /*!
     * \brief column_ The column of the position.
     */
    int column_;

public :

    /*!
     * \brief Constructor of the position.
     * \param row the row of the position. The default value is 0.
     * \param column the column of the position. The default value is 0.
     */
    constexpr Position(int row = 0, int column = 0);

    /*!
     * \brief Getter of the row.
     * \return the row of the position.
     */
    constexpr int row() const;

    /*!
     * \brief Getter of the column.
     * \return the column of the position.
     */
    constexpr int column() const;

    /*!
     * \brief Convert the position to a String.
     * \return the string of the position.
     */
    inline std::string to_string() const;
};

/*!
 * \brief Convert a direction to a position.
 * \param direction the direction to convert.
 * \return the converted position from the direction.
 */
inline Position to_position(Direction direction);

/*!
 * \brief Calculate the next position from the current position and the direction.
 * \param position the current position.
 * \param direction the direction.
 * \return the next position.
 */
inline Position next(Position position, Direction direction);

/*!
 * \brief Operator == to compare 2 positions.
 * \param lhs a position.
 * \param rhs a position.
 * \return true if lhs and rhs are equal, otherwise false.
 */
constexpr bool operator==(const Position & lhs, const Position & rhs);

/*!
 * \brief operator != to compare 2 positions.
 * \param lhs a position.
 * \param rhs a position.
 * \return true if lhs and rhs are different, otherwise false.
 */
constexpr bool operator!=(const Position & lhs, const Position & rhs);

/*!
 * \brief operator + to add 2 positions.
 * \param lhs a position.
 * \param rhs a position.
 * \return the addition of the 2 positions.
 */
constexpr Position operator+(const Position & lhs, const Position & rhs);

/*!
 * \brief Convert the position to a String.
 * \param position the position to convert;
 * \return the string of the position.
 */
inline std::string to_string(const Position & position);

/*!
 * \brief operator << to inject a position into an output stream.
 * \param out an output stream where the position is injected.
 * \param position a position to inject in an output stream.
 * \return the output stream after the injection.
 */
inline std::ostream & operator<<(std::ostream & out, const Position & position);

constexpr Position::Position(int row, int column):
    row_ {row},
    column_ {column}
{

}

constexpr int Position::row() const
{
    return this->row_;
}

constexpr int Position::column() const
{
    return this->column_;
}

Position to_position(Direction direction)
{
    switch(direction)
    {
    case Direction::UP : return Position(-1,0);
    case Direction::UP_RIGHT : return Position(-1,1);
    case Direction::RIGHT : return Position(0,1);
    case Direction::DOWN_RIGHT : return Position(1,1);
    case Direction::DOWN : return Position(1,0);
    case Direction::DOWN_LEFT : return Position(1,-1);
    case Direction::LEFT : return Position(0,-1);
    case Direction::UP_LEFT : return Position(-1,-1);
    }
    return Position();
}

Position next(Position position, Direction direction)
{
    return position + to_position(direction);
}

std::string Position::to_string() const
{
    return {"[" + std::to_string(row_) + ";" + std::to_string(column_) + "]"};
}

constexpr bool operator==(const Position & lhs, const Position & rhs)
{
    return lhs.row()== rhs.row() && lhs.column() == rhs.column();
}

constexpr bool operator!=(const Position & lhs, const Position & rhs)
{
    return !(lhs==rhs);
}

constexpr Position operator+(const Position & lhs, const Position & rhs)
{
    int row = lhs.row()+rhs.row();
    int column = lhs.column()+rhs.column();
    return Position(row, column);
}

std::string to_string(const Position & position)
{
    return position.to_string();
}

std::ostream & operator<<(std::ostream & out, const Position & position)
{
    out << to_string(position);
    return out;
}
}

#endif // POSITION_H
