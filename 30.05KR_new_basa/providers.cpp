#include "providers.h"
#include "ui_providers.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QStringList>
#include "adminmenu.h"
#include <QDebug>

providers::providers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::providers)
{
  ui->setupUi(this);
  connect(ui->btnSelectAll,SIGNAL(clicked(bool)),this, SLOT(selectAll()));
  connect(ui->btnSelectAll_2,SIGNAL(clicked(bool)),this, SLOT(selectAll1()));
  connect(ui->btnAdd,SIGNAL(clicked(bool)),this, SLOT(add()));
  connect(ui->btnAdd_3,SIGNAL(clicked(bool)),this, SLOT(add1()));
  connect(ui->btnDel,SIGNAL(clicked(bool)),this, SLOT(del()));
    connect(ui->btnDel_3,SIGNAL(clicked(bool)),this, SLOT(del1()));
  connect(ui->btnEdit,SIGNAL(clicked(bool)),this, SLOT(edit()));
  connect(ui->btnEdit_3,SIGNAL(clicked(bool)),this, SLOT(edit1()));
  // Количество столбцов
  ui->twp->setColumnCount(5);
  ui->twp_2->setColumnCount(2);
  // Возможность прокрутки
  ui->twp->setAutoScroll(true);
  ui->twp_2->setAutoScroll(true);
  // Режим выделения ячеек - только одна строка
  ui->twp->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->twp->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->twp_2->setSelectionMode(QAbstractItemView::SingleSelection);
  ui->twp_2->setSelectionBehavior(QAbstractItemView::SelectRows);
  // Заголовки таблицы
  ui->twp->setHorizontalHeaderItem(0,new QTableWidgetItem("Название"));
  ui->twp->setHorizontalHeaderItem(1,new QTableWidgetItem("Год публикации"));
  ui->twp->setHorizontalHeaderItem(2,new QTableWidgetItem("Количество"));
  ui->twp->setHorizontalHeaderItem(3,new QTableWidgetItem("Айди издательства"));
  ui->twp->setHorizontalHeaderItem(4,new QTableWidgetItem("Автор"));
//  ui->twp->setHorizontalHeaderItem(4,new QTableWidgetItem("Айди книги"));
  ui->twp_2->setHorizontalHeaderItem(0,new QTableWidgetItem("Название категории"));
  ui->twp_2->setHorizontalHeaderItem(1,new QTableWidgetItem("Описание"));

  // Последний столбец растягивается при изменении размера формы
  ui->twp->horizontalHeader()->setStretchLastSection(true);
    ui->twp_2->horizontalHeader()->setStretchLastSection(true);
  // Разрешаем сортировку пользователю
  ui->twp->setSortingEnabled(false);
  ui->twp_2->setSortingEnabled(false);
  //ui->twp->QTableView::sortByColumn(0);
  // Запрет на изменение ячеек таблицы при отображении
  ui->twp->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->twp_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

  this->loadAuthros();

}


providers::~providers()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}

void providers::dbconnect()
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


void providers::Clearr()
{
 ui->twp->clearContents();
}


//void providers::selectAll()
//{
//// Очистить содержимое компонента
////ui->twp->clearContents();
//// Если соединение не открыто, то вызвать нашу функцию для открытия
//// если подключиться не удалось, то вывести сообщение об ошибке и
//// выйти из функции
//if( !dbconn.isOpen() )
//{
//dbconnect();
//if( !dbconn.isOpen() )
//{
//QMessageBox::critical(this,"Error",dbconn.lastError().text());
//return;
//}
//}
//// Создать объект запроса с привязкой к установленному соединению
//QSqlQuery query(dbconn);
//// Создать строку запроса на выборку данных
//QString sqlstr = "SELECT book.title, book.publish_year, book.count, publish.title, concat(author.family, ' ', author.name) as author_fullname from book join publish  on publish.id = book.publish_id join authorship on authorship.book_id = book.id join author on author.id = authorship.author_id";

////QString sqlstr = "SELECT book.title, book.publish_year, book.count, publish.title, concat(author.family, ' ', author.name) from book join publish  on publish.id = book.publish_id join authorship on authorship.book_id = book_id join author on author.id = authorship.author_id";


