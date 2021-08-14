#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QCoreApplication>
#include <algorithm>
#include <QMessageBox>

QVector<QVector<int> > array_sort(int n);
QVector <int> array_leng;
int i;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    int n = ui->lineEdit->text().toInt();
    if (n<0) {
        QMessageBox::warning(this, "Внимание!","n-только натуральное число!");
        return ;
    }
    array_sort(n);
    print_array(array_sort(n), n);
}

void MainWindow::print_array (QVector<QVector<int> > array_sort, int n) {
    QVector<int> res_array;

    for(int i = 0; i < n; i++)
    {
        QString str;
        res_array = array_sort[i];
        for(int j = 0; j < res_array.length() ; j++)
        {
            str += QString::number(res_array[j]) + ' ';
        }
        ui->plainTextEdit->appendPlainText(str);
        ui->plainTextEdit->appendPlainText(" ");
    }
}

int compare(const int&a, const int&b) {
    if (i%2 ==0)
        return a<b;
    else if (i%2 != 0)
        return a>b;
}

QVector<QVector<int> > array_sort(int n) {
    int val;
    int rand;
    QVector<int> vector[n];
    QVector <QVector<int> > result;

    while(array_leng.length() < n) {
        val = qrand() % 100 + 1;
        if (array_leng.contains(val)) continue;
        array_leng.append(val);
    }
    for (i=0; i<n; i++) {
        while (vector[i].length() < array_leng[i]) {
            rand = qrand() % 100 + 1;
            vector[i].append(rand);
        }
        qSort(vector[i].begin(), vector[i].end(), compare);
    }

    for (int i = 0; i < n ; i++) {
        result.append(vector[i]);
    }
    return result;
}

MainWindow::~MainWindow()
{
    delete ui;
}
