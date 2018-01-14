#include "task.h"
#include "ui_task.h"
#include <QInputDialog>

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->removeButton, &QPushButton::clicked, [this, name] {
        this->emit removed(this);
    });
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
    connect(ui->checkBox, &QCheckBox::toggled, this, &Task::checked);
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString& name)
{
    ui->checkBox->setText(name);
}

QString Task::name() const
{
    return ui->checkBox->text();
}

bool Task::isCompleted() const
{
    return ui->checkBox->isChecked();
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit title"), tr("New title"), QLineEdit::Normal, this->name(), &ok);

    if (ok && !value.isEmpty())
        this->setName(value);
}

void Task::checked(bool enable)
{
    QFont font = ui->checkBox->font();
    font.setStrikeOut(enable);
    ui->checkBox->setFont(font);
    emit statusChanged(this);
}
