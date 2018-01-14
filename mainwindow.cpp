#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("Add Task"), tr("New Task"), QLineEdit::Normal, tr("Task name"), &ok);

    if (ok && !name.isEmpty())
    {
        Task *task = new Task(name);
        ui->tasksLayout->addWidget(task);
        mTasks.append(task);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
    }
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
}
