#ifndef INFOSTURN_H
#define INFOSTURN_H
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
namespace diaballik {
/*!
 * \brief The InfosTurn class represents the zone that show the current player, the number of moves and throw left.
 */
class InfosTurn : public QGroupBox
{
    Q_OBJECT
public:
    /*!
     * \brief InfosTurn, constructor of infoTurn.
     * \param current, the current player.
     * \param moves, the number of moves left.
     * \param throws, the number of throws left.
     */
    InfosTurn(std::string current, int moves, int throws);
    /*!
     * \brief update the paramters.
     * \param current, the current player.
     * \param moves, the number of moves left.
     * \param throws, the number of throws left.
     */
    void update(std::string current, int moves, bool throws);
    /*!
     * \brief getPass, getter of the QPushButton pass that is used to pass the turn.
     * \return the QPushButton.
     */
    QPushButton* getPass();
    /*!
     * \brief setButton, setter of the button pass.
     * \param disable, if is true, set the button enable else disable it.
     */
    void setButton(bool disable);
private:
    QLabel * current;
    QLabel * nbMoves;
    QLabel * nbThrow;
    QPushButton * pass;
};
}
#endif // INFOSTURN_H
