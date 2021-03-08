#ifndef VIEWBOARD_H
#define VIEWBOARD_H
#include "model/board.h"
#include <QGridLayout>
#include "square.h"
namespace diaballik {
/*!
 * \brief The ViewBoard class, represent the GUI board of the game.
 */
class ViewBoard : public QGridLayout
{
    Q_OBJECT
public:
    /*!
     * \brief ViewBoard, constructor of viewBoard.
     * \param board, the board to represent.
     */
    ViewBoard(Board board);
    /*!
     * \brief displayBoard, display each piece of the board.
     * \param board, the board of the game.
     */
    void displayBoard(Board board);
    /*!
     * \brief displayPieces, display the piece at the position of the board.
     * \param board, the board of the game.
     * \param i, the row.
     * \param j, the column.
     */
    void displayPieces(Board board,int i, int j);
    /*!
     * \brief setColor, set the color of the square.
     * \param pos, the position of the square.
     * \param selected, if the piece is selected.
     */
    void setColor(Position pos, bool selected);
public slots:
    /*!
     * \brief selectedSquare, emit a signal with the position selected.
     * \param pos, the position selected.
     */
    void selectedSquare(Position pos);
signals:
    void VerifyselectedSquare(Position pos);
};
}
#endif // VIEWBOARD_H
