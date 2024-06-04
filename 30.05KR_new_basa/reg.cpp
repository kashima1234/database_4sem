#include "reg.h"
#include "ui_reg.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "usermenu.h"

reg::reg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reg)
{
    ui->setupUi(this);
    connect(ui->btnAdd,SIGNAL(clicked(bool)),this, SLOT(add()));
    ui->twemployees->setColumnCount(1);
    ui->twemployees->setAutoScroll(true);
    // Режим выделения ячеек - только одна строка
    ui->twemployees->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->twemployees->setSelectionBehavior(QAbstractItemView::SelectRows);
      ui->twemployees->setHorizontalHeaderItem(0,new QTableWidgetItem("ID"));
      // Последний столбец растягивается при изменении размера формы
      ui->twemployees->horizontalHeader()->setStretchLastSection(true);
      // Разрешаем сортировку пользователю
      ui->twemployees->setSortingEnabled(false);
      //ui->twemployees->QTableView::sortByColumn(0);
      // Запрет на изменение ячеек таблицы при отображении
      ui->twemployees->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

reg::~reg()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}

void reg::dbconnect()
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





void reg::add()
{
if( ui->leFam->text().isEmpty() || ui->lePat->text().isEmpty()
    || ui->leBir->text().isEmpty() )
{
    QMessageBox::critical(this,"Error","All fields are empty!");
    return;
}
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
QString sqlstr = "insert into abonent(family, name, patronymic, birth_date) values(?,?,?,?)";
// Подготовить запрос
query.prepare(sqlstr);
// Передать параметры из полей ввода в запрос
query.bindValue(0,ui->leFam->text());
query.bindValue(1,ui->leNam->toPlainText());
query.bindValue(2,ui->lePat->text());
query.bindValue(3,ui->leBir->text());
// Выполнить запрос
if( !query.exec() )
{
ui->teResult->append( query.lastQuery());
QMessageBox::critical(this,"Error","Регистрация не успешна. Возможно, уже есть запись с такими данными.");
return;
}
// Если запрос выполнен, то вывести сообщение одобавлении строки
ui->teResult->append( QString("AddRead %1 rows").arg(query.numRowsAffected()) );
// и обновить записи в компоненте таблицы
if( QMessageBox::question(this,"Регистрация","Вы успешно зарегистрировали пользователя! В поле ID абонентa появился номер абонента. Обязательно его запомните!",
QMessageBox::Ok)==QMessageBox::Ok)
search();
}

void reg::on_btnMenu_clicked()
{
    this->close();
    usermenu *umenu = new usermenu(this);
    umenu->show();
}


void reg::search()
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
    QString sqlstr = "select id from abonent where family LIKE '%' || ? || '%'";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leFam->text());
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    ui->twemployees->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->twemployees->setItem(i,0,new
        QTableWidgetItem(query.value("id").toString()));
        i++;
    }
}
