#ifndef TABLEAU_H
#define TABLEAU_H

#include <QObject>

int rand_a_b(int a,int b) ;

class tableau : public QObject
{
   Q_OBJECT
public:
    explicit tableau(QObject *parent = 0);

    void imp() ;
    //tableau() ;


    Q_INVOKABLE void gauche();
    Q_INVOKABLE void droite();
    Q_INVOKABLE void bas();
    Q_INVOKABLE void haut();
    Q_INVOKABLE void Init() ;
    Q_INVOKABLE void retour() ;

    int score ;
    std::string texte_perdu;

    int ***H ;
    int *score_H ;
    int ret_dispos ;

    Q_PROPERTY(QList<QString> liste READ readTableau NOTIFY cptChanged);
    Q_PROPERTY(QString scor READ readScore NOTIFY cptChanged);
    Q_PROPERTY(QList<QString> couleurs READ readColor NOTIFY cptChanged);
    Q_PROPERTY(QList<QString> couleurtext READ readColorText NOTIFY cptChanged);
    Q_PROPERTY(QString texteperdu READ readText NOTIFY cptChanged);
    Q_PROPERTY(QString retours READ readRetours NOTIFY cptChanged);

    QList<QString> readTableau();
    QString readScore();
    QList<QString> readColor();
    QList<QString> readColorText();
    QString readText();
    QString readRetours();

signals:
    void cptChanged() ;

//public slots:

private :
    int **M;
    void nvelle_case();
    bool perdu();
    void decalage() ;
};

#endif // TABLEAU_H
