#ifndef CAESARSHIFTDIALOG_H
#define CAESARSHIFTDIALOG_H

#include <QDialog>
#include "ICryptographer.h"

namespace Ui {
class CaesarShiftDialog;
}

class CaesarShiftDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CaesarShiftDialog(QWidget *parent = 0);
    ~CaesarShiftDialog();

    ICryptographer* createChosenCrypto();

private:
    Ui::CaesarShiftDialog *ui;
};

#endif // CAESARSHIFTDIALOG_H
