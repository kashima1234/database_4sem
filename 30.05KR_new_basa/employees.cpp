#include "employees.h"
#include "ui_employees.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "adminmenu.h"
#include <QDate>
employees::employees(QWidget *parent) :
QMainWindow(parent),
  ui(new Ui::employees)
{
  ui->setupUi(this);
  connect(ui->btnConnect,SIGNAL(clicked(bool)),this, SLOT(dbconnect()));
  connect(ui->btnSelectAll,SIGNAL(clicked(bool)),this, SLOT(selectAll()));
  connect(ui->btnClear,SIGNAL(clicked(bool)),this, SLOT(Clearr()));
  connect(ui->btnAdd,SIGNAL(clicked(bool)),this, SLOT(add()));
  connect(ui->btnDel,SIGNAL(clicked(bool)),this, SLOT(del()));
  connect(ui->btnEdit,SIGNAL(clicked(bool)),this, SLOT(edit()));
  connect(ui->btnSearch,SIGNAL(clicked(bool)),this, SLOT(search()));
  connect(ui->btnFilterByDate, SIGNAL(clicked(bool)), this, SLOT(filterByBirthDate()));
  connect(ui->btnFilterByDates, SIGNAL(clicked(bool)), this, SLOT(filterByBirthAndDeathDates()));
  // Количество столбцов
  ui->twemployees->setColumnCount(6);
  // Возможность прокрутки
  ui->twemployees->setAutoScroll(true);
  // Режим выделения ячеек - только одна строка
  ui->twemployees->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->twemployees->setSelectionBehavior(QAbstractItemView::SelectRows);
  // Заголовки таблицы
  ui->twemployees->setHorizontalHeaderItem(0,new QTableWidgetItem("Фамилия"));
  ui->twemployees->setHorizontalHeaderItem(1,new QTableWidgetItem("Имя"));
  ui->twemployees->setHorizontalHeaderItem(2,new QTableWidgetItem("Отчество"));
  ui->twemployees->setHorizontalHeaderItem(3,new QTableWidgetItem("Дата рождения"));
  ui->twemployees->setHorizontalHeaderItem(4,new QTableWidgetItem("Дата смерти"));
  ui->twemployees->setHorizontalHeaderItem(5,new QTableWidgetItem("ID"));
  // Последний столбец растягивается при изменении размера формы
  ui->twemployees->horizontalHeader()->setStretchLastSection(true);
  // Разрешаем сортировку пользователю
  ui->twemployees->setSortingEnabled(false);
  //ui->twemployees->QTableView::sortByColumn(0);
  // Запрет на изменение ячеек таблицы при отображении
  ui->twemployees->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

employees::~employees()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}

void employees::dbconnect()
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

void employees::Clearr()
{
 ui->twemployees->clearContents();
}

void employees::add() {
    if(ui->leDea->text().isEmpty()) {
    QDate date = QDate::fromString(ui->leBir->text(),"yyyy-MM-dd");
    if(!date.isValid())
    {
        QMessageBox::critical(this,"Error","Invalid date format!");
        return;
    }
    } else {
        QDate date = QDate::fromString(ui->leBir->text(),"yyyy-MM-dd");
        QDate date1 = QDate::fromString(ui->leDea->text(),"yyyy-MM-dd");
        if(!date.isValid() || !date1.isValid())
        {
            QMessageBox::critical(this,"Error","Invalid date format!");
            return;
        }
    }

    // Проверить, что поле ввода date_of_death не пустое
    if(ui->leDea->text().isEmpty()){
        // Если пустое - создать запрос без этого поля
        // Создать строку запроса
        QString sqlstr = "insert into author(family, name, patronymic, birth_date, death_date) values(?,?,?,?,?)";
        // QString sqlstr = "INSERT INTO author (family, name, patronymic, birth_date, death_date, id) VALUES (?, ?, ?, ?, ?)";

        // Подключиться к БД
        if( !dbconn.isOpen() )
        {
            dbconnect();
            if( !dbconn.isOpen() )
            {
                QMessageBox::critical(this,"Error","Cannot connect to Database!");
                return;
            }
        }
        QSqlQuery query(dbconn);
        // Подготовить запрос
        query.prepare(sqlstr);
        // Передать параметры из полей ввода в запрос
        query.bindValue(0,ui->leFam->text());
        query.bindValue(1,ui->lename->text());
        query.bindValue(2,ui->lePat->text());
        query.bindValue(3,ui->leBir->text());
        // Выполнить запрос
        if( !query.exec() )
        {
            ui->teResult->append( query.lastQuery());
            QMessageBox::critical(this,"Error",query.lastError().text());
            return;
        }
        // Если запрос выполнен, то вывести сообщение об добавлении строки
        ui->teResult->append( QString("AddRead %1 rows").arg(query.numRowsAffected()) );
        // и обновить записи в компоненте таблицы
        selectAll();
    }else{
        // Если поле ввода date_of_death не пустое - выполнить обычный запрос
        // Подключиться к БД
        if( !dbconn.isOpen() )
        {
            dbconnect();
            if( !dbconn.isOpen() )
            {
                QMessageBox::critical(this,"Error","Cannot connect to Database!");
                return;
            }
        }
        QSqlQuery query(dbconn);
        // Создать строку запроса
        QString sqlstr = "insert into author(family, name, patronymic, birth_date,death_date) values(?,?,?,?,?)";
        // Подготовить запрос
        query.prepare(sqlstr);
        // Передать параметры из полей ввода в запрос
        query.bindValue(0,ui->leFam->text());
        query.bindValue(1,ui->lename->text());
        query.bindValue(2,ui->lePat->text());
        query.bindValue(3,ui->leBir->text());
        query.bindValue(4,ui->leDea->text());
        // Выполнить запрос
        if( !query.exec() )
        {
            ui->teResult->append( query.lastQuery());
            QMessageBox::critical(this,"Error",query.lastError().text());
            return;
        }
        // Если запрос выполнен, то вывести сообщение об добавлении строки
        ui->teResult->append( QString("AddRead %1 rows").arg(query.numRowsAffected()) );
        // и обновить записи в компоненте таблицы
        selectAll();
    }
}


