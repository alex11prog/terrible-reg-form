#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Регистрация");
    db_sql = QSqlDatabase::addDatabase("QSQLITE");
    db_sql.setDatabaseName("./db.db");
    db_sql.open();
    query_db_sql = new QSqlQuery(db_sql);
    query_db_sql->exec("CREATE TABLE reg_db(id INT AUTO_INCREMENT, login TEXT, password TEXT, number_phone TEXT)");
    model_db_sql = new QSqlTableModel(this, db_sql);
    model_db_sql->setTable("reg_db");
    model_db_sql->select();

    for (int i = 0; i < model_db_sql->rowCount(); ++i) {
        acc_.set_login(model_db_sql->record(i).value("login").toString());
        acc_.set_password(model_db_sql->record(i).value("password").toString());
        acc_.set_number_phone(model_db_sql->record(i).value("number_phone").toString());
        vector_accs.push_back(acc_);
    }
    rg = QRandomGenerator::global();
    ui->lineEdit_phone->setReadOnly(true);
    time_run = QTime::currentTime();

}

MainWindow::~MainWindow()
{
    db_sql.close();
    delete ui;
}


void MainWindow::on_lineEdit_login_textChanged(const QString &arg1)
{
    num_line_edit = 1;
    if (!use_generator &&
       (arg1.contains("0") ||
        arg1.contains("1") ||
        arg1.contains("2") ||
        arg1.contains("3") ||
        arg1.contains("4") ||
        arg1.contains("5") ||
        arg1.contains("6") ||
        arg1.contains("7") ||
        arg1.contains("8") ||
        arg1.contains("9"))){
        QMessageBox::warning(this, "Ошибка!", "Цифры вводится только через генератор!");
        clear_all();
    }
    else use_generator = false;
    ui->lineEdit_login->selectAll();

}


void MainWindow::on_pushButton_generator_clicked()
{
    if(last_time_generator.secsTo(QTime::currentTime())<2){
        last_time_generator = QTime::currentTime();
        QMessageBox::StandardButton confirm = QMessageBox::question(this, "Подтверждение", "Подозрительная активновсть\nПодтвердите, что вы не робот!"
                                                                    , QMessageBox::Yes | QMessageBox::No);
        if(confirm == QMessageBox::Yes){
            QMessageBox::StandardButton confirm = QMessageBox::question(this, "Подтверждение", "Вы точно не робот?"
                                                                        , QMessageBox::Yes | QMessageBox::No);
            if(confirm == QMessageBox::Yes){
                QMessageBox::information(this, "Проверка пройдена", "Вы прошли проверку!\nНапоминаем, генератором можно пользоваться не чаще чем раз в 2 секунды!");
            }
            else{
                QMessageBox::warning(this, "Критическая ошибка!", "Вы не прошли проверку!");
            }
        }
        else{
            QMessageBox::warning(this, "Критическая ошибка!", "Вы не прошли проверку!");
        }
        clear_all();
    }
    else{
        last_time_generator = QTime::currentTime();
        QString gnrt = QString::number(rg->bounded(0, 100));
        if(num_line_edit==1){
            use_generator = true;
            if(ui->lineEdit_login->text().length()<10) ui->lineEdit_login->insert(gnrt);
            else{
                num_line_edit=2;
                ui->lineEdit_phone->insert(gnrt);
                ui->lineEdit_login->setReadOnly(true);
            }

        }
        else{
            ui->lineEdit_phone->cursorWordBackward(false);
            ui->lineEdit_phone->insert(gnrt);
        }
    }
}


void MainWindow::on_btn_clear_clicked()
{
    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Подтверждение", "Вы уверены?"
                                                                , QMessageBox::Yes | QMessageBox::No);
    if(confirm == QMessageBox::Yes){
        if(num_line_edit==1){
            ui->lineEdit_login->cursorBackward(false);
            ui->lineEdit_login->backspace();
            ui->lineEdit_phone->del();
        }
        else{
            ui->lineEdit_phone->cursorBackward(false);
            ui->lineEdit_phone->del();
        }
    }
}


