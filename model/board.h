/*!
 * \file board.h
 *
 * \brief Definition of the class diaballik::Board.
 */
#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "position.h"
#include <vector>
#include <iostream>

/*!
 * \brief Namespace of Diaballik.
 */
namespace diaballik
{

/*!
 * \brief The Board class represents a board of the game.
 */
class Board
{
    /*!
     * \brief size_ The size of the board.
     */
    const int size_;

    /*!
     * \brief board_ The game board.
     */
    std::vector<std::vector<Piece*>> board_;

public :

    /*!
     * \brief Constructor of the board.
     * \param size the size of the board. It must be 5x5, 7x7 or 9x9.
     * \param isVariant the type of the board.
     * True if the board must be a variant, otherwise false for the classic board.
     * The variant changes the position of 2 pieces for each player.
     */
    Board(int size, bool isVariant);

    /*!
     * \brief deleteBoard is used at the destruction of the game. Delete each piece
     * of the board that has been dynamically created.
     */
    void deleteBoard();

    /*!
     * \brief Getter of the size.
     * \return the size of the board.
     */
    constexpr int size() const;

    /*!
     * \brief Verify if the position is inside the board.
     * \param position the position to verify.
     * \return true if it is inside the board, otherwise false.
     */
    constexpr bool isInside(Position position) const;

    /*!
     * \brief Verify if the square at the position is free.
     * \param position the position to verify.
     * \return true if there is no piece on position on the board, otherwise false.
     */
    inline bool isFree(Position position) const;

    /*!
     * \brief Verify if there is a context of anti game.
     * A context of anti game happends when the opponent player has a wall with his pieces and the current player has
     * 3 pieces next to ennemy pieces.
     * \param color the color of the current player.
     * \return true if there is a context of anti game so the current player can't go through the wall, otherwise false so when the wall do not
     * exist or the current player has a piece behind the wall.
     */
    bool isAntiJeu(PlayerColor color) const;

    /*!
     * \brief Put a piece on the board.
     * \param piece the piece to put on the board.
     * \param position the position where to put the piece.
     */
    void put(Piece * piece, Position position);

    /*!
     * \brief Remove a piece from the board.
     * \param position the position where is the piece to remove.
     * \return the piece removed.
     */
    Piece * remove(Position position);

    /*!
     * \brief Getter of a piece on the board.
     * \param position the position where the piece is.
     * \return the piece from the board.
     */
    inline Piece* getPiece(Position position)const;

    /*!
     * \brief Convert the board to a String.
     * \return the string of the board.
     */
    inline std::string to_string()const;

private :

    void initialiseBoard(bool isVariant);
    void insertPieces(bool isVariant);
    std::string addColumnsNumbers()const;
    bool hasPieceIn(PlayerColor color)const;
    bool hasBlockLine(PlayerColor opponentColor) const;
    bool hasBlockedPieces(PlayerColor color, Position pos)const;
    bool whiteHasPassed()const;
    bool blackHasPassed()const;
    bool verifyNext(Position pos,PlayerColor color)const;
    bool verifyBlacksBlocked(Position pos)const;
    bool verifyWhitesBlocked(Position pos)const;
    void fillFirstRow(int i, int j, bool isVariant);
    void fillLastRow(int i, int j , bool isVariant);
    bool FindFirstBrick(Position & current, PlayerColor opponentColor, int & j) const;
    bool findNextBrick(Position current, Position & next, PlayerColor opponentColor) const;

};

/*!
 * \brief Convert the board to a String.
 * \param board the board to convert;
 * \return the string of the board.
 */
inline std::string to_string(const Board & board);

/*!
 * \brief operator << to inject a board into an output stream.
 * \param out an output stream where the board is injected.
 * \param board a board to inject in an output stream.
 * \return the output stream after the injection.
 */
inline std::ostream &operator<<(std::ostream & out, const Board & board);


constexpr int Board::size() const
{
    return this->size_;
}

constexpr bool Board::isInside(Position position) const
{
    return position.row()<this->size() && position.column()<this->size() && position.row()>=0 && position.column()>=0;
}

inline bool Board::isFree(Position position) const{
    return this->board_.at(position.row()).at(position.column())==nullptr;
}

inline Piece* Board::getPiece(Position position)const
{
    return this->board_.at(position.row()).at(position.column());
}


inline std::string Board::to_string()const
{
    std::string retour="  "+addColumnsNumbers()+"\n";
    unsigned i=0;
    for (std::vector<std::vector<Piece*>>::const_iterator it=this->board_.cbegin();it!=this->board_.cend();++it,++i)
    {
        retour+=std::to_string(i)+"   ";
        for (std::vector<Piece*>::const_iterator it2=it->cbegin();it2!=it->cend();++it2)
        {
            if(*it2!= nullptr)
                retour+=diaballik::to_string(**it2)+" ";
             else
                retour+=".  ";
        }
        retour+="\n";
    }
    return retour;
}


inline std::string to_string(const Board & board)
{
    return board.to_string();
}

inline std::ostream &operator<<(std::ostream & out, const Board & board)
{
    out<<to_string(board);
    return out;
}
}


#endif // BOARD_H