//void employees::del()
//{
//// Подключение к БД
//if( !dbconn.isOpen() )
//{
//dbconnect();
//if( !dbconn.isOpen() )
//{
//QMessageBox::critical(this,"Error","Cannot connect to Database!");
//return;
//}
//}
//// Получить номер выбранной строки в компоненте таблицы
//int currow = ui->twemployees->currentRow();
//// Если он меньше 0 (строка не выбрана), то
//// сообщение об ошибке и выход из функции
//if( currow < 0 )
//{
//QMessageBox::critical(this,"Error","Not selected row!");
//return;
//}
//// Спросить у пользователя подтверждение удаления записи
//// Используется статический метод QMessageBox::question
//// для задания вопроса, который возвращает код нажатой кнопки

//if( QMessageBox::question(this,"Delete","Delete row?",
//QMessageBox::Cancel,QMessageBox::Ok)==QMessageBox::Cancel)
//return;
//// Создать объект запроса
//QSqlQuery query(dbconn);
//// Создать строку запроса.
//// Вместо подготовки запроса и передачи параметров значение параметра
//// конкатенируется со строкой запроса
//// Обратите,что строковое значение помещается в одинарные кавычки
//// Значение выбирается из компонента таблицы методом item(row,col)
//QString sqlstr = "delete from author where id = '"
//+ ui->twemployees->item(currow,5)->text() + "'";
//// Выполнить строку запроса и проверить его успешность
//if( !query.exec(sqlstr) )
//{
//ui->teResult->append( query.lastQuery());
//QMessageBox::critical(this,"Error",query.lastError().text());
//return;
//}
//// Вывести сообщение об удалении строки
//ui->teResult->append( QString("Del %1 rows").arg(query.numRowsAffected()) );
//// Обновить содержимое компонента таблицы
//selectAll();
//}

