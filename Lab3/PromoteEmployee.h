// promoteemployee.h
#ifndef PROMOTEEMPLOYEE_H
#define PROMOTEEMPLOYEE_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class PromoteEmployee : public QDialog
{
    Q_OBJECT

public:
    PromoteEmployee(QWidget *parent = nullptr);

    int getEmployeeNumber() const;
    int getPromotionAmount() const;

private:
    QLineEdit *employeeNumberEdit;
    QLineEdit *promotionAmountEdit;

    QDialogButtonBox *buttonBox;
};

#endif // PROMOTEEMPLOYEE_H
