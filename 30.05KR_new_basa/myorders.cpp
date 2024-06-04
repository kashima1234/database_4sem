#include "myorders.h"
#include "ui_myorders.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "usermenu.h"

#include <iostream>

myorders::myorders(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myorders)
{

    ui->setupUi(this);
      connect(ui->btnSelectAll,SIGNAL(clicked(bool)),this, SLOT(search()));
      // connect(ui->btnSelectAll_2,SIGNAL(clicked(bool)),this, SLOT(search2()));
      // connect(ui->btnSelectAll_3,SIGNAL(clicked(bool)),this, SLOT(search3()));
      // Количество столбцов
      ui->two->setColumnCount(7);
      // Возможность прокрутки
      ui->two->setAutoScroll(true);
      // Режим выделения ячеек - только одна строка
      ui->two->setSelectionMode(QAbstractItemView::SingleSelection);
      ui->two->setSelectionBehavior(QAbstractItemView::SelectRows);
      // Заголовки таблицы
      // Select abonent.id,abonent.family,abonent.names,abonent.patronymic,book.id,book.title,record.taken_date,record.return_date
      ui->two->setHorizontalHeaderItem(0,new QTableWidgetItem("Фамилия"));
      ui->two->setHorizontalHeaderItem(1,new QTableWidgetItem("Имя"));
      ui->two->setHorizontalHeaderItem(2,new QTableWidgetItem("Отчество"));
      ui->two->setHorizontalHeaderItem(3,new QTableWidgetItem("Айди книги"));
      ui->two->setHorizontalHeaderItem(4,new QTableWidgetItem("Название"));
      ui->two->setHorizontalHeaderItem(5,new QTableWidgetItem("Дата выдачи"));
      ui->two->setHorizontalHeaderItem(6,new QTableWidgetItem("Дата возврата"));

      // Последний столбец растягивается при изменении размера формы
      ui->two->horizontalHeader()->setStretchLastSection(true);
      // Разрешаем сортировку пользователю
      ui->two->setSortingEnabled(false);
      //ui->two->QTableView::sortByColumn(0);
      // Запрет на изменение ячеек таблицы при отображении
      ui->two->setEditTriggers(QAbstractItemView::NoEditTriggers);

    }

myorders::~myorders()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}

void myorders::dbconnect()
{
    if(!dbconn.isOpen())
    {
    // Если соединение не открыто, то вывести список доступных драйверов БД
    // (вывод в поле teResult, метод append добавляет строки).
    ui->teResult->append("SQL drivers:");
    ui->teResult->append(QSqlDatabase::drivers().join(","));
    // Создать глобальную переменную для установки соединения с БД
    dbconn=QSqlDatabase::addDatabase("QPSQL");
    // Установить параметры соединения: имя БД, адрес хоста, логин и пароль
    //пользователя, порт (если отличается от стандартного)
    dbconn.setDatabaseName("KRDATABASE");
    dbconn.setHostName("localhost");
    dbconn.setUserName("postgres");
    dbconn.setPassword("postgres");
    // Открыть соединениe и результат вывести в окно вывода
    if( dbconn.open() )
    ui->teResult->append("Connect is open...");
    else
    {
    ui->teResult->append("Error of connect:");
    ui->teResult->append(dbconn.lastError().text());
    }
    }
    else
    // Если соединение уже открыто, то сообщить об этом
    ui->teResult->append("Connect is already open...");
    }

void myorders::search()
{
    // Подключение к БД
    if( !dbconn.isOpen() )
    {
    dbconnect();
    if( !dbconn.isOpen() )
    {
    QMessageBox::critical(this,"Error",dbconn.lastError().text());
    return;
    }
    }
    QSqlQuery query(dbconn);
    // Создать строку запроса
    //QString sqlstr = "select * from view3 where fio LIKE '%' || ? || '%'";
//    QString sqlstr = "Select abonent.family,abonent.name,abonent.patronymic,book.id,book.title,record.taken_date,record.return_date from abonent join record on(abonent.id = record.abonent_id) join book on(book.id = record.book_id) where abonent.family ilike '%' || ? || '%'";
    QString sqlstr = "Select abonent.family,abonent.name,abonent.patronymic,book.id,book.title,record.taken_date,record.return_date from abonent join record on(abonent.id = record.abonent_id) join book on(book.id = record.book_id) where abonent.family ilike '%' || ? || '%'";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leSearch->text());
    std::cout << ui->leSearch->text().toStdString() << std::endl;
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    ui->two->setRowCount(query.numRowsAffected());
    std::cout << query.numRowsAffected() << std::endl;
    std::cout << query.result() << std::endl;

    int i = 0;
    while(query.next())
    {
        //abonent.id_abonent,abonent.surname,abonent.names,abonent.patronymic,book.id_book,book.title,record.date_of_taken_book,record.date_of_return_book
        ui->two->setItem(i,0,new
        QTableWidgetItem(query.value(0).toString()));
        ui->two->setItem(i,1,new
        QTableWidgetItem(query.value(1).toString()));
        ui->two->setItem(i,2,new
        QTableWidgetItem(query.value(2).toString()));
        ui->two->setItem(i,3,new
        QTableWidgetItem(query.value(3).toString()));
        ui->two->setItem(i,4,new
        QTableWidgetItem(query.value(4).toString()));
        ui->two->setItem(i,5,new
        QTableWidgetItem(query.value(5).toString()));
        ui->two->setItem(i,6,new
        QTableWidgetItem(query.value(6).toString()));
        i++;
    }
}

