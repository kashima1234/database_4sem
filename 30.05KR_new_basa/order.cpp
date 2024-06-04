#include "order.h"
#include "ui_order.h"
#include "usermenu.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
order::order(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
      connect(ui->btnSelectAll,SIGNAL(clicked(bool)),this, SLOT(selectAll()));
      connect(ui->btnOrder,SIGNAL(clicked(bool)),this, SLOT(add()));
      // Количество столбцов
      ui->twp->setColumnCount(5);
      // Возможность прокрутки
      ui->twp->setAutoScroll(true);
      // Режим выделения ячеек - только одна строка
      ui->twp->setSelectionMode(QAbstractItemView::SingleSelection);
      ui->twp->setSelectionBehavior(QAbstractItemView::SelectRows);
      // Заголовки таблицы
      ui->twp->setHorizontalHeaderItem(0,new QTableWidgetItem("Имя абонента"));
      ui->twp->setHorizontalHeaderItem(1,new QTableWidgetItem("Имя книги"));
      ui->twp->setHorizontalHeaderItem(2,new QTableWidgetItem("Дата взятия"));
       ui->twp->setHorizontalHeaderItem(3,new QTableWidgetItem("Дата возврата"));
       ui->twp->setHorizontalHeaderItem(4,new QTableWidgetItem("ID записи"));
      // Последний столбец растягивается при изменении размера формы
      ui->twp->horizontalHeader()->setStretchLastSection(true);
      // Разрешаем сортировку пользователю
      ui->twp->setSortingEnabled(false);
      //ui->twp->QTableView::sortByColumn(0);
      // Запрет на изменение ячеек таблицы при отображении
      ui->twp->setEditTriggers(QAbstractItemView::NoEditTriggers);

    }

order::~order()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}


void order::dbconnect()
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
}
}
else
// Если соединение уже открыто, то сообщить об этом
ui->teResult->append("Connect is already open...");
}

void order::selectAll()
{
// Очистить содержимое компонента
//ui->twp->clearContents();
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
QString sqlstr = "select abonent.name, book.title, record.taken_date, record.return_date, record.id from record join abonent on abonent.id = record.abonent_id join book on book.id = record.book_id";
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
ui->twp->setRowCount( query.size());
else
ui->twp->setRowCount( 0);
ui->teResult->append( QString("Read %1 rows").arg(query.size()));
// Прочитать в цикле все строки результата (курсора)
// и вывести их в компонент таблицы
int i=0;
while(query.next())
{
    ui->twp->setItem(i,0,new
    QTableWidgetItem(query.value(0).toString()));
    ui->twp->setItem(i,1,new
    QTableWidgetItem(query.value(1).toString()));
    ui->twp->setItem(i,2,new
    QTableWidgetItem(query.value(2).toString()));
    ui->twp->setItem(i,3,new
    QTableWidgetItem(query.value(3).toString()));
    ui->twp->setItem(i,4,new
    QTableWidgetItem(query.value(4).toString()));
i++;
}
}

void order::on_btnMenu_clicked()
{
    this->close();
    usermenu *amenu = new usermenu(this);
    amenu->show();
}


void order::add()
{
    if (!dbconn.isOpen()) {
        dbconnect();
        if (!dbconn.isOpen()) {
            QMessageBox::critical(this, "Error", dbconn.lastError().text());
            return;
        }
    }

    if(ui->leRet->text().isEmpty()) {
    QDate date = QDate::fromString(ui->leTak->text(),"yyyy-MM-dd");
    if(!date.isValid())
    {
        QMessageBox::critical(this,"Error","Invalid date format!");
        return;
    }
    } else {
        QDate date = QDate::fromString(ui->leTak->text(),"yyyy-MM-dd");
        QDate date1 = QDate::fromString(ui->leRet->text(),"yyyy-MM-dd");
        if(!date.isValid() || !date1.isValid())
        {
            QMessageBox::critical(this,"Error","Invalid date format!");
            return;
        }
    }
    QString bookId = ui->leBo->text();
    QSqlQuery checkQuery(dbconn);
    checkQuery.prepare("SELECT count FROM book WHERE id = ?");
    checkQuery.bindValue(0, bookId);
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Error", checkQuery.lastError().text());
        return;
    }
    if (!checkQuery.first()) {
        QMessageBox::critical(this, "Error", "Книга не найдена.");
        return;
    }
    int bookCount = checkQuery.value(0).toInt();
    if (bookCount <= 0) {
        QMessageBox::critical(this, "Error", "Книги нет в наличии.");
        return;
    }

    QString returnDate = ui->leRet->text();
    QSqlQuery updateQuery(dbconn);
    if (returnDate.isEmpty()) {
        updateQuery.prepare("INSERT INTO record(abonent_id, book_id, taken_date) VALUES (?, ?, ?)");
        updateQuery.bindValue(0, ui->leAb->text());
        updateQuery.bindValue(1, bookId);
        updateQuery.bindValue(2, ui->leTak->text());
    } else {
        updateQuery.prepare("INSERT INTO record(abonent_id, book_id, taken_date, return_date) VALUES (?, ?, ?, ?)");
        updateQuery.bindValue(0, ui->leAb->text());
        updateQuery.bindValue(1, bookId);
        updateQuery.bindValue(2, ui->leTak->text());
        updateQuery.bindValue(3, returnDate);
    }
    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "Error", "Не удалось сделать запись. Проверьте корректность заполнения данных");
        return;
    }
    QMessageBox::question(this, "Запись", "Запись сделана!", QMessageBox::Ok);
    ui->teResult->append(QString("AddRead %1 rows").arg(updateQuery.numRowsAffected()));
    selectAll();

    // Decrease book count
    QSqlQuery decreaseQuery(dbconn);
    decreaseQuery.prepare("UPDATE book SET count = ? WHERE id = ?");
    decreaseQuery.bindValue(0, bookCount - 1);
    decreaseQuery.bindValue(1, bookId);
    if (!decreaseQuery.exec()) {
        QMessageBox::warning(this, "Warning", "База данных не доступна");
    }
}


