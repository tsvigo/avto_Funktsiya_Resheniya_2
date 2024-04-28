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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief list_of_synapses
/// переменные:
std::vector<unsigned long long> list_of_synapses ;
std::vector<unsigned long long
            //  int
            > list_of_neurons[201] ;//={};
long long variable_error;
QString
// std::string
    Nazvaniye_fayla_s_neyronami_i_signalom="";
  
bool Odin_Uchitelia;
bool Odin_Programmi;
     QString line;
///////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////// \brief readFileLineByLine
////////////////////////////////////////////////////////////////////////////////////////////////////// \param filename
void readFileLineByLine(const QString& filename) {
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
///     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////        
        qDebug() << Nazvaniye_fayla_s_neyronami_i_signalom;
    } // цикл

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
   readFileLineByLine("/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/peyzaji/paths_to_files.txt");
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
    else
    {
        Odin_Uchitelia=false;  ui->label_2->setText ("Odin_Programmi==true; Odin_Uchitelia=false");
       
        QProcess::startDetached(

           "/home/viktor/my_projects_qt_2_build/build-bez_1_GUI-Desktop_Qt_5_12_12_GCC_64bit-Release/bez_1_GUI"
            , qApp->arguments());  

    }
    //        Odin_Programmi==false;
    // если одно сочетание запускаем одну программу, если другое - другую
}

