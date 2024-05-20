#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
using namespace std;
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include <QListWidget>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief list_of_synapses
/// переменные:
std::vector<unsigned long long> list_of_synapses;//[10500];// ={};
std::vector<unsigned long long  > list_of_neurons;//[250];//[201] ;//={};
long long variable_error;
QString
// std::string
    Nazvaniye_fayla_s_neyronami_i_signalom="";
  
bool Odin_Uchitelia;
bool Odin_Programmi;
     QString line;
 //    QListWidget listWidget;
     QString myString ;
     int var ;
///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////// \brief readFileLineByLine
////////////////////////////////////////////////////////////////////////////////////////////////////// \param filename
void readFileLineByLine(const QString& filename) {

QListWidget listWidget;

QListWidget listWidget2;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading:" << filename;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
         Nazvaniye_fayla_s_neyronami_i_signalom = in.readLine();
        // Обработка прочитанной строки
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is( //NOTE: сигналы 1

       Nazvaniye_fayla_s_neyronami_i_signalom.toStdString().c_str()
        //NOTE: считывание в вектор нейронов и сигналов из файла (НАДО Менять для подстройки)
        );
    std::istream_iterator<unsigned long long> start(is), end;
    std::vector<unsigned long long> list_of_neurons(start, end);
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// из файла синапсов в вектор
    std::ifstream is2(
     "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
    );

    std::istream_iterator<unsigned long long> start2(is2), end2;
    std::vector<unsigned long long> list_of_synapses(start2, end2);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// тут же должно быть решение
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   считаем ошибку то есть решение
// TODO: FIXME: тут должен быть блок вычисления 200 нейрона
//########################################################################################################
    for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
        
        {
            // sigpe арифметическое исключение: (СИНАПСЫ бЫЛИ 0 ДЕление на 0)
      //      heap-buffer-overflow 
//       if (neuron_index < 200)
//      if (list_of_synapses[synapse_index]!=0)
//     if (var < 200)
//   if ( synapse_index < 10100)
//  if (list_of_synapses[synapse_index]!=0)
            list_of_neurons[var]=list_of_neurons[var]+  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]); // + на -   
        } // вычитаем нейроны
    }
    
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
//           if (neuron_index < 200)
//      if (list_of_synapses[synapse_index]!=0)
//     if (var < 200)
//   if ( synapse_index < 10100)
//  if (list_of_synapses[synapse_index]!=0)
        list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]); // + на -
    }
//########################################################################################################        
    variable_error     =   1073741824-list_of_neurons[200] ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   std::cout << "variable_error = "<< variable_error<< std::endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    if 
        ( variable_error <=0)

    {
     //   ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это 1.");
     std::cout << "Программа считает что это 1.";
        Odin_Programmi=true;
    }
                           else {
      //  ui->label->setText(Nazvaniye_fayla_s_neyronami_i_signalom+"\n"+"Программа считает что это не 1.");
       std::cout << "Программа считает что это не 1.";
          Odin_Programmi=false;
    } 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// TODO: если программа считает что это 1 (неправильно) то записываем путь к txt файлу в файл. 
   if ( Odin_Programmi==true)
   {
  // Odin_Uchitelia=false; 
   // Добавить строку в текстовый список
       // Создаем виджет списка
    
    listWidget.show();

    // Добавляем строковую переменную в список
     myString =Nazvaniye_fayla_s_neyronami_i_signalom;
    listWidget.addItem(myString);
   }
//########################################################################################################
   if ( Odin_Programmi==false)
   {
  // Odin_Uchitelia=true; 
   // Добавить строку в текстовый список
       // Создаем виджет списка
    
    listWidget2.show();

    // Добавляем строковую переменную в список
     myString =Nazvaniye_fayla_s_neyronami_i_signalom;
    listWidget2.addItem(myString);
   }   
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
        qDebug() << Nazvaniye_fayla_s_neyronami_i_signalom;
    } // цикл
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (    Odin_Programmi==true &&  Odin_Uchitelia==false)
{
    // Записываем содержимое списка в файл
    QString filename2 = "/home/viktor/my_projects_qt_2/avto_Funktsiya_Resheniya_2/oshiboshnie_files_1.txt";
    //"/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji/oshiboshnie_files_1.txt";
    QFile file2(filename2);
    if (file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file2);
        for (int i = 0; i < listWidget.count(); i++) {
            out << listWidget.item(i)->text() << "\n";
        }
        file2.close();
        qDebug() << "Содержимое списка записано в файл:" << filename2;
    } else {
        qDebug() << "Не удалось открыть файл для записи:" << filename2;
    }
    }
