#include <QCoreApplication>
#include "game_objects.h"
#include <QFile>
#include "game_new.h"
#include <QDebug>
//#include <QTextCodec>
#include <QFileInfo>
#include <QMessageBox>
#include <iostream>
using namespace std;

#include <QList>
#include <QString>
#include <QPoint>
#include <QDataStream>

//QDataStream& operator<<(QDataStream& stream, const Road& obj)
//{
//    return stream << obj.x1 << obj.x2 << obj.y1 << obj.y2 <<obj.color;
//}

//QDataStream& operator>>(QDataStream& stream, Road& obj)
//{
//    return stream >> obj.x1 >> obj.x2 >> obj.y1 >> obj.y2 >> obj.color;
//}

//QDataStream& operator<<(QDataStream& stream, const Town& obj)
//{
//    return stream << obj.town<< obj.color;
//}

//QDataStream& operator>>(QDataStream& stream, Town& obj)
//{
//    return stream >> obj.town >> obj.color;
//}
//QDataStream& operator<<(QDataStream& stream, const Hex& obj)
//{

//    stream << obj.zone << obj.x <<obj.y;
//    for(int i=0; i<6; i++){
//        for(int j=0; i<2; i++){
//            stream<<obj.peek[i][j];
//        }
//    }
//    stream<<obj.number[0]<<obj.number[1];
//    return stream;
//}

//QDataStream& operator>>(QDataStream& stream, Hex& obj)
//{
//    stream >> obj.zone >> obj.x >>obj.y;
//    for(int i=0; i<6; i++){
//        for(int j=0; i<2; i++){
//            stream>>obj.peek[i][j];
//        }
//    }
//    stream>>obj.number[0]>>obj.number[1];
//    return stream;
//}

//QDataStream& operator<<(QDataStream& stream, const Player& obj)
//{
//    return stream << obj.name << obj.color <<\
//     obj.clay << obj.wood << obj.stone<< obj.millet << obj.wool<<\
//    obj.monopoly<< obj.ivent<< obj.new_road<<\
//    obj.road_new << obj.knight << obj.points<<obj.road<<\
//    obj.army<< obj.vilage<< obj.sity<<\
//    obj.cards<<obj.the_bigest_roud<<\
//   obj.the_bigest_army<< obj.bot;
//}

//QDataStream& operator>>(QDataStream& stream, Player& obj)
//{
//    return stream >> obj.name >> obj.color >>\
//     obj.clay >> obj.wood >> obj.stone>> obj.millet >> obj.wool>>\
//    obj.monopoly<< obj.ivent<< obj.new_road<<\
//    obj.road_new >> obj.knight >> obj.points>>obj.road>>\
//    obj.army>> obj.vilage>> obj.sity>>\
//    obj.cards>>obj.the_bigest_roud>>\
//   obj.the_bigest_army>> obj.bot;
//}

///*===============================================================*/
///*===============================================================*/
///*===============================================================*/


//const auto datastreamVersion = QDataStream::Qt_5_12;

//void Game_New::serialize(QString outputFileName){

//     QFile outputFile(outputFileName);
//     QDataStream outputStream(&outputFile);

//     outputStream.setVersion(datastreamVersion);

//    if(!outputFile.open(QIODevice::WriteOnly |QIODevice::Text |QIODevice::Truncate)) {
//        //QIODevice::Text --чтобы символы конца строки преобразовывались с учетом текущей платформы
//        //Truncate - для очистки файла записи
//        //QIODevice::Append - без очистки - дописывать в конец файла
//         QMessageBox msgBox;
//         msgBox.setText("Файл не найден");
//         msgBox.setModal(true);
//         msgBox.exec();
//         outputFile.close();

//        return;
//    }
//    outputStream  << point<< num<<now;

//    for(int i=0; i<num; i++){
//        outputStream << player[i];
//    }
//    for(int i=0; i<19; i++){
//        outputStream << hex[i];
//    }
//    for(int i=0; i<72; i++){
//        road[i].color=(road[i].player!=nullptr)?(road[i].color):('n');
//       outputStream <<road[i];
//    }

//     for(int i=0; i<54; i++){
//         town[i].color=(town[i].player!=nullptr)?(town[i].color):('n');
//    outputStream << town[i];
//     }
//    if(outputStream.status()!=QDataStream::Ok){
//        outputFile.close();
////        qCritical()<<"in stream isn't ok\n";
//        return;
//    }


