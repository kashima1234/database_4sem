#include "mainwindow.h"
#include "adminmenu.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
ui->setupUi(this);
connect(ui->btnConnect,SIGNAL(clicked(bool)),this, SLOT(dbconnect()));
connect(ui->btnSelectAll,SIGNAL(clicked(bool)),this, SLOT(selectAll()));
connect(ui->btnClear,SIGNAL(clicked(bool)),this, SLOT(Clearr()));
connect(ui->btnAdd,SIGNAL(clicked(bool)),this, SLOT(add()));
connect(ui->btnDel,SIGNAL(clicked(bool)),this, SLOT(del()));
connect(ui->btnEdit,SIGNAL(clicked(bool)),this, SLOT(edit()));
connect(ui->btnSearch,SIGNAL(clicked(bool)),this, SLOT(search()));
// Количество столбцов
ui->twCustomers->setColumnCount(2);
// Возможность прокрутки
ui->twCustomers->setAutoScroll(true);
// Режим выделения ячеек - только одна строка
ui->twCustomers->setSelectionMode(QAbstractItemView::SingleSelection);
ui->twCustomers->setSelectionBehavior(QAbstractItemView::SelectRows);
// Заголовки таблицы
ui->twCustomers->setHorizontalHeaderItem(0,new QTableWidgetItem("Название"));
ui->twCustomers->setHorizontalHeaderItem(1,new QTableWidgetItem("Описание"));
//ui->twCustomers->setHorizontalHeaderItem(2,new QTableWidgetItem("Логотип"));
// Последний столбец растягивается при изменении размера формы
ui->twCustomers->horizontalHeader()->setStretchLastSection(true);
// Разрешаем сортировку пользователю
ui->twCustomers->setSortingEnabled(false);
// ui->twCustomers->QTableView::sortByColumn(0);
// Запрет на изменение ячеек таблицы при отображении
ui->twCustomers->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}

void MainWindow::dbconnect()
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

void MainWindow::Clearr()
{
 ui->twCustomers->clearContents();
}

void MainWindow::add()
{
// Подключиться к БД
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
QString sqlstr = "insert into publish(title, description) values(?,?)";
// Подготовить запрос
query.prepare(sqlstr);
// Передать параметры из полей ввода в запрос
query.bindValue(0,ui->leTit->text());
query.bindValue(1,ui->leYea->toPlainText());
//query.bindValue(2,ui->leCou->text());
// Выполнить запрос
if( !query.exec() )
{
ui->teResult->append( query.lastQuery());
QMessageBox::critical(this,"Error",query.lastError().text());
return;
}
// Если запрос выполнен, то вывести сообщение одобавлении строки
ui->teResult->append( QString("AddRead %1 rows").arg(query.numRowsAffected()) );
// и обновить записи в компоненте таблицы
selectAll();
}

void MainWindow::del()
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
// Получить номер выбранной строки в компоненте таблицы
int currow = ui->twCustomers->currentRow();
// Если он меньше 0 (строка не выбрана), то
// сообщение об ошибке и выход из функции
if( currow < 0 )
{
QMessageBox::critical(this,"Error","Not selected row!");
return;
}
// Спросить у пользователя подтверждение удаления записи
// Используется статический метод QMessageBox::question
// для задания вопроса, который возвращает код нажатой кнопки

if( QMessageBox::question(this,"Delete","Delete row?",
QMessageBox::Cancel,QMessageBox::Ok)==QMessageBox::Cancel)
return;
// Создать объект запроса
QSqlQuery query(dbconn);
// Создать строку запроса.
// Вместо подготовки запроса и передачи параметров значение параметра
// конкатенируется со строкой запроса
// Обратите,что строковое значение помещается в одинарные кавычки
// Значение выбирается из компонента таблицы методом item(row,col)
QString sqlstr = "delete from publish where title = '"
+ ui->twCustomers->item(currow,0)->text() + "'";
// Выполнить строку запроса и проверить его успешность
if( !query.exec(sqlstr) )
{
ui->teResult->append( query.lastQuery());
QMessageBox::critical(this,"Error","Издательство невозможно удалить, т.к. есть книги, в которых оно указано.");
return;
}
// Вывести сообщение об удалении строки
ui->teResult->append( QString("Del %1 rows").arg(query.numRowsAffected()) );
// Обновить содержимое компонента таблицы
selectAll();
}

