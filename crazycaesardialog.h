#ifndef CRAZYCAESARDIALOG_H
#define CRAZYCAESARDIALOG_H

#include <QDialog>
#include "ICryptographer.h"

namespace Ui {
class CrazyCaesarDialog;
}

class CrazyCaesarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CrazyCaesarDialog(QWidget *parent = 0);
    ~CrazyCaesarDialog();

    ICryptographer* createChosenCrypto();

private:
    Ui::CrazyCaesarDialog *ui;
};

#endif // CRAZYCAESARDIALOG_H
