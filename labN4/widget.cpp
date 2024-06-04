#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->dbconnect();
    connect(ui->btnConnect,SIGNAL(clicked(bool)),this, SLOT(dbconnect()));
    connect(ui->btnSelectAll, SIGNAL(clicked(bool)), this, SLOT(selectAll()));
    connect(ui->btnAdd, SIGNAL(clicked(bool)), this, SLOT(add()));
    connect(ui->btnDel, SIGNAL(clicked(bool)), this, SLOT(del()));
    connect(ui->btnEdit, SIGNAL(clicked(bool)), this, SLOT(edit()));
    connect(ui->twOrg, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(selectedItem(QTableWidgetItem*)));

    ui->twOrg->setColumnCount(4);
    // Возможность прокрутки
    ui->twOrg->setAutoScroll(true);
    // Режим выделения ячеек - только одна строка
    ui->twOrg->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->twOrg->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Заголовки таблицы
    ui->twOrg->setHorizontalHeaderItem(0,new QTableWidgetItem("Abbr"));
    ui->twOrg->setHorizontalHeaderItem(1,new QTableWidgetItem("Title"));
    ui->twOrg->setHorizontalHeaderItem(2,new QTableWidgetItem("City"));
    ui->twOrg->setHorizontalHeaderItem(3,new QTableWidgetItem("INN"));
    // Последний столбец растягивается при изменении размера формы
    ui->twOrg->horizontalHeader()->setStretchLastSection(true);
    // Разрешаем сортировку пользователю
    ui->twOrg->setSortingEnabled(true);
    // ui->twOrg->sortByColumn(0);
    // Запрет на изменение ячеек таблицы при отображении
    ui->twOrg->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Widget::~Widget()
{
    delete ui;
    if( dbconn.isOpen())
    dbconn.close();
}

void Widget::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_login_clicked()
{
    QString username = ui->username->text();
        QString password = ui->password->text();

    if (username == "ahmed" && password == "kashima")
    {
        //QMessageBox::information(this, "Login", "Username and Password are correct");
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and Password are incorrect");
    }
}

void Widget::dbconnect()
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
        dbconn.setDatabaseName("dbtest");
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


void Widget::selectAll()
{
// Очистить содержимое компонента
   ui->twOrg->clearContents();
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
    QString sqlstr = "select * from org";
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
        ui->twOrg->setRowCount( query.size());
    else
        ui->twOrg->setRowCount( 0);
    ui->teResult->append( QString("Read %1 rows").arg(query.size()));
    // Прочитать в цикле все строки результата (курсора)
    // и вывести их в компонент таблицы
    int i=0;
    while(query.next())
    {
        ui->twOrg->setItem(i,0,new
        QTableWidgetItem(query.value("abbr").toString()));
        ui->twOrg->setItem(i,1,new
        QTableWidgetItem(query.value("title").toString()));
        ui->twOrg->setItem(i,2,new
        QTableWidgetItem(query.value("city").toString()));
        ui->twOrg->setItem(i,3,new
        QTableWidgetItem(query.value("inn").toString()));

        i++;
    }
}


void Widget::add()
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
    QString sqlstr = "insert into org(abbr,title,city,inn) values(?,?,?,?)";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->lbAbbr->text());
    query.bindValue(1,ui->lbTitle->text());
    query.bindValue(2,ui->lbCity->text());
    // Если тип поля отличается от строкового, то преобразовать его
    query.bindValue(3,ui->lbInn->text().toLongLong());
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


void Widget::del()
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
    int currow = ui->twOrg->currentRow();
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
    QString sqlstr = "delete from org where abbr = '"
    + ui->twOrg->item(currow,0)->text() + "'";
    // Выполнить строку запроса и проверить его успешность
    if( !query.exec(sqlstr) )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    // Вывести сообщение об удалении строки
    ui->teResult->append( QString("Del %1 rows").arg(query.numRowsAffected()) );
    // Обновить содержимое компонента таблицы
    selectAll();
}

