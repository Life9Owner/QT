#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QPushButton;
class QLabel;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void onClick();
    void onCheck(int state);
private:
    Ui::MainWindow *ui;
private:
    QPushButton* clickBtn;
    QLabel* label;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event) override;
};
#endif // MAINWINDOW_H