//    if(outputStream.status()!=QDataStream::Ok){
//        outputFile.close();
//       // qCritical()<<"out stream isn't ok\n";
//        return;
//    }

//    outputFile.close();
//}

//void Game_New::deserialize(const QString outputFileName){//
//    /*================ Чтение */

//    QFile inputFile(outputFileName);
//    if(!inputFile.exists()){
//        QFileInfo info(inputFile);
//        QMessageBox msgBox;
//        msgBox.setText("ok");
//        msgBox.setModal(true);
//        msgBox.exec();
//        return;
//    }

//    if(!inputFile.open(QIODevice::ReadOnly|QIODevice::Text)){
//        QMessageBox msgBox;
//        msgBox.setText("ok");
//        msgBox.setModal(true);
//        msgBox.exec();

//    }

//    QDataStream inputStream(&inputFile);
//    inputStream.setVersion(datastreamVersion);
//    inputStream >>point>>num>>now;
//    player=new Player[num];

//    for(int i=0; i<num; i++){
//         inputStream >> player[i];
//    }

//     init_all();
//    for(int i=0; i<19; i++){
//        inputStream >> hex[i];
//    }
//    for(int i=0; i<72; i++){

//         inputStream >>road[i];
//    }
//  for(int i=0; i<54; i++){
//     inputStream >>town[i];
//  }



//         hex_init();
//     for(int i=0; i<19; i++){
//         if(hex[i].number[1]==1)
//             fief_move(i);
//     }
//     for(int i=0; i<72; i++){
//         if(road[i].color=='r'){

//             for(int j=0; j<num; j++){
//                 if(player[j].color=='r')
//                     road[i].player=&player[j];
//             }

//         }
//         else if(road[i].color=='b'){

//             for(int j=0; j<num; j++){
//                 if(player[j].color=='b')
//                     road[i].player=&player[j];
//             }

//         }
//         else if(road[i].color=='w'){

//             for(int j=0; j<num; j++){
//                 if(player[j].color=='w')
//                     road[i].player=&player[j];
//             }

//         }
//         else if(road[i].color=='y'){

//             for(int j=0; j<num; j++){
//                 if(player[j].color=='y')
//                     road[i].player=&player[j];
//             }

//         }

//     }
//     for(int i=0; i<54; i++){
//         if(town[i].color=='r'){
//            town[i].label=new QLabel("", this);
//            town[i].label->setScaledContents(true);
//            town[i].label->show();
//             for(int j=0; j<num; j++){
//                 if(player[j].color=='r')
//                     town[i].player=&player[j];
//             }
//             (town[i].town==1)?( town[i].label->setPixmap(QPixmap())):( town[i].label->setPixmap(QPixmap()));
//         }
//         else if(town[i].color=='b'){
//            town[i].label=new QLabel("", this);
//            town[i].label->setScaledContents(true);
//            town[i].label->show();
//             for(int j=0; j<num; j++){
//                 if(player[j].color=='b')
//                     town[i].player=&player[j];
//             }
//             (town[i].town==1)?( town[i].label->setPixmap(QPixmap())):( town[i].label->setPixmap(QPixmap()));
//         }
//         else if(town[i].color=='w'){
//            town[i].label=new QLabel("", this);
//            town[i].label->setScaledContents(true);
//            town[i].label->show();
//             for(int j=0; j<num; j++){
//                 if(player[j].color=='w')
//                     town[i].player=&player[j];
//             }
//             (town[i].town==1)?( town[i].label->setPixmap(QPixmap())):( town[i].label->setPixmap(QPixmap()));
//         }
//         else if(town[i].color=='y'){
//            town[i].label=new QLabel("", this);
//            town[i].label->setScaledContents(true);
//            town[i].label->show();
//             for(int j=0; j<num; j++){
//                 if(player[j].color=='y')
//                     town[i].player=&player[j];
//             }
//             (town[i].town==1)?( town[i].label->setPixmap(QPixmap())):( town[i].label->setPixmap(QPixmap()));
//         }
//     }
//     action[start]=0;
//     action[clear]=1;
//     infromation_tool();
//    inputFile.close();
//     repaint();

//}



