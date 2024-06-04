#include "supplies.h"
#include "ui_supplies.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "adminmenu.h"

#include <iostream>


supplies::supplies(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::supplies)
{
    ui->setupUi(this);
      connect(ui->btnSelectAll,SIGNAL(clicked(bool)),this, SLOT(selectAll()));
      // Количество столбцов
      ui->twotchet->setColumnCount(4);
      // Возможность прокрутки
      ui->twotchet->setAutoScroll(true);
      // Режим выделения ячеек - только одна строка
      ui->twotchet->setSelectionMode(QAbstractItemView::SingleSelection);
      ui->twotchet->setSelectionBehavior(QAbstractItemView::SelectRows);
      // Заголовки таблицы
      ui->twotchet->setHorizontalHeaderItem(0,new QTableWidgetItem("Автор"));
      ui->twotchet->setHorizontalHeaderItem(1,new QTableWidgetItem("Имя"));
      ui->twotchet->setHorizontalHeaderItem(2,new QTableWidgetItem("Название книги"));
      ui->twotchet->setHorizontalHeaderItem(3,new QTableWidgetItem("Количество"));
//      ui->twotchet->setHorizontalHeaderItem(4,new QTableWidgetItem("Айди книги"));
//      ui->twotchet->setHorizontalHeaderItem(5,new QTableWidgetItem("Айди автора"));
      // Последний столбец растягивается при изменении размера формы
      ui->twotchet->horizontalHeader()->setStretchLastSection(true);
      // Разрешаем сортировку пользователю
      ui->twotchet->setSortingEnabled(false);
      //ui->twotchet->QTableView::sortByColumn(0);
      // Запрет на изменение ячеек таблицы при отображении
      ui->twotchet->setEditTriggers(QAbstractItemView::NoEditTriggers);

      ui->minCount->setValidator(new QIntValidator(0, 2147483647));
      ui->maxCount->setValidator(new QIntValidator(0, 2147483647));

    }

supplies::~supplies()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}


void supplies::dbconnect()
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
                auto lastError = dbconn.lastError().text();
                ui->teResult->append(lastError);
            }
        }
        else
        // Если соединение уже открыто, то сообщить об этом
            ui->teResult->append("Connect is already open...");
    }


void supplies::selectAll()
{
// Очистить содержимое компонента
//ui->twotchet->clearContents();
// Если соединение не открыто, то вызвать нашу функцию для открытия
// если подключиться не удалось, то вывести сообщение об ошибке и
// выйти из функции
if( !dbconn.isOpen() )
{
dbconnect();
if( !dbconn.isOpen() )
{
QMessageBox::critical(this,"Error",dbconn.lastError().text());
return;
}
}
// Создать объект запроса с привязкой к установленному соединению
QSqlQuery query(dbconn);
// Создать строку запроса на выборку данных
QString sqlstr = "select author.family, author.name, book.title, book.count, authorship.book_id, authorship.id from book join authorship on (book.id = authorship.book_id) join author on (author.id = authorship.author_id)";
// Выполнить запрос и поверить его успешность
if( !query.exec(sqlstr) )
{
QMessageBox::critical(this,"Error", query.lastError().text());
return;
}
// Если запрос активен (успешно завершен),
// то вывести сообщение о прочитанном количестве строк в окно вывода
// и установить количество строк для компонента таблицы
if( query.isActive())
ui->twotchet->setRowCount( query.size());
else
ui->twotchet->setRowCount( 0);
ui->teResult->append( QString("Read %1 rows").arg(query.size()));
// Прочитать в цикле все строки результата (курсора)
// и вывести их в компонент таблицы
int i=0;
while(query.next())
{
    ui->twotchet->setItem(i,0,new
    QTableWidgetItem(query.value(0).toString()));
    ui->twotchet->setItem(i,1,new
    QTableWidgetItem(query.value(1).toString()));
    ui->twotchet->setItem(i,2,new
    QTableWidgetItem(query.value(2).toString()));
    ui->twotchet->setItem(i,3,new
    QTableWidgetItem(query.value(3).toString()));
    ui->twotchet->setItem(i,4,new
    QTableWidgetItem(query.value(4).toString()));
    ui->twotchet->setItem(i,5,new
    QTableWidgetItem(query.value(5).toString()));
i++;
}
}