//// Выполнить запрос и поверить его успешность
//if( !query.exec(sqlstr) )
//{
//QMessageBox::critical(this,"Error", query.lastError().text());
//return;
//}
//// Если запрос активен (успешно завершен),
//// то вывести сообщение о прочитанном количестве строк в окно вывода
//// и установить количество строк для компонента таблицы
//if( query.isActive())
//ui->twp->setRowCount( query.size());
//else
//ui->twp->setRowCount( 0);
//ui->teResult->append( QString("Read %1 rows").arg(query.size()));
//// Прочитать в цикле все строки результата (курсора)
//// и вывести их в компонент таблицы
//int i=0;
//while(query.next())
//{
//ui->twp->setItem(i,0,new
//QTableWidgetItem(query.value(0).toString()));
//ui->twp->setItem(i,1,new
//QTableWidgetItem(query.value(1).toString()));
//ui->twp->setItem(i,2,new
//QTableWidgetItem(query.value(2).toString()));
//ui->twp->setItem(i,3,new
//QTableWidgetItem(query.value(3).toString()));
//ui->twp->setItem(i,4,new
//QTableWidgetItem(query.value(4).toString()));
////ui->twp->setItem(i,4,new
////QTableWidgetItem(query.value("id").toString()));

//i++;
//}

//}

//selectalls


