// hireemployee.cpp
#include "HireEmployee.h"
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

HireEmployee::HireEmployee(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Hire new employee");

    QFormLayout *formLayout = new QFormLayout(this);

    nameEdit = new QLineEdit(this);
    ageEdit = new QLineEdit(this);
    genderEdit = new QLineEdit(this);
    addressEdit = new QLineEdit(this);
    passportCodeEdit = new QLineEdit(this);
    positionCodeEdit = new QLineEdit(this);

    formLayout->addRow("Name:", nameEdit);
    formLayout->addRow("Age:", ageEdit);
    formLayout->addRow("Gender:", genderEdit);
    formLayout->addRow("Address:", addressEdit);
    formLayout->addRow("Passport code:", passportCodeEdit);
    formLayout->addRow("Position code:", positionCodeEdit);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                     Qt::Horizontal, this);
    formLayout->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

QString HireEmployee::getName() const
{
    return nameEdit->text();
}

int HireEmployee::getAge() const
{
    return ageEdit->text().toInt();
}

QString HireEmployee::getGender() const
{
    return genderEdit->text();
}

QString HireEmployee::getAddress() const
{
    return addressEdit->text();
}

QString HireEmployee::getPassportCode() const
{
    return passportCodeEdit->text();
}

QString HireEmployee::getPositionCode() const
{
    return positionCodeEdit->text();
}
