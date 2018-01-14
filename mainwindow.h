#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "task.h"
#include <QMainWindow>
#include <QDebug>

namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addTask();
    void removeTask(Task* task);

private:
    Ui::MainWindow *ui;
    QVector<Task*> mTasks;
};

#endif
