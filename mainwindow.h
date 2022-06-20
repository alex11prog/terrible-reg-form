#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "acc.h"
#include <QString>
#include <QRandomGenerator>
#include<QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_login_textChanged(const QString &arg1);

    void on_pushButton_generator_clicked();

    void on_btn_clear_clicked();

    void on_Button_register_clicked();

    void on_reg2_clicked();

    void on_lineEdit_pw_textChanged(const QString &arg1);

    void on_lineEdit_pw2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db_sql;
    QSqlQuery *query_db_sql;
    QSqlTableModel *model_db_sql;
    acc acc_;
    QVector<acc> vector_accs;
    QRandomGenerator *rg;
    bool use_generator = false;
    int num_line_edit = 1;
    QTime time_run;
    QTime last_time_generator = QTime::currentTime();
    QString pw1 = "";
    QString pw2 = "";
    bool check_fields();
    void clear_all();
};
#endif // MAINWINDOW_H
