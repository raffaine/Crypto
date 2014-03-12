#include "caesarshiftdialog.h"
#include "ui_caesarshiftdialog.h"

#include "caesarcrypto.h"

CaesarShiftDialog::CaesarShiftDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CaesarShiftDialog)
{
    ui->setupUi(this);
}

CaesarShiftDialog::~CaesarShiftDialog()
{
    delete ui;
}

ICryptographer* CaesarShiftDialog::createChosenCrypto() {
    return new CaesarCrypto(ui->ShiftSBox->value());
}