void providers::selectAll()
{
    if (!dbconn.isOpen())
    {
        dbconnect();
        if (!dbconn.isOpen())
        {
            QMessageBox::critical(this, "Error", dbconn.lastError().text());
            return;
        }
    }

    QSqlQuery query(dbconn);
    QString sqlstr = "SELECT book.id, book.title, book.publish_year, book.count, publish.title, concat(author.family, ' ', author.name) as author_fullname "
                     "from book join publish on publish.id = book.publish_id "
                     "join authorship on authorship.book_id = book.id "
                     "join author on author.id = authorship.author_id";

    if (!query.exec(sqlstr))
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    if (query.isActive())
        ui->twp->setRowCount(query.size());
    else
        ui->twp->setRowCount(0);

    ui->teResult->append(QString("Read %1 rows").arg(query.size()));

    int i = 0;
    while (query.next())
    {
        ui->twp->setItem(i, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->twp->setItem(i, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->twp->setItem(i, 2, new QTableWidgetItem(query.value(3).toString()));
        ui->twp->setItem(i, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->twp->setItem(i, 4, new QTableWidgetItem(query.value(5).toString()));

        // Store the id in the last column but keep it hidden
        ui->twp->setItem(i, 5, new QTableWidgetItem(query.value(0).toString()));
        ui->twp->setColumnHidden(5, true);

        i++;
    }
}




//void providers::add()
//{
// Подключиться к БД
//if( !dbconn.isOpen() )
//{
//dbconnect();
//if( !dbconn.isOpen() )
//{
//QMessageBox::critical(this,"Error",dbconn.lastError().text());
//return;
//}
//}
//QSqlQuery query(dbconn);
// Создать строку запроса
// "insert into author(surname, names, patronymic, date_of_birth,date_of_death) values(?,?,?,?,?)";
//QString sqlstr = "insert into book(title,publish_year,count,publish_id) values(?,?,?,?)";
// Подготовить запрос
//query.prepare(sqlstr);
// Передать параметры из полей ввода в запрос
//query.bindValue(0,ui->leTit->text());
//query.bindValue(1,ui->leYea->text());
//query.bindValue(2,ui->leCou->text());
//query.bindValue(3,ui->lePublishing->text());
// Выполнить запрос
//if( !query.exec() )
//{
//ui->teResult->append( query.lastQuery());
//QMessageBox::critical(this,"Error",query.lastError().text());
//return;
//}
//e// Если запрос выполнен, то вывести сообщение одобавлении строки
//ui->teResult->append( QString("AddRead %1 rows").arg(query.numRowsAffected()) );
// и обновить записи в компоненте таблицы
//selectAll();
//}

//ee/////////////////

//void providers::add()
//{
//    // Подключиться к БД
//    if( !dbconn.isOpen() )
//    {
//        dbconnect();
//        if( !dbconn.isOpen() )
//        {
//            QMessageBox::critical(this,"Error",dbconn.lastError().text());
//            return;
//        }
//    }

//    QString title = ui->leTit->text();
//    QString publishYearStr = ui->leYea->text();
//    QString countStr = ui->leCou->text();
//    QString publishId = ui->lePublishing->text();

//    // Validate the publish year to ensure it is not negative
//    bool ok;
//    int publishYear = publishYearStr.toInt(&ok);
//    if (!ok || publishYear < 0) {
//        QMessageBox::critical(this, "Error", "Год публикации должен быть неотрицательным целым числом. .");
//        return;
//    }

//    // Validate count to ensure it is not negative or non-numeric
//    int count = countStr.toInt(&ok);
//    if (!ok || count < 0) {
//        QMessageBox::critical(this, "Error", "Количество должно быть неотрицательным целым числом..");
//        return;
//    }

//    if (dbconn.transaction()) {
//        QSqlQuery query(dbconn);
//        // Создать строку запроса
//        QString sqlstr = "insert into book(title, publish_year, count, publish_id) values(?, ?, ?, ?) RETURNING id";
//        // Подготовить запрос
//        query.prepare(sqlstr);
//        // Передать параметры из полей ввода в запрос
//        query.bindValue(0, title);
//        query.bindValue(1, publishYear);
//        query.bindValue(2, count);
//        query.bindValue(3, publishId);

//        // Выполнить запрос
//        if( !query.exec() )
//        {
//            ui->teResult->append(query.lastQuery());
//            QMessageBox::critical(this,"Error",query.lastError().text());
//            dbconn.rollback();
//            return;
//        }
//        QString bookId = query.value(0).toString();

//        QStringList familyName = ui->authors->currentText().split(" ");
//        sqlstr = "select id from author where family=? and name=?";
//        query.prepare(sqlstr);
//        query.bindValue(0, familyName.at(0));
//        query.bindValue(1, familyName.at(1));
//        if( !query.exec() )
//        {
//            ui->teResult->append(query.lastQuery());
//            QMessageBox::critical(this,"Error",query.lastError().text());
//            dbconn.rollback();
//            return;
//        }
//        QString authorId = query.value(0).toString();
//        sqlstr = "insert into authorship(book_id, author_id) values(?,?)";
//        query.prepare(sqlstr);
//        query.bindValue(0, bookId);
//        query.bindValue(1, authorId);
//        if( !query.exec() )
//        {
//            ui->teResult->append(query.lastQuery());
//            QMessageBox::critical(this,"Error",query.lastError().text());
//            dbconn.rollback();
//            return;
//        }
//        // Если запрос выполнен, то вывести сообщение о добавлении строки
//        ui->teResult->append(QString("Added %1 row(s)").arg(query.numRowsAffected()));
//        if (dbconn.commit())
//            QMessageBox::critical(this,"Error", "error on commiting transaction");

//        // и обновить записи в компоненте таблицы
//        selectAll();
//    } else {
//        QMessageBox::critical(this,"Error", "");
//    }
//}



void providers::add()
{
    // Connect to the database
    if (!dbconn.isOpen()) {
        dbconnect();
        if (!dbconn.isOpen()) {
            QMessageBox::critical(this, "Error", dbconn.lastError().text());
            return;
        }
    }

    QString title = ui->leTit->text();
    QString publishYearStr = ui->leYea->text();
    QString countStr = ui->leCou->text();
    QString publishId = ui->lePublishing->text();

    // Validate the publish year to ensure it is not negative
    bool ok;
    int publishYear = publishYearStr.toInt(&ok);
    if (!ok || publishYear < 0) {
        QMessageBox::critical(this, "Error", "Год публикации должен быть неотрицательным целым числом.");
        return;
    }

    // Validate count to ensure it is not negative or non-numeric
    int count = countStr.toInt(&ok);
    if (!ok || count < 0) {
        QMessageBox::critical(this, "Error", "Количество должно быть неотрицательным целым числом.");
        return;
    }

    if (dbconn.transaction()) {
        QSqlQuery query(dbconn);
        // Create query string
        QString sqlstr = "INSERT INTO book(title, publish_year, count, publish_id) VALUES(?, ?, ?, ?) RETURNING id";
        // Prepare query
        query.prepare(sqlstr);
        // Bind values from input fields to the query
        query.bindValue(0, title);
        query.bindValue(1, publishYear);
        query.bindValue(2, count);
        query.bindValue(3, publishId);

        // Execute query
        if (!query.exec()) {
            ui->teResult->append(query.lastQuery());
            QMessageBox::critical(this, "Error", query.lastError().text());
            dbconn.rollback();
            return;
        }

        // Fetch the returned book ID
        QString bookId;
        if (query.next()) {
            bookId = query.value(0).toString();
        } else {
            QMessageBox::critical(this, "Error", "Failed to retrieve the book ID.");
            dbconn.rollback();
            return;
        }

        // Split family and given names
        QStringList familyName = ui->authors->currentText().split(" ");
        if (familyName.size() < 2) {
            QMessageBox::critical(this, "Error", "Invalid author name format.");
            dbconn.rollback();
            return;
        }

        sqlstr = "SELECT id FROM author WHERE family=? AND name=?";
        query.prepare(sqlstr);
        query.bindValue(0, familyName.at(0));
        query.bindValue(1, familyName.at(1));
        if (!query.exec() || !query.next()) {
            ui->teResult->append(query.lastQuery());
            QMessageBox::critical(this, "Error", query.lastError().text());
            dbconn.rollback();
            return;
        }

        QString authorId = query.value(0).toString();
        sqlstr = "INSERT INTO authorship(book_id, author_id) VALUES(?, ?)";
        query.prepare(sqlstr);
        query.bindValue(0, bookId);
        query.bindValue(1, authorId);
        if (!query.exec()) {
            ui->teResult->append(query.lastQuery());
            QMessageBox::critical(this, "Error", query.lastError().text());
            dbconn.rollback();
            return;
        }

        // If the query is successful, display a message about the added row
        ui->teResult->append(QString("Added %1 row(s)").arg(query.numRowsAffected()));
        dbconn.commit();

        // Update records in the table component
        selectAll();
    } else {
        QMessageBox::critical(this, "Error", "Transaction failed to start.");
    }
}



//ee/////////////////
//void providers::edit()
//{
//// Подключение к БД
//if( !dbconn.isOpen() )
//{
//dbconnect();
//if( !dbconn.isOpen() )
//{
//QMessageBox::critical(this,"Error",dbconn.lastError().text());
//return;
//}
//}
//// Получить номер выбранной строки в компоненте таблицы
//int currow = ui->twp->currentRow();
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

//if( QMessageBox::question(this,"Edit","Edit row?",
//QMessageBox::Cancel,QMessageBox::Ok)==QMessageBox::Cancel)
//return;
//// Создать объект запроса
//QSqlQuery query(dbconn);

//// Создать строку запроса.
//// Вместо подготовки запроса и передачи параметров значение параметра
//// конкатенируется со строкой запроса
//// Обратите,что строковое значение помещается в одинарные кавычки
//// Значение выбирается из компонента таблицы методом item(row,col)
//QString sqlstr = "update book set title = ?, publish_year = ?, count = ?, publish_id = ? where id = '" + ui->twp->item(currow, 4)->text() + "'";
//// Подготовить запрос
//query.prepare(sqlstr);
//// Передать параметры из полей ввода в запрос
//query.bindValue(0,ui->leTit->text());
//query.bindValue(1,ui->leYea->text());
//query.bindValue(2,ui->leCou->text());
//query.bindValue(3,ui->lePublishing->text());

//// Выполнить запрос
//if( !query.exec() )
//{
//ui->teResult->append( query.lastQuery());
//QMessageBox::critical(this,"Error",query.lastError().text());
//return;
//}
//// Если запрос выполнен, то вывести сообщение одобавлении строки
//ui->teResult->append( QString("AddRead %1rows").arg(query.numRowsAffected()) );
//// и обновить записи в компоненте таблицы
//selectAll();

//}


void providers::edit()
{
    // Check if the database connection is open
    if (!dbconn.isOpen()) {
        dbconnect();
        if (!dbconn.isOpen()) {
            QMessageBox::critical(this, "Error", dbconn.lastError().text());
            return;
        }
    }

    // Get the current selected row
    int currow = ui->twp->currentRow();

    // If no row is selected, show an error message and exit
    if (currow < 0) {
        QMessageBox::critical(this, "Error", "Not selected row!");
        return;
    }

    // Ask for confirmation before editing
    if (QMessageBox::question(this, "Edit", "Edit row?", QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Cancel) {
        return;
    }

    // Create the query object
    QSqlQuery query(dbconn);

    // Prepare the query string with placeholders
    QString sqlstr = "UPDATE book SET title = ?, publish_year = ?, count = ?, publish_id = ? WHERE id = ?";

    // Prepare the query
    query.prepare(sqlstr);

    // Bind the input values to the query
    query.bindValue(0, ui->leTit->text());
    query.bindValue(1, ui->leYea->text());
    query.bindValue(2, ui->leCou->text());
    query.bindValue(3, ui->lePublishing->text());
    query.bindValue(4, ui->twp->item(currow, 5)->text()); // Assuming id is in the 6th column

    // Execute the query and check for errors
    if (!query.exec()) {
        ui->teResult->append(query.lastQuery());
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    // Log the result and refresh the table
    ui->teResult->append(QString("Updated %1 rows").arg(query.numRowsAffected()));
    selectAll();
}



//d/////

//void providers::del()
//{
//    // Подключение к БД
//    if (!dbconn.isOpen())
//    {
//        dbconnect();
//        if (!dbconn.isOpen())
//        {
//            QMessageBox::critical(this, "Error", dbconn.lastError().text());
//            return;
//        }
//    }

//    // Получить номер выбранной строки в компоненте таблицы
//    int currow = ui->twp->currentRow();

//    // Если он меньше 0 (строка не выбрана), то сообщение об ошибке и выход из функции
//    if (currow < 0)
//    {
//        QMessageBox::critical(this, "Error", "Not selected row!");
//        return;
//    }

//    // Спросить у пользователя подтверждение удаления записи
//    if (QMessageBox::question(this, "Delete", "Delete row?", QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Cancel)
//        return;

//    // Создать объект запроса
//    QSqlQuery query(dbconn);

//    // Создать строку запроса
//    QString sqlstr = "delete from book where title = :title and publish_year = :publish_year and count = :count and id = :id";

//    // Подготовить запрос
//    query.prepare(sqlstr);

//    // Передать параметры из компонентов таблицы в запрос
//    query.bindValue(":title", ui->twp->item(currow, 0)->text());
//    query.bindValue(":publish_year", ui->twp->item(currow, 1)->text());
//    query.bindValue(":count", ui->twp->item(currow, 2)->text());

//    // Выполнить строку запроса и проверить его успешность
//    if (!query.exec())
//    {
//        ui->teResult->append(query.lastQuery());
//        QMessageBox::critical(this, "Error", query.lastError().text());
//        return;
//    }

//    // Вывести сообщение об удалении строки
//    ui->teResult->append(QString("Del %1 rows").arg(query.numRowsAffected()));

//    // Обновить содержимое компонента таблицы
//    selectAll();
//}

//dd

void providers::del()
{
    // Check if the database connection is open
    if (!dbconn.isOpen())
    {
        dbconnect();
        if (!dbconn.isOpen())
        {
            QMessageBox::critical(this, "Error", dbconn.lastError().text());
            return;
        }
    }

    // Get the current selected row
    int currow = ui->twp->currentRow();

    qDebug() << "Current Row: " << currow;

    // If no row is selected, show an error message and exit
    if (currow < 0)
    {
        QMessageBox::critical(this, "Error", "No row selected for deletion.");
        return;
    }

    // Retrieve the ID from the hidden column
    QTableWidgetItem *bookTitleItem = ui->twp->item(currow, 0);
    QTableWidgetItem *bookPubYear = ui->twp->item(currow, 1);
    if (!bookTitleItem || !bookPubYear)
    {
        qDebug() << "ID Item is null!";
        QMessageBox::critical(this, "Error", "Не удалось получить идентификатор для удаления.");
        return;
    }

   // QString id = idItem->text();
    QString title = bookTitleItem->text();
    QString bookPub = bookPubYear->text();

    // Ask for confirmation before deleting
    if (QMessageBox::question(this, "Delete", "Delete row?", QMessageBox::Cancel, QMessageBox::Ok) == QMessageBox::Cancel)
    {
        return;
    }

    // Prepare the delete query
    QSqlQuery query(dbconn);
    QString sqlstr = "DELETE FROM book WHERE title = :title and publish_year = :pub_year ";
    query.prepare(sqlstr);
    query.bindValue(":title", title);
    query.bindValue(":pub_year", bookPub);

    // Execute the query and check for errors
    if (!query.exec())
    {
        ui->teResult->append(query.lastQuery());
        auto errorText = query.lastError().text();

        if (errorText.contains("23503")) {
            // SQL error code 23503 corresponds to foreign key violation
            QMessageBox::critical(this, "Error", "Невозможно удалить поставщика, так как на него есть ссылка в другой таблице.");
        } else {
            QMessageBox::critical(this, "Error", errorText);
        }
        return;
    }

    // Log the result and refresh the table
    ui->teResult->append(QString("Deleted %1 row(s)").arg(query.numRowsAffected()));
    selectAll();
}



void providers::on_btnEdit1_clicked()
{
    int currow = ui->twp->currentRow();

    // Если он меньше 0 (строка не выбрана), то
    // сообщение об ошибке и выход из функции
    if( currow < 0 )
    {
        QMessageBox::critical(this,"Error","Not selected row!");
        return;
    }
            ui->leTit->setText(ui->twp->item(ui->twp->currentRow(),0)->text());
            ui->leYea->setText(ui->twp->item(ui->twp->currentRow(),1)->text());
            ui->leCou->setText(ui->twp->item(ui->twp->currentRow(),2)->text());
            ui->lePublishing->setText(ui->twp->item(ui->twp->currentRow(),3)->text());
}


void providers::on_btnMenu_clicked()
{
    this->close();
    adminmenu *amenu = new adminmenu(this);
    amenu->show();
}

void providers::selectAll1()
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
//JOIN goods on goods.id = supply.supplied_id ORDER BY supply.provider_id, supply.date
QString sqlstr = "SELECT title, description FROM category";
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
ui->twp_2->setRowCount( query.size());
else
ui->twp_2->setRowCount( 0);
ui->teResult->append( QString("Read %1 rows").arg(query.size()));
// Прочитать в цикле все строки результата (курсора)
// и вывести их в компонент таблицы
int i=0;
while(query.next())
{
ui->twp_2->setItem(i,0,new
QTableWidgetItem(query.value("title").toString()));
ui->twp_2->setItem(i,1,new
QTableWidgetItem(query.value("description").toString()));
i++;
}
}

void providers::add1()
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
//QString sqlstr = "insert into book(title,year_of_publication,count) values(?,?,?)";
QString sqlstr = "insert into category(title, description) values(?,?)";
// Подготовить запрос
query.prepare(sqlstr);
// Передать параметры из полей ввода в запрос
query.bindValue(0,ui->leTitK->text());
query.bindValue(1,ui->leDisc->text());

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
selectAll1();
}

void providers::del1()
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
int currow = ui->twp_2->currentRow();
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
QString sqlstr = "delete from category where title = '"
+ ui->twp_2->item(currow,0)->text() + "'";
// Выполнить строку запроса и проверить его успешность
if( !query.exec(sqlstr) )
{
ui->teResult->append( query.lastQuery());
QMessageBox::critical(this,"Error","Невозможно удалить данную запись, т.к. в базе содержатся от нее зависящие записи.");
return;
}
// Вывести сообщение об удалении строки
ui->teResult->append( QString("Del %1 rows").arg(query.numRowsAffected()) );
// Обновить содержимое компонента таблицы
selectAll1();
}


void providers::edit1()
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
int currow = ui->twp_2->currentRow();
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
QString sqlstr = "update category set title = ?, description = ? where title = '" + ui->twp_2->item(currow,0)->text() + "'";
// Подготовить запрос
query.prepare(sqlstr);
// Передать параметры из полей ввода в запрос
query.bindValue(0,ui->leTitK->text());
query.bindValue(1,ui->leDisc->text());

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
selectAll1();

}


void providers::on_btnEdit1_3_clicked()
{
    int currow = ui->twp_2->currentRow();

    // Если он меньше 0 (строка не выбрана), то
    // сообщение об ошибке и выход из функции
    if( currow < 0 )
    {
        QMessageBox::critical(this,"Error","Not selected row!");
        return;
    }
            ui->leTitK->setText(ui->twp_2->item(ui->twp_2->currentRow(),0)->text());
            ui->leDisc->setText(ui->twp_2->item(ui->twp_2->currentRow(),1)->text());

}

void providers::on_btnSeaB_clicked()
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
    //title = ?, year_of_publication = ?, count = ?
    QString sqlstr = "select * from book where title LIKE '%' || ? || '%'";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leSeaB->text());
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    ui->twp->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->twp->setItem(i,0,new
        QTableWidgetItem(query.value("title").toString()));
        ui->twp->setItem(i,1,new
        QTableWidgetItem(query.value("publish_year").toString()));
        ui->twp->setItem(i,2,new
        QTableWidgetItem(query.value("count").toString()));
        i++;
    }
    ui->teResult->append(QString("Поиск выполнен успешно").arg(query.numRowsAffected()) );
}

