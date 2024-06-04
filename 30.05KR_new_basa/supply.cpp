#include "supply.h"
#include "ui_supply.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "adminmenu.h"

supply::supply(QWidget *parent) :
QMainWindow(parent),
  ui(new Ui::supply)
{
    ui->setupUi(this);
      connect(ui->btnSelectAll,SIGNAL(clicked(bool)),this, SLOT(selectAll()));
      // Количество столбцов
      ui->twotchet->setColumnCount(8);
      // Возможность прокрутки
      ui->twotchet->setAutoScroll(true);
      // Режим выделения ячеек - только одна строка
      ui->twotchet->setSelectionMode(QAbstractItemView::SingleSelection);
      ui->twotchet->setSelectionBehavior(QAbstractItemView::SelectRows);
      // Заголовки таблицы
      ui->twotchet->setHorizontalHeaderItem(0,new QTableWidgetItem("ID продажи"));
      ui->twotchet->setHorizontalHeaderItem(1,new QTableWidgetItem("ФИО Покупателя"));
      ui->twotchet->setHorizontalHeaderItem(2,new QTableWidgetItem("ФИО Работника"));
      ui->twotchet->setHorizontalHeaderItem(3,new QTableWidgetItem("Приобритеный товар"));
      ui->twotchet->setHorizontalHeaderItem(4,new QTableWidgetItem("Кол-во товара"));
      ui->twotchet->setHorizontalHeaderItem(5,new QTableWidgetItem("Сумма заказа"));
      ui->twotchet->setHorizontalHeaderItem(6,new QTableWidgetItem("ID Покупателя"));
      ui->twotchet->setHorizontalHeaderItem(7,new QTableWidgetItem("ID Работника"));
      // Последний столбец растягивается при изменении размера формы
      ui->twotchet->horizontalHeader()->setStretchLastSection(true);
      // Разрешаем сортировку пользователю
      ui->twotchet->setSortingEnabled(false);
      //ui->twotchet->QTableView::sortByColumn(0);
      // Запрет на изменение ячеек таблицы при отображении
      ui->twotchet->setEditTriggers(QAbstractItemView::NoEditTriggers);

    }

supply::~supply()
{
    if( dbconn.isOpen())
    dbconn.close();
    delete ui;
}

void supply::dbconnect()
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
dbconn.setDatabaseName("diskeshop");
dbconn.setHostName("localhost");
dbconn.setUserName("student");
dbconn.setPassword("1");
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


void supply::selectAll()
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
QString sqlstr = "select * from view1";
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
    QTableWidgetItem(query.value("saleid").toString()));
    ui->twotchet->setItem(i,1,new
    QTableWidgetItem(query.value("customer").toString()));
    ui->twotchet->setItem(i,2,new
    QTableWidgetItem(query.value("employee").toString()));
    ui->twotchet->setItem(i,3,new
    QTableWidgetItem(query.value("goods").toString()));
    ui->twotchet->setItem(i,4,new
    QTableWidgetItem(query.value("quantity").toString()));
    ui->twotchet->setItem(i,5,new
    QTableWidgetItem(query.value("total").toString()));
    ui->twotchet->setItem(i,6,new
    QTableWidgetItem(query.value("customerid").toString()));
    ui->twotchet->setItem(i,7,new
    QTableWidgetItem(query.value("employeeid").toString()));

i++;
}
}

void supply::on_btnMenu_clicked()
{
    this->close();
    adminmenu *amenu = new adminmenu(this);
    amenu->show();
}


