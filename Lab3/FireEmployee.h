#ifndef FIREEMPLOYEE_H
#define FIREEMPLOYEE_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class FireEmployee : public QDialog
{
    Q_OBJECT

public:
    FireEmployee(QWidget *parent = nullptr);

    int getEmployeeNumber() const;

private:
    QLineEdit *employeeNumberEdit;
    QDialogButtonBox *buttonBox;
};

#endif // FIREEMPLOYEE_H
