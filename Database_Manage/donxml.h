#ifndef DONXML_H
#define DONXML_H
#include <QString>
#include <QStringList>
#include <QDomDocument>
#include <QDomElement>


class DonXML
{
public:
    DonXML();

    static void createXML(QString FilePath);
    static void appendXML(QString filePath, QStringList list);
    static void writeXML(QDomDocument &doc, QDomElement &root, QStringList &list);
    static void readXML(QString filePath, QStringList &fList, QStringList &bList, QStringList &pList, QStringList &nList, QStringList &tList);



};

#endif // DONXML_H
