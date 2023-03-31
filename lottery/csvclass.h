
#ifndef CSVCLASS_H
#define CSVCLASS_H
#include <QDebug>
#include <QFile>




class CsvClass
{
public:
    CsvClass();
    QList<QStringList> ReadFromCSV(QString PathName);
    void SaveToCSV(QList<QStringList> CsvList,QString PathName);
    int getLineOfCSV(void);
    int i_numOfLine = 0;


};

#endif // CSVCLASS_H


