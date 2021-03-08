#ifndef SQUARE_H
#define SQUARE_H
#include <QLabel>
#include "../model/position.h"
namespace diaballik {
/*!
 * \brief The Square class represent each square of the board.
 */
class Square : public QLabel
{
    Q_OBJECT
public:
    /*!
     * \brief Square, the constructor of the square.
     * \param x, the row of the board.
     * \param y, the column of the board.
     */
    Square(int x, int y);
    /*!
     * \brief setSeleted, set the color of the square to represent if this case is selected.
     * \param selected, the boolean that says if the square is selected or not.
     */
    void setSeleted(bool selected);
private:
    int i;
    int j;
protected:
    void mousePressEvent(QMouseEvent *event) override;
signals:
    void clicked(Position pos);
};
}
#endif // SQUARE_H
