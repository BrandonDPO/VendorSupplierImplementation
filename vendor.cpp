#include "vendor.h"

Vendor::Vendor() {}

void Vendor::setDetails(QString name, QString email, bool isManufactuer) {
    m_Name = name;
    m_Email = email;
    m_IsManufacturer = isManufactuer;
}

bool Vendor::isManufacturer() {
    return m_IsManufacturer;
}

QString Vendor::getName() {
    return m_Name;
}

QString Vendor::toString() {
    QString output = "---------------------------------------------- \n";
    output        += "                 Supplier \n";
    output        += "---------------------------------------------- \n";
    output += "Name : " + getName() + " \n";
    output += "Email : " + m_Email + " \n";
    if (isManufacturer()) {
        output += "Manufacturer : Yes \n";
    } else {
        output += "Manufacturer : No \n";
    }
    output += "---------------------------------------------- \n";
    return output;
}

