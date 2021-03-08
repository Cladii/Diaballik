#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <iostream>
#include <set>
namespace diaballik {
class Observer;
/*!
 * \brief The Observable class, or observation subect, inform the classes that observe him.
 */
class Observable{
public :
    /*!
     * \brief Add an observer to the list of observers.
     * \param observer, the one that will observe the subject.
     */
    virtual void addObserver(Observer * observer)final;

    /*!
     * \brief Remove an observer of the list of observers.
     * \param observer, the one that will not observe the subject anymore.
     */
    virtual void removeObserver(Observer * observer)final;

    /*!
     * \brief Virtual destructor, because there is polymorphism.
     */
    virtual ~Observable()=default;

    /*!
    * \brief Constructeur par recopie par défaut.
    *
    * Le destructeur virtuel par defaut a des effets en cascade.
    */
    Observable(const Observable &)=default;

    /*!
    * \brief Constructeur par déplacement par défaut.
    */
    Observable(Observable &&)=default;

    /*!
    * \brief Opérateur d'assignation par recopie par défaut.
    */
    Observable & operator=(const Observable &)=default;

    /*!
    * \brief Opérateur d'assignation par déplacement par défaut.
    */
    Observable & operator=(Observable &&)=default;


protected:
    /*!
    * \brief Constructeur privé pour éviter l'instanciation hors héritage
    */
    Observable()=default;

    /*!
     * \brief Notify all observers that are observing us.
     */
    virtual void notifyAll()const final;

    /*!
     * \brief the list of observers that are observing us.
     */
    std::set<Observer *>observers_{};
};
}
#endif // OBSERVABLE_H
