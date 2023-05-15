#include "product.h"

Product::Product(QString name, double price)
{
    m_Name = name;
    m_Price = price;
}

void Product::setSupplier(QString name, QString email, bool isManufacturer) {
    m_Supplier = Vendor();
    m_Supplier.setDetails(name, email, isManufacturer);
}

QString Product::getManufacturerName() {
    if (m_Supplier.isManufacturer()) {
        return m_Supplier.getName();
    } else {
        return "Unknown";
    }
}

QString Product::toString(bool supplierDetails) {
    QString output = "---------------------------------------------- \n";
    output        += "                 Product \n";
    output        += "---------------------------------------------- \n";
    output += "Name : " + m_Name + " \n";
    output += "Price : " + QString::number(m_Price) + " \n";
    output += "Manufacturer : " + getManufacturerName() + " \n";
    output += "---------------------------------------------- \n";

    if (supplierDetails) {
        output += m_Supplier.toString();
    }

    return output;
}