//########################################################################################################    
 if (    Odin_Programmi==false &&  Odin_Uchitelia==true)   // ошибочные не единицы 
 {
    // Записываем содержимое списка в файл
    QString filename2 = "/home/viktor/my_projects_qt_2/avto_Funktsiya_Resheniya_2/oshiboshnie_files_ne_1.txt";
    QFile file2(filename2);
    if (file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file2);
        for (int i = 0; i < listWidget.count(); i++) {
            out << listWidget.item(i)->text() << "\n";
        }
        file2.close();
        qDebug() << "Содержимое списка записано в файл:" << filename2;
    } else {
        qDebug() << "Не удалось открыть файл для записи:" << filename2;
    }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// 
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   std::cout << "avto_Funktsiya_Resheniya_2"<< std::endl;
   // надо иметь файл со списком с полными путями .txt изображений пейзажей
//   readFileLineByLine("/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji/paths_to_files.txt");
   // TODO: видимо переделать на выбор файла в диалоге
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// открываем файл для решения
    /// \brief fileName
///
//   if (Nazvaniye_fayla_s_neyronami_i_signalom=="")
//   {
//Nazvaniye_fayla_s_neyronami_i_signalom = line;
//QFileDialog::getOpenFileName(this,      tr("Open txt"), "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly", tr("Txt Files (*.txt)"));
       // надо записать название файла с сигналоми нейронами в файл
/*----------------------------------------------------------------------------------------------------------------------*/
//QFile file("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/название файла с нейронами и сигналами.txt");
//// самый новый файл с нейронами и сигналами
//if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//    return;

//QTextStream out(&file);
//out << Nazvaniye_fayla_s_neyronami_i_signalom;
//file.close();
/*----------------------------------------------------------------------------------------------------------------------*/
  // }
////
/////   


/// 

/// 
}

Dialog::~Dialog()
{
    delete ui;
}

// кнопка Ошибка
void Dialog::on_pushButton_clicked()
{
    if ( Odin_Programmi==false) // Если не распознана 1:
    {
        Odin_Uchitelia=true; ui->label_2->setText ("Odin_Programmi==false; Odin_Uchitelia=true");
       
        QProcess::startDetached(
         
"/home/viktor/my_projects_qt_2/build-cycle_of_distinguishing_a_one_with_vectors_GUI-Desktop_Qt_5_12_12_GCC_64bit-Debug/cycle_of_distinguishing_a_one_with_vectors_GUI"
                                , qApp->arguments());  
//   qApp->quit();
    }
    else //Если не распознана не 1:
    {
        Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
       
        QProcess::startDetached(

           "/home/viktor/my_projects_qt_2_build/build-bez_1_GUI-Desktop_Qt_5_12_12_GCC_64bit-Release/bez_1_GUI"
            , qApp->arguments());  

    }
    //        Odin_Programmi==false;
    // если одно сочетание запускаем одну программу, если другое - другую
}


void Dialog::on_pushButton_3_clicked() // заведомые не 1
{
 // неплохо получить тут название проверяемой папки и записать её как... 
    Odin_Uchitelia=false; 
      readFileLineByLine(//"/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji/paths_to_files.txt"
                        // "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji_2/output.txt"
                        "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji/paths_to_files.txt"
                        );
      // список файлов для проверки
       std::cout << std::endl<<"программа avto_Funktsiya_Resheniya_2 окончена"<< std::endl;
}


void Dialog::on_pushButton_2_clicked() // заведомые 1
{
  Odin_Uchitelia=true;   
    readFileLineByLine(
   // "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji/paths_to_files.txt"
   "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/Edinitsy_iz_shriftov_posle_pereustanovki_Debiana/output.txt"
    );
     // список файлов для проверки
     std::cout <<  std::endl<<"программа avto_Funktsiya_Resheniya_2 окончена"<< std::endl;
}