void supplies::search()
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
    //select author.surname, author.names, book.title, book.count from book, author
    //QString sqlstr = "select author.surname, author.names, book.title, book.count from book join authorship on (book.id_book = authorship.id_book) join author on (author.id_author = authorship.id_author)";
    QString sqlstr = "select author.family, author.name, book.title, book.count, authorship.book_id, authorship.author from book join authorship on book.id = authorship.book_id join author on author.author_id = authorship.id;";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leSea->text());
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    ui->twotchet->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->twotchet->setItem(i,0,new
        QTableWidgetItem(query.value("family").toString()));
        ui->twotchet->setItem(i,1,new
        QTableWidgetItem(query.value("name").toString()));
        ui->twotchet->setItem(i,2,new
        QTableWidgetItem(query.value("title").toString()));
        ui->twotchet->setItem(i,3,new
        QTableWidgetItem(query.value("count").toString()));
        ui->twotchet->setItem(i,4,new
        QTableWidgetItem(query.value("authorship.book_id").toString()));
        ui->twotchet->setItem(i,5,new
        QTableWidgetItem(query.value("author_id").toString()));
        i++;
    }
    ui->teResult->append( QString("Поиск выполнен успешно").arg(query.numRowsAffected()) );
}

void supplies::on_btnMenu_clicked()
{
    this->close();
    adminmenu *amenu = new adminmenu(this);
    amenu->show();
}

void supplies::on_btnSea_clicked()
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
    //select author.surname, author.names, book.title, book.count from book, author
    QString sqlstr = "select author.family, author.name, book.title, book.count, authorship.book_id, authorship.id from book join authorship on (book.id = authorship.book_id) join author on (author.id = authorship.author_id) where author.family ILIKE '%' || ? || '%'";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leSea->text());
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    ui->twotchet->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->twotchet->setItem(i,0,new
        QTableWidgetItem(query.value("family").toString()));
        ui->twotchet->setItem(i,1,new
        QTableWidgetItem(query.value("name").toString()));
        ui->twotchet->setItem(i,2,new
        QTableWidgetItem(query.value("title").toString()));
        ui->twotchet->setItem(i,3,new
        QTableWidgetItem(query.value("count").toString()));
        ui->twotchet->setItem(i,4,new
        QTableWidgetItem(query.value("authorship.book_id").toString()));
        ui->twotchet->setItem(i,5,new
        QTableWidgetItem(query.value("authorship.id").toString()));
        i++;
    }
    ui->teResult->append( QString("Поиск выполнен успешно").arg(query.numRowsAffected()) );
}

void supplies::on_btnSelectAll_2_clicked()
{
    QString minCount = ui->minCount->text();
    QString maxCount = ui->maxCount->text();
    if (minCount >= maxCount) {
        return;
    }

    if( !dbconn.isOpen() )
    {
    dbconnect();
    if( !dbconn.isOpen() )
    {
    QMessageBox::critical(this,"Error",dbconn.lastError().text());
    return;
    }
    }
    // Создать объект запроса с привязкой к установленному соединению
    QSqlQuery query(dbconn);
    // Создать строку запроса на выборку данных
    QString sqlstr = "select author.family, author.name, book.title, book.count, authorship.book_id, authorship.id from book join authorship on (book.id = authorship.book_id) join author on (author.id = authorship.author_id) where book.count between " + minCount + " and " + maxCount;
//    std::cout << sqlstr;
//    bool err = query.prepare(sqlstr);
//    query.bindValue(0, minCount);
//    query.bindValue(1, maxCount);
//    if (err) {
//        QMessageBox::critical(this,"Error", "Запрос неправильный");
//        return;
//    }
    // Выполнить запрос и поверить его успешность
    if( !query.exec(sqlstr) )
    {
    QMessageBox::critical(this,"Error", query.lastError().text());
    return;
    }
    // Если запрос активен (успешно завершен),
    // то вывести сообщение о прочитанном количестве строк в окно вывода
    // и установить количество строк для компонента таблицы
    if( query.isActive())
    ui->twotchet->setRowCount( query.size());
    else
    ui->twotchet->setRowCount( 0);
    ui->teResult->append( QString("Read %1 rows").arg(query.size()));
    // Прочитать в цикле все строки результата (курсора)
    // и вывести их в компонент таблицы
    int i=0;
    while(query.next())
    {
        ui->twotchet->setItem(i,0,new
        QTableWidgetItem(query.value(0).toString()));
        ui->twotchet->setItem(i,1,new
        QTableWidgetItem(query.value(1).toString()));
        ui->twotchet->setItem(i,2,new
        QTableWidgetItem(query.value(2).toString()));
        ui->twotchet->setItem(i,3,new
        QTableWidgetItem(query.value(3).toString()));
        ui->twotchet->setItem(i,4,new
        QTableWidgetItem(query.value(4).toString()));
        ui->twotchet->setItem(i,5,new
        QTableWidgetItem(query.value(5).toString()));
    i++;
    }
}
