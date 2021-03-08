#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include <QFormLayout>
#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QDialog>

namespace diaballik {
/*!
 * \brief The Formulaire class, where the user enter the parameters of the game to create.
 */
class Formulaire : public QDialog{
    Q_OBJECT

public :
    /*!
     * \brief Formulaire, constructor of the formulaire.
     */
    Formulaire();

public slots:
    /*!
     * \brief ValidateForm, When the user press the button to confirm, verify if he has enter names for
     * both players. then emit a signal to swap the the window that contains the game.
     */
    void ValidateForm();
signals:
    /*!
     * \brief swapToGame, signal called to create the game.
     * \param size, the size of the board to create.
     * \param variante, true if the variant of the game is selected.
     * \param nom1, the name of the first player.
     * \param nom2, the name of the second player.
     */
    void swapToGame(int size, bool variante, std::string nom1, std::string nom2);

private:
    QFormLayout * layout;
    QRadioButton * variante;
    QComboBox * size;
    QLineEdit * nom1;
    QLineEdit * nom2;
    QPushButton * valider;
};
}
#endif // FORMULAIRE_H