void MainWindow::edit()
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
// Получить номер выбранной строки в компоненте таблицы
int currow = ui->twCustomers->currentRow();
// Если он меньше 0 (строка не выбрана), то
// сообщение об ошибке и выход из функции
if( currow < 0 )
{
QMessageBox::critical(this,"Error","Not selected row!");
return;
}
// Спросить у пользователя подтверждение удаления записи
// Используется статический метод QMessageBox::question
// для задания вопроса, который возвращает код нажатой кнопки

if( QMessageBox::question(this,"Edit","Edit row?",
QMessageBox::Cancel,QMessageBox::Ok)==QMessageBox::Cancel)
return;
// Создать объект запроса
QSqlQuery query(dbconn);
// Создать строку запроса.
// Вместо подготовки запроса и передачи параметров значение параметра
// конкатенируется со строкой запроса
// Обратите,что строковое значение помещается в одинарные кавычки
// Значение выбирается из компонента таблицы методом item(row,col)
//book(title, year_of_publiction, count)
QString sqlstr = "update publish set title = ? , description = ? where title = '" + ui->twCustomers->item(currow,0)->text() + "'";
// Подготовить запрос
query.prepare(sqlstr);
// Передать параметры из полей ввода в запрос
query.bindValue(0,ui->leTit->text());
query.bindValue(1,ui->leYea->toPlainText());
//query.bindValue(2,ui->leCou->text());

// Выполнить запрос
if( !query.exec() )
{
    ui->teResult->append( query.lastQuery());
    QMessageBox::critical(this,"Error",query.lastError().text());
    return;
}
// Если запрос выполнен, то вывести сообщение одобавлении строки
ui->teResult->append( QString("AddRead %1rows").arg(query.numRowsAffected()) );
// и обновить записи в компоненте таблицы
selectAll();

}

void MainWindow::selectAll()
{
// Очистить содержимое компонента
//ui->twCustomers->clearContents();
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
QString sqlstr = "select * from publish";
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
ui->twCustomers->setRowCount( query.size());
else
ui->twCustomers->setRowCount( 0);
ui->teResult->append( QString("Read %1 rows").arg(query.size()));
// Прочитать в цикле все строки результата (курсора)
// и вывести их в компонент таблицы
int i=0;
//book(title, year_of_publiction, count)
while(query.next())
{
ui->twCustomers->setItem(i,0,new
QTableWidgetItem(query.value("title").toString()));
ui->twCustomers->setItem(i,1,new
QTableWidgetItem(query.value("description").toString()));
//ui->twCustomers->setItem(i,2,new
//QTableWidgetItem(query.value("logo").toString()));

i++;
}
}

void MainWindow::search()
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
    QString sqlstr = "select * from publish where title LIKE '%' || ? || '%'";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leSearch->text());
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    ui->twCustomers->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->twCustomers->setItem(i,0,new
        QTableWidgetItem(query.value("title").toString()));
        ui->twCustomers->setItem(i,1,new
        QTableWidgetItem(query.value("description").toString()));
//        ui->twCustomers->setItem(i,2,new
//        QTableWidgetItem(query.value("logo").toString()));
        i++;
    }
    ui->teResult->append( QString("Поиск выполнен успешно").arg(query.numRowsAffected()) );
}


void MainWindow::on_btnMenu_clicked()
{
    this->close();
    adminmenu *amenu = new adminmenu(this);
    amenu->show();
}

void MainWindow::on_btnEdit1_clicked()
{
    int currow = ui->twCustomers->currentRow();

    // Если он меньше 0 (строка не выбрана), то
    // сообщение об ошибке и выход из функции
    if( currow < 0 )
    {
        QMessageBox::critical(this,"Error","Not selected row!");
        return;
    }
            ui->leTit->setText(ui->twCustomers->item(ui->twCustomers->currentRow(),0)->text());
            ui->leYea->setText(ui->twCustomers->item(ui->twCustomers->currentRow(),1)->text());
//            ui->leCou->setText(ui->twCustomers->item(ui->twCustomers->currentRow(),2)->text());
}

