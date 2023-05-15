#ifndef VENDOR_H
#define VENDOR_H

#include <QString>


class Vendor
{
private:
    QString m_Name;
    QString m_Email;
    bool m_IsManufacturer;

public:
    Vendor();
    void setDetails(QString name, QString email, bool isManufactuer);
    bool isManufacturer();
    QString getName();
    QString toString();
};

#endif // VENDOR_H