void MainWindow::on_Button_register_clicked()
{
    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Подтверждение", "Вы уверены?"
                                                                , QMessageBox::Yes | QMessageBox::No);
    if(confirm == QMessageBox::Yes){
        if(time_run.secsTo(QTime::currentTime())>900){
            QMessageBox::warning(this, "Ошибка!", "Превышен лимит заполнения формы в 15 минут!");
            clear_all();
        }
        else if(check_fields()){
            QMessageBox::warning(this, "Ошибка!", "Вы не попали в центр кнопки!\nПодсказка: центр кнопки внутри буквы \"Р\"");
            clear_all();
        }
    }
}


void MainWindow::on_reg2_clicked()
{
    QMessageBox::StandardButton confirm = QMessageBox::question(this, "Подтверждение", "Вы уверены?"
                                                                , QMessageBox::Yes | QMessageBox::No);
    if(confirm == QMessageBox::Yes){
        if(time_run.secsTo(QTime::currentTime())>900){
            QMessageBox::warning(this, "Ошибка!", "Превышен лимит заполнения формы в 15 минут!");
            clear_all();
        }
        else if(check_fields()){
            acc_.set_login(ui->lineEdit_login->text());
            acc_.set_password(ui->lineEdit_pw->text());
            acc_.set_number_phone(ui->lineEdit_phone->text());
            vector_accs.push_back(acc_);
            QString req = QString("INSERT INTO reg_db(login, password, number_phone) VALUES ('")
                    + acc_.get_login() + QString("', '")
                    + acc_.get_password() + QString("', '")
                    + acc_.get_number_phone() + QString("')");
            query_db_sql->exec(req);
            clear_all();
            QMessageBox::information(this, "Поздравляем!", "Аккаунт успешно зарегистрирован!");
        }
    }
}


void MainWindow::on_lineEdit_pw_textChanged(const QString &arg1)
{
    if(arg1.length()>pw1.length()){
        ui->lineEdit_pw2->cursorBackward(false);
        ui->lineEdit_pw2->insert(arg1[arg1.length()-1]);
    }
    pw1=arg1;
}


void MainWindow::on_lineEdit_pw2_textChanged(const QString &arg1)
{
    if(arg1.length()<pw2.length()){
        ui->lineEdit_pw->backspace();
    }
    pw2=arg1;
    if(            ui->lineEdit_login->text() == "" &&
                   ui->lineEdit_phone->text() == "" &&
                   ui->lineEdit_pw->text() == ""){
        ui->lineEdit_phone->setReadOnly(false);
        ui->lineEdit_phone->setValidator( new QIntValidator);
    }
}

bool MainWindow::check_fields()
{
    if(ui->lineEdit_login->text() == ""){
        QMessageBox::warning(this, "Ошибка!", "Логин не может быть пустым!");
    }
    else if(ui->lineEdit_phone->text().length()!=10){
        QMessageBox::warning(this, "Ошибка!", "Номер должен содержать 10 цифр!");
    }
    else if(ui->lineEdit_pw->text().length()<6){
        QMessageBox::warning(this, "Ошибка!", "Минимальная длина пароля 6 символов!");
    }
    else if(ui->lineEdit_pw2->text().length()<6){
        QMessageBox::warning(this, "Ошибка!", "Минимальная длина пароля 6 символов!");
    }
    else if(ui->lineEdit_pw->text()!=ui->lineEdit_pw2->text()){
        QMessageBox::warning(this, "Ошибка!", "Пароли не совпадают");
    }
    else{
        bool have_login = false;
        bool have_phone = false;
        for(int i = 0; i < vector_accs.size();i++){
            if(vector_accs[i].get_login() == ui->lineEdit_login->text()){
                have_login=true;
            }
            if(vector_accs[i].get_number_phone() == ui->lineEdit_phone->text()){
                have_phone=true;
            }
        }
        if(have_login){
            QMessageBox::warning(this, "Ошибка!", "Данный логин уже занят!");
        }
        else if(have_phone){
            QMessageBox::warning(this, "Ошибка!", "Данный номер телефона уже занят!");
        }
        else{
            return true;
        }

    }
    clear_all();
    return false;
}

void MainWindow::clear_all()
{
    ui->lineEdit_login->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_pw->clear();
    ui->lineEdit_pw2->clear();
    QString str = QString("Осталось ") + QString::number(900 - time_run.secsTo(QTime::currentTime())) + QString(" секунд!");
    QMessageBox::warning(this, "Предупреждение!", str);
}

