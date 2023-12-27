#include "FireEmployee.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

FireEmployee::FireEmployee(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Fire employee");

    QFormLayout *formLayout = new QFormLayout(this);

    employeeNumberEdit = new QLineEdit(this);

    formLayout->addRow("Employee Number:", employeeNumberEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);
    formLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

int FireEmployee::getEmployeeNumber() const
{
    return employeeNumberEdit->text().toInt();
}
