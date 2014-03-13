#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "caesarcrypto.h"
#include "crazycaesar.h"
#include "caesarshiftdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_crypto.reset( new CaesarCrypto(-3) );

    connect(ui->CryptoToOriginalBtn, SIGNAL(clicked()),
            this, SLOT(CryptToOriginal()));

    connect(ui->OriginalToCryptoBtn, SIGNAL(clicked()),
            this, SLOT(OriginalToCrypto()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OriginalToCrypto() {
    QString qstr = ui->OriginalTextEdit->toPlainText();
    std::string str = m_crypto->Encrypt(qstr.toStdString());

    ui->CryptoTextEdit->setPlainText(QString::fromStdString(str));
}

void MainWindow::CryptToOriginal() {
    QString qstr = ui->CryptoTextEdit->toPlainText();
    std::string str = m_crypto->Decrypt(qstr.toStdString());

    qstr.fromStdString(str);
    ui->OriginalTextEdit->setPlainText(QString::fromStdString(str));
}

void MainWindow::on_actionCaesar_Shift_triggered()
{
    CaesarShiftDialog dlg;
    dlg.setModal(true);

    dlg.exec();

    if( dlg.result() == QDialog::Accepted ) {
        m_crypto.reset( dlg.createChosenCrypto() );
    }
}

void MainWindow::on_actionCrazy_Caesar_triggered()
{
    m_crypto.reset( new CrazyCaesar(1) );
}