void employees::del()
{
    // Подключение к БД
    if (!dbconn.isOpen()) {
        dbconnect();
        if (!dbconn.isOpen()) {
            QMessageBox::critical(this, "Error", "Cannot connect to Database!");
            return;
        }
    }

    // Получить номер выбранной строки в компоненте таблицы
    int currow = ui->twemployees->currentRow();
    // Если он меньше 0 (строка не выбрана), то сообщение об ошибке и выход из функции
    if (currow < 0) {
        QMessageBox::critical(this, "Error", "Not selected row!");
        return;
    }

    // Спросить у пользователя подтверждение удаления записи
    if (QMessageBox::question(this, "Delete", "Delete row?", QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Cancel) {
        return;
    }

    // Создать объект запроса
    QSqlQuery query(dbconn);
    // Создать строку запроса
    QString sqlstr = "delete from author where id = '" + ui->twemployees->item(currow, 5)->text() + "'";

    // Выполнить строку запроса и проверить его успешность
    if (!query.exec(sqlstr)) {
        ui->teResult->append(query.lastQuery());
        auto errorText = query.lastError().text();

        if (errorText.contains("23503")) {
            // SQL error code 23503 corresponds to foreign key violation
            QMessageBox::critical(this, "Error", "Невозможно удалить автора, он занят братуха, он читает книгу уделайй его книгу потом побрупой.");
        } else {
            QMessageBox::critical(this, "Error", errorText);
        }
        return;
    }

    // Вывести сообщение об удалении строки
    ui->teResult->append(QString("Deleted %1 rows").arg(query.numRowsAffected()));
    // Обновить содержимое компонента таблицы
    selectAll();
}



void employees::edit()
{

    if( ui->leFam->text().isEmpty() || ui->lename->text().isEmpty()
         || ui->leBir->text().isEmpty())
    {
        QMessageBox::critical(this,"Error","Some  fields are empty!");
        return;
    }

    if(ui->leDea->text().isEmpty()) {
    QDate date = QDate::fromString(ui->leBir->text(),"yyyy-MM-dd");
    if(!date.isValid())
    {
        QMessageBox::critical(this,"Error","Invalid date format!");
        return;
    }
    } else {
        QDate date = QDate::fromString(ui->leBir->text(),"yyyy-MM-dd");
        QDate date1 = QDate::fromString(ui->leDea->text(),"yyyy-MM-dd");
        if(!date.isValid() || !date1.isValid())
        {
            QMessageBox::critical(this,"Error","Invalid date format!");
            return;
        }
    }
    if( !dbconn.isOpen() )
    {
        dbconnect();
        if( !dbconn.isOpen() )
        {
            QMessageBox::critical(this,"Error","Cannot connect to Database!");
            return;
        }
    }
    int currow = ui->twemployees->currentRow();
    if( currow < 0 )
    {
        QMessageBox::critical(this,"Error","Not selected row!");
        return;
    }
    if( QMessageBox::question(this,"Edit","Edit row?",QMessageBox::Cancel,QMessageBox::Ok)==QMessageBox::Cancel)
        return;
    QSqlQuery query(dbconn);
    QString sqlstr = "update author set ";
    QString updatestr = "";

    if(!ui->leFam->text().isEmpty())
        updatestr += "family = '" + ui->leFam->text() + "',";

    if(!ui->lename->text().isEmpty())
        updatestr += "name = '" + ui->lename->text() + "',";

    if(!ui->lePat->text().isEmpty())
        updatestr += "patronymic = '" + ui->lePat->text() + "',";
    if(ui->lePat->text().isEmpty())
        updatestr += "patronymic = '',";

    if(!ui->leBir->text().isEmpty())
        updatestr += "birth_date = '" + ui->leBir->text() + "',";

    if(!ui->leDea->text().isEmpty())
        updatestr += "death_date = '" + ui->leDea->text() + "',";

    sqlstr += updatestr.left(updatestr.length() - 1) + " where id = '" + ui->twemployees->item(currow,5)->text() + "'";
    query.prepare(sqlstr);

    // Привязать значения к параметрам запроса
    if(!ui->leFam->text().isEmpty())
        query.bindValue(":family", ui->leFam->text());

    if(!ui->lename->text().isEmpty())
        query.bindValue(":name", ui->lename->text());

    if(!ui->lePat->text().isEmpty())
        query.bindValue(":patronymic", ui->lePat->text());

    if(!ui->leBir->text().isEmpty())
        query.bindValue(":birth_date", ui->leBir->text());

    if(!ui->leDea->text().isEmpty())
        query.bindValue(":death_date", ui->leDea->text());

    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }

    ui->teResult->append( QString("AddRead %1rows").arg(query.numRowsAffected()) );

    selectAll();
}

void employees::selectAll()
{
// Очистить содержимое компонента
//ui->twemployees->clearContents();
// Если соединение не открыто, то вызвать нашу функцию для открытия
// если подключиться не удалось, то вывести сообщение об ошибке и
// выйти из функции
if( !dbconn.isOpen() )
{
dbconnect();
if( !dbconn.isOpen() )
{
QMessageBox::critical(this,"Error","Cannot connect to Database!");
return;
}
}
// Создать объект запроса с привязкой к установленному соединению
QSqlQuery query(dbconn);
// Создать строку запроса на выборку данных
QString sqlstr = "select * from author";
// Выполнить запрос и поверить его успешность
if( !query.exec(sqlstr) )
{
QMessageBox::critical(this,"Error", "Query unsuccesful. Check your data and try again!");
return;
}
// Если запрос активен (успешно завершен),
// то вывести сообщение о прочитанном количестве строк в окно вывода
// и установить количество строк для компонента таблицы
if( query.isActive())
ui->twemployees->setRowCount( query.size());
else
ui->twemployees->setRowCount( 0);
ui->teResult->append( QString("Read %1 rows").arg(query.size()));
// Прочитать в цикле все строки результата (курсора)
// и вывести их в компонент таблицы
int i=0;
//surname, names, patronymic, date_of_birth,date_of_death)
while(query.next())
{
ui->twemployees->setItem(i,0,new
QTableWidgetItem(query.value("family").toString()));
ui->twemployees->setItem(i,1,new
QTableWidgetItem(query.value("name").toString()));
ui->twemployees->setItem(i,2,new
QTableWidgetItem(query.value("patronymic").toString()));
ui->twemployees->setItem(i,3,new
QTableWidgetItem(query.value("birth_date").toString()));
ui->twemployees->setItem(i,4,new
QTableWidgetItem(query.value("death_date").toString()));
ui->twemployees->setItem(i,5,new
QTableWidgetItem(query.value("id").toString()));
i++;
}
}