void order::on_btnEdit_1_clicked()
{
    int currow = ui->twp->currentRow();

    // Если он меньше 0 (строка не выбрана), то
    // сообщение об ошибке и выход из функции
    if( currow < 0 )
    {
        QMessageBox::critical(this,"Error","Not selected row!");
        return;
    }
            ui->leAb->setText(ui->twp->item(ui->twp->currentRow(),0)->text());
            ui->leBo->setText(ui->twp->item(ui->twp->currentRow(),1)->text());
            ui->leTak->setText(ui->twp->item(ui->twp->currentRow(),2)->text());
            ui->leRet->setText(ui->twp->item(ui->twp->currentRow(),3)->text());

}


void order::on_btnEdit_clicked()
{

    if(ui->leRet->text().isEmpty()) {
    QDate date = QDate::fromString(ui->leTak->text(),"yyyy-MM-dd");
    if(!date.isValid())
    {
        QMessageBox::critical(this,"Error","Invalid date format!");
        return;
    }
    } else {
        QDate date = QDate::fromString(ui->leTak->text(),"yyyy-MM-dd");
        QDate date1 = QDate::fromString(ui->leRet->text(),"yyyy-MM-dd");
        if(!date.isValid() || !date1.isValid())
        {
            QMessageBox::critical(this,"Error","Invalid date format!");
            return;
        }
    }
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
    int currow = ui->twp->currentRow();
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
    //insert into record(id_abonent,id_book, date_of_taken_book, date_of_return_book) values(?,?,?,?)
    QString sqlstr = "update record set abonent_id= ?, book_id = ?, taken_date = ?, return_date = ? where id = '" + ui->twp->item(currow,4)->text() + "'";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leAb->text());
    query.bindValue(1,ui->leBo->text());
    query.bindValue(2,ui->leTak->text());
    query.bindValue(3,ui->leRet->text());
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error","Не удалось изменить запись. Проверьте корректность заполнения данных");
        return;
    }
    // Если запрос выполнен, то вывести сообщение одобавлении строки

    ui->teResult->append( QString("AddRead %1rows").arg(query.numRowsAffected()) );
    // и обновить записи в компоненте таблицы
    selectAll();
}

//void order::o
void order::on_recordFilterBtn_clicked()
{
    auto abonentName = ui->abonentName->text();
    auto bookName = ui->bookName->text();

    if (abonentName.isEmpty() && bookName.isEmpty()) {
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
    QString sqlstr = "select abonent.name, book.title, record.taken_date, record.return_date, record.id from record join abonent on abonent.id = record.abonent_id join book on book.id = record.book_id where ";
    bool isAbonentEmpty = true;
    if (!abonentName.isEmpty()) {
        sqlstr += "abonent.name ilike '%" + abonentName + "%' ";
        isAbonentEmpty = false;
    }

    if (!bookName.isEmpty()) {
        if (!isAbonentEmpty) {
            sqlstr += "and ";
        }
        sqlstr += "book.title ilike '%" + bookName + "%' ";
    }
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
    ui->twp->setRowCount( query.size());
    else
    ui->twp->setRowCount( 0);
    ui->teResult->append( QString("Read %1 rows").arg(query.size()));
    // Прочитать в цикле все строки результата (курсора)
    // и вывести их в компонент таблицы
    int i=0;
    while(query.next())
    {
        ui->twp->setItem(i,0,new
        QTableWidgetItem(query.value(0).toString()));
        ui->twp->setItem(i,1,new
        QTableWidgetItem(query.value(1).toString()));
        ui->twp->setItem(i,2,new
        QTableWidgetItem(query.value(2).toString()));
        ui->twp->setItem(i,3,new
        QTableWidgetItem(query.value(3).toString()));
        ui->twp->setItem(i,4,new
        QTableWidgetItem(query.value(4).toString()));
    i++;
    }
}
