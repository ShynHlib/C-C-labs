#include "DemoteEmployee.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

DemoteEmployee::DemoteEmployee(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Demote employee");

    QFormLayout *formLayout = new QFormLayout(this);

    employeeNumberEdit = new QLineEdit(this);
    decreaseAmountEdit = new QLineEdit(this);

    formLayout->addRow("Employee Number:", employeeNumberEdit);
    formLayout->addRow("How much of a decrease:", decreaseAmountEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);
    formLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

int DemoteEmployee::getEmployeeNumber() const
{
    return employeeNumberEdit->text().toInt();
}

int DemoteEmployee::getDecreaseAmount() const
{
    return decreaseAmountEdit->text().toInt();
}
