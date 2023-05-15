#ifndef PRODUCT_H
#define PRODUCT_H

#include "vendor.h"
#include <QString>

class Product
{
private:
    QString m_Name;
    double m_Price;
    Vendor m_Supplier;
public:
    Product(QString name, double Price);
    void setSupplier(QString name, QString email, bool isManufacturer);
    QString getManufacturerName();
    QString toString(bool supplierDetails);
};

#endif // PRODUCT_H
