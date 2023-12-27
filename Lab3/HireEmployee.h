#ifndef HIREEMPLOYEE_H
#define HIREEMPLOYEE_H

#include <QDialog>

class QLineEdit;
class QDialogButtonBox;

class HireEmployee : public QDialog
{
    Q_OBJECT

public:
    HireEmployee(QWidget *parent = nullptr);

    QString getName() const;
    int getAge() const;
    QString getGender() const;
    QString getAddress() const;
    QString getPassportCode() const;
    QString getPositionCode() const;

private:
    QLineEdit *nameEdit;
    QLineEdit *ageEdit;
    QLineEdit *genderEdit;
    QLineEdit *addressEdit;
    QLineEdit *passportCodeEdit;
    QLineEdit *positionCodeEdit;

    QDialogButtonBox *buttonBox;
};

#endif // HIREEMPLOYEE_H