// void myorders::search2()
// {
//     // Подключение к БД
//     if( !dbconn.isOpen() )
//     {
//     dbconnect();
//     if( !dbconn.isOpen() )
//     {
//     QMessageBox::critical(this,"Error",dbconn.lastError().text());
//     return;
//     }
//     }
//     QSqlQuery query(dbconn);
//     // Создать строку запроса
//     //QString sqlstr = "select * from view3 where fio LIKE '%' || ? || '%'";
//     QString sqlstr = "Select abonent.id,abonent.family,abonent.name,abonent.patronymic,book.id,book.title, record.taken_date,record.return_date from abonent join record on(abonent.id = record.abonent_id) join book on(book.id = record.book_id) where (record.return_date is null) and (book.title LIKE '%' || ? || '%')";
//     // Подготовить запрос
//     query.prepare(sqlstr);
//     // Передать параметры из полей ввода в запрос
//     query.bindValue(0,ui->leSearch_2->text());
//     // Выполнить запрос
//     if( !query.exec() )
//     {
//         ui->teResult->append( query.lastQuery());
//         QMessageBox::critical(this,"Error",query.lastError().text());
//         return;
//     }
//     ui->two->setRowCount(query.numRowsAffected());
//     int i = 0;
//     while(query.next())
//     {
//         QString sqlstr = "Select abonent.id,abonent.family,abonent.name,abonent.patronymic,book.id,book.title, record.taken_date,record.return_date from abonent join record on(abonent.id = record.abonent_id) join book on(book.id = record.book_id) where (record.return_date is null) and (book.title LIKE '%' || ? || '%')";
//         //abonent.id_abonent,abonent.surname,abonent.names,abonent.patronymic,book.id_book,book.title,record.taken_date,record.return_date
//         ui->two->setItem(i,0,new
//         QTableWidgetItem(query.value("abonent.family").toString()));
//         ui->two->setItem(i,1,new
//         QTableWidgetItem(query.value("abonent.name").toString()));
//         ui->two->setItem(i,2,new
//         QTableWidgetItem(query.value("abonent.patronymic").toString()));
//         ui->two->setItem(i,3,new
//         QTableWidgetItem(query.value("book.id").toString()));
//         ui->two->setItem(i,4,new
//         QTableWidgetItem(query.value("book.title").toString()));
//         ui->two->setItem(i,5,new
//         QTableWidgetItem(query.value("record.taken_date").toString()));
//         ui->two->setItem(i,6,new
//         QTableWidgetItem(query.value("record.return_date").toString()));
//         i++;
//     }
// }

// void myorders::search3()
// {
//     // Подключение к БД
//     if( !dbconn.isOpen() )
//     {
//     dbconnect();
//     if( !dbconn.isOpen() )
//     {
//     QMessageBox::critical(this,"Error",dbconn.lastError().text());
//     return;
//     }
//     }
//     QSqlQuery query(dbconn);
//     // Создать строку запроса
//     //QString sqlstr = "select * from view3 where fio LIKE '%' || ? || '%'";
//     QString sqlstr = "Select abonent.id,abonent.family,abonent.name,abonent.patronymic,book.id,book.title,record.taken_date,record.return_date from abonent join record on(abonent.id = record.abonent_id) join book on(book.id = record.book_id) where (record.return_date is null) and (record.taken_date<(now() - interval '30 days')) ";
//     // Подготовить запрос
//     query.prepare(sqlstr);
//     // Передать параметры из полей ввода в запрос
//     //query.bindValue(0,ui->leSearch->text());
//     // Выполнить запрос
//     if( !query.exec() )
//     {
//         ui->teResult->append( query.lastQuery());
//         QMessageBox::critical(this,"Error",query.lastError().text());
//         return;
//     }
//     ui->two->setRowCount(query.numRowsAffected());
//     int i = 0;
//     while(query.next())
//     {
//         //abonent.id_abonent,abonent.family,abonent.name,abonent.patronymic,book.id,book.title,record.taken_date,record.return_date
//         ui->two->setItem(i,0,new
//         QTableWidgetItem(query.value("abonent.family").toString()));
//         ui->two->setItem(i,1,new
//         QTableWidgetItem(query.value("abonent.name").toString()));
//         ui->two->setItem(i,2,new
//         QTableWidgetItem(query.value("abonent.patronymic").toString()));
//         ui->two->setItem(i,3,new
//         QTableWidgetItem(query.value("book.id").toString()));
//         ui->two->setItem(i,4,new
//         QTableWidgetItem(query.value("book.title").toString()));
//         ui->two->setItem(i,5,new
//         QTableWidgetItem(query.value("record.taken_date").toString()));
//         ui->two->setItem(i,6,new
//         QTableWidgetItem(query.value("record.return_date").toString()));
//         i++;
//     }
// }

void myorders::on_btnMenu_clicked()
{
    this->close();
    usermenu *umenu = new usermenu(this);
    umenu->show();
}