void providers::on_btnSeaK_clicked()
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
    //title = ?, year_of_publication = ?, count = ?
    QString sqlstr = "select title, description from category where title LIKE '%' || ? || '%'";
    // Подготовить запрос
    query.prepare(sqlstr);
    // Передать параметры из полей ввода в запрос
    query.bindValue(0,ui->leSeaK->text());
    // Выполнить запрос
    if( !query.exec() )
    {
        ui->teResult->append( query.lastQuery());
        QMessageBox::critical(this,"Error",query.lastError().text());
        return;
    }
    ui->twp_2->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->twp_2->setItem(i,0,new
        QTableWidgetItem(query.value("title").toString()));
        ui->twp_2->setItem(i,1,new
        QTableWidgetItem(query.value("description").toString()));
        i++;
    }
    ui->teResult->append( QString("Поиск выполнен успешно").arg(query.numRowsAffected()) );
}

void providers::on_comboBox_activated(const QString &arg1)
{
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
    QString sqlstr = "select id, concat(family, ' ', name) as fullname from author";
    // Выполнить запрос и поверить его успешность
    if( !query.exec(sqlstr) )
    {
    QMessageBox::critical(this,"Error", "Query unsuccesful. Check your data and try again!");
    return;
    }
    // Если запрос активен (успешно завершен),
    // то вывести сообщение о прочитанном количестве строк в окно вывода
    // и установить количество строк для компонента таблицы
    ui->teResult->append( QString("Read %1 rows").arg(query.size()));
    // Прочитать в цикле все строки результата (курсора)
    // и вывести их в компонент таблицы
    int i=0;
    //surname, names, patronymic, date_of_birth,date_of_death)
    while(query.next())
    {
        ui->authors->addItem(query.value("fullname").toString());
    }
}

void providers::loadAuthros() {
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
    QString sqlstr = "select id, concat(family, ' ', name) as fullname from author order by family";
    // Выполнить запрос и поверить его успешность
    if( !query.exec(sqlstr) )
    {
    QMessageBox::critical(this,"Error", "Query unsuccesful. Check your data and try again!");
    return;
    }
    // Если запрос активен (успешно завершен),
    // то вывести сообщение о прочитанном количестве строк в окно вывода
    // и установить количество строк для компонента таблицы
    ui->teResult->append( QString("Read %1 rows").arg(query.size()));
    // Прочитать в цикле все строки результата (курсора)
    // и вывести их в компонент таблицы
    int i=0;
    //surname, names, patronymic, date_of_birth,date_of_death)
    while(query.next())
    {
        ui->authors->addItem(query.value("fullname").toString());
    }
}