void Widget::selectedItem(QTableWidgetItem * item)
{
    const auto abbr = ui->twOrg->item(item->row(), 0)->text();
    this->loadSingleAbbr(abbr);
}

void Widget::loadSingleAbbr(QString abbr)
{
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
    QString sqlstr = "select * from org where abbr = ?";

    query.prepare(sqlstr);
    query.bindValue(0, abbr);
    // Выполнить запрос и поверить его успешность
    if( !query.exec() )
    {
        QMessageBox::critical(this,"Error", query.lastError().text());
        return;
    }
    // Если запрос активен (успешно завершен),
    // то вывести сообщение о прочитанном количестве строк в окно вывода
    // и установить количество строк для компонента таблицы
    ui->teResult->append( QString("Read %1 rows").arg(query.size()));
    // Прочитать в цикле все строки результата (курсора)
    // и вывести их в компонент таблицы
    int i=0;
    while(query.next())
    {
        ui->lbAbbr->setText(query.value("abbr").toString());
        ui->lbTitle->setText(query.value("title").toString());
        ui->lbCity->setText(query.value("city").toString());
        ui->lbInn->setText(query.value("inn").toString());

        i++;
    }
}



void Widget::edit()
{
    // Подключение к БД
    if (!dbconn.isOpen())
    {
        dbconnect();
        if (!dbconn.isOpen())
        {
            QMessageBox::critical(this, "Error", dbconn.lastError().text());
            return;
        }
    }
    // Получить номер выбранной строки в компоненте таблицы
    int currow = ui->twOrg->currentRow();
    // Если он меньше 0 (строка не выбрана), то
    // сообщение об ошибке и выход из функции
    if (currow < 0)
    {
        QMessageBox::critical(this, "Error", "Not selected row!");
        return;
    }
    // Создать объект запроса
    QSqlQuery query(dbconn);
    // Получить значения из редактируемых полей
    QString abbr = ui->lbAbbr->text();
    QString title = ui->lbTitle->text();
    QString city = ui->lbCity->text();
    QString inn = ui->lbInn->text();
    // Создать строку запроса для обновления записи
    QString sqlstr = "update org set title = ?, city = ?, inn = ? where abbr = ?";
    query.prepare(sqlstr);
    // Привязать значения к параметрам запроса
    query.bindValue(0, title);
    query.bindValue(1, city);
    query.bindValue(2, inn);
    query.bindValue(3, abbr);
    // Выполнить запрос и проверить его успешность
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }
    // Вывести сообщение об успешном обновлении записи
    ui->teResult->append("Record updated successfully.");
    // Обновить содержимое компонента таблицы
    selectAll();
}


//void Widget::edit()
//{
//    // Подключиться к БД
//    if (!dbconn.isOpen())
//    {
//        dbconnect();
//        if (!dbconn.isOpen())
//        {
//            QMessageBox::critical(this, "Error", dbconn.lastError().text());
//            return;
//        }
//    }
//    QSqlQuery query(dbconn);
//    // Создать строку запроса
//    QString sqlstr = "update org set title=?, city=?, inn=? where abbr=?";
//    // Подготовить запрос
//    query.prepare(sqlstr);
//    // Передать параметры из полей ввода в запрос
//    query.bindValue(0, ui->lbTitle->text());
//    query.bindValue(1, ui->lbCity->text());
//    // Если тип поля отличается от строкового, то преобразовать его
//    query.bindValue(2, ui->lbInn->text().toLongLong());
//    query.bindValue(3, ui->lbAbbr->text());
//    // Выполнить запрос
//    if (!query.exec())
//    {
//        ui->teResult->append(query.lastQuery());
//        QMessageBox::critical(this, "Error", query.lastError().text());
//        return;
//    }
//    // Если запрос выполнен, то вывести сообщение о добавлении строки
//    ui->teResult->append(QString("Updated %1 rows").arg(query.numRowsAffected()));
//    // и обновить записи в компоненте таблицы
//    selectAll();
//}

