#include "csvclass.h"
#include <QTextCodec>
CsvClass::CsvClass()
{
    qDebug()<<"This is CSV exapmle!\n";
}

QList<QStringList> CsvClass::ReadFromCSV(QString PathName)
{
    QList<QStringList> retList;
    qDebug().noquote()<<"Original   CSV   name:"<<PathName.toStdString().c_str();
    //指定为GBK
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    QFile file(PathName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return retList;
    while (!file.atEnd()) {
        //QByteArray line = file.readLine();
        //QString line = file.readLine();
        QString line = codec->toUnicode(file.readLine());

        line.replace('\n',"");//delete \n symbol
        QStringList lineList = line.split(',');
        retList.append(lineList);
        qDebug().noquote()<<lineList;
    }
    file.close();

    i_numOfLine = retList.size();

    return retList;
}

void CsvClass::SaveToCSV(QList<QStringList> CsvList,QString PathName)
{
    qDebug().noquote()<<"\nDestination CSV name:"<<PathName;
    for(int i=0;i<CsvList.size();i++)
    {
        QString tmpStr;
        QStringList strList = CsvList.at(i);
        for(int j=0;j<strList.size();j++){
            tmpStr.append(strList.at(j));
            if(j<(strList.size()-1)){
                tmpStr.append(',');
            }else{
                tmpStr.append('\n');
            }
        }
        qDebug().noquote()<<i<<'\t'<<tmpStr;
        QFile file(PathName);
        if(!file.open(QIODevice::WriteOnly| QIODevice::Text | QIODevice::Append)){
            qDebug()<<"Open "<<PathName<<" Error!";
            return;
        }else{
            QTextStream in(&file);
#if(QT_VERSION >= QT_VERSION_CHECK(6,0,0))
            in.setEncoding(QStringConverter::System);
#else
            QTextCodec *codec = QTextCodec::codecForName("GBK");	//设置为ANSI编码
            in.setCodec(codec);

#endif
            in<<tmpStr;
            file.close();
        }
    }
}

int CsvClass::getLineOfCSV()
{

    return i_numOfLine;
}
