// promoteemployee.cpp
#include "promoteemployee.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

PromoteEmployee::PromoteEmployee(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Promote employee");

    QFormLayout *formLayout = new QFormLayout(this);

    employeeNumberEdit = new QLineEdit(this);
    promotionAmountEdit = new QLineEdit(this);

    formLayout->addRow("Employee Number:", employeeNumberEdit);
    formLayout->addRow("How much of a raise:", promotionAmountEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);
    formLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

int PromoteEmployee::getEmployeeNumber() const
{
    return employeeNumberEdit->text().toInt();
}

int PromoteEmployee::getPromotionAmount() const
{
    return promotionAmountEdit->text().toInt();
}
