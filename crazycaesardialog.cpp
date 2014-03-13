#include "crazycaesardialog.h"
#include "ui_crazycaesardialog.h"

#include "crazycaesar.h"
#include <QHash>
#include <limits>

CrazyCaesarDialog::CrazyCaesarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CrazyCaesarDialog)
{
    ui->setupUi(this);
}

CrazyCaesarDialog::~CrazyCaesarDialog()
{
    delete ui;
}

ICryptographer* CrazyCaesarDialog::createChosenCrypto() {
    uint hash = qHash(ui->PasswordEdit->text());

    int val = int(qint64(hash) - (std::numeric_limits<uint>::max()/2));

    return new CrazyCaesar(val);
}
