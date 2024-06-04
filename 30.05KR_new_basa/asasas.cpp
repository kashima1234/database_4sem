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
    QString sqlstr = "select * from view3 where fio LIKE '%' || ? || '%'";
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
    ui->two->setRowCount(query.numRowsAffected());
    int i = 0;
    while(query.next())
    {
        ui->two->setItem(i,0,new
        QTableWidgetItem(query.value("id").toString()));
        ui->two->setItem(i,1,new
        QTableWidgetItem(query.value("fio").toString()));
        ui->two->setItem(i,2,new
        QTableWidgetItem(query.value("name").toString()));
        ui->two->setItem(i,3,new
        QTableWidgetItem(query.value("quantity").toString()));
        ui->two->setItem(i,4,new
        QTableWidgetItem(query.value("total").toString()));
        ui->two->setItem(i,5,new
        QTableWidgetItem(query.value("customer_id").toString()));
        i++;
    }
    ui->teResult->append( QString("Поиск выполнен успешно").arg(query.numRowsAffected()) );
}
