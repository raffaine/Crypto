#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "ICryptographer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<ICryptographer> m_crypto;

private slots:
    void OriginalToCrypto();
    void CryptToOriginal();

    void on_actionCaesar_Shift_triggered();
    //void on_closeDlg();
};

#endif // MAINWINDOW_H
