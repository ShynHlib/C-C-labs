#ifndef DEMOTEEMPLOYEE_H
#define DEMOTEEMPLOYEE_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class DemoteEmployee : public QDialog
{
    Q_OBJECT

public:
    DemoteEmployee(QWidget *parent = nullptr);

    int getEmployeeNumber() const;
    int getDecreaseAmount() const;

private:
    QLineEdit *employeeNumberEdit;
    QLineEdit *decreaseAmountEdit;

    QDialogButtonBox *buttonBox;
};

#endif // DEMOTEEMPLOYEE_H