void employees::on_btnMenu_clicked()
{
    this->close();
    adminmenu *amenu = new adminmenu(this);
    amenu->show();
}

void employees::search()
{

    if( ui->leSearch->text().isEmpty() )
    {
        QMessageBox::critical(this,"Error","Search field is empty!");
        return;
    }
    // Подключение к БД
    if( !dbconn.isOpen() )
    {
    dbconnect();
    if( !dbconn.isOpen() )
    {
    QMessageBox::critical(this,"Error","Cannot connect to Database!");
    return;
    }
    }
    QSqlQuery query(dbconn);
    // Создать строку запроса
    QString sqlstr = "select * from author where family LIKE '%' || ? || '%'";
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
    ui->twemployees->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->twemployees->setItem(i,0,new
        QTableWidgetItem(query.value("family").toString()));
        ui->twemployees->setItem(i,1,new
        QTableWidgetItem(query.value("name").toString()));
        ui->twemployees->setItem(i,2,new
        QTableWidgetItem(query.value("patronymic").toString()));
        ui->twemployees->setItem(i,3,new
        QTableWidgetItem(query.value("birth_date").toString()));
        ui->twemployees->setItem(i,4,new
        QTableWidgetItem(query.value("death_date").toString()));
        ui->twemployees->setItem(i,5,new
        QTableWidgetItem(query.value("id").toString()));
        i++;
    }
    ui->teResult->append( QString("Поиск выполнен успешно").arg(query.numRowsAffected()) );
}

void employees::on_btnEdit1_clicked()
{
    int currow = ui->twemployees->currentRow();

    // Если он меньше 0 (строка не выбрана), то
    // сообщение об ошибке и выход из функции
    if( currow < 0 )
    {
        QMessageBox::critical(this,"Error","Not selected row!");
        return;
    }
            ui->leFam->setText(ui->twemployees->item(ui->twemployees->currentRow(),0)->text());
            ui->lename->setText(ui->twemployees->item(ui->twemployees->currentRow(),1)->text());
            ui->lePat->setText(ui->twemployees->item(ui->twemployees->currentRow(),2)->text());
            ui->leBir->setText(ui->twemployees->item(ui->twemployees->currentRow(),3)->text());
            ui->leDea->setText(ui->twemployees->item(ui->twemployees->currentRow(),4)->text());
}




void employees::filterByBirthDate()
{
    if (!dbconn.isOpen()) {
        dbconnect();
        if (!dbconn.isOpen()) {
            QMessageBox::critical(this, "Error", "Cannot connect to Database!");
            return;
        }
    }

    QSqlQuery query(dbconn);
    QString sqlstr = "SELECT family, name, patronymic, birth_date, death_date, id FROM author ORDER BY birth_date";
    query.prepare(sqlstr);

    if (!query.exec()) {
        ui->teResult->append(query.lastQuery());
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    ui->twemployees->setRowCount(query.size());

    int row = 0;
    while (query.next()) {
        ui->twemployees->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->twemployees->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->twemployees->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->twemployees->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->twemployees->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->twemployees->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        ++row;
    }

    if (row == 0) {
        // Inform the user if no records match the filter criteria
        QMessageBox::information(this, "No Results", "No records match the specified date range.");
    }
}

void employees::filterByBirthAndDeathDates()
{
    if (!dbconn.isOpen()) {
            dbconnect();
            if (!dbconn.isOpen()) {
                QMessageBox::critical(this, "Error", "Cannot connect to Database!");
                return;
            }
        }

        QSqlQuery query(dbconn);
        QString sqlstr = "SELECT family, name, patronymic, birth_date, death_date, id FROM author ORDER BY death_date";

        query.prepare(sqlstr);

        if (!query.exec()) {
            ui->teResult->append(query.lastQuery());
            QMessageBox::critical(this, "Error", query.lastError().text());
            return;
        }

        ui->twemployees->setRowCount(query.size());

        int row = 0;
        while (query.next()) {
            ui->twemployees->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->twemployees->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->twemployees->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->twemployees->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->twemployees->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->twemployees->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
            ++row;
        }

        if (row == 0) {
            // Inform the user if no records match the filter criteria
            QMessageBox::information(this, "No Results", "No records match the specified date ranges.");
        }

}




