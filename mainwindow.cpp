#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <bits/endian.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::anyColorChanged(IConvertable *changer)
{
    rgb_color_ = changer->ToRGB();
    cmyk_color_ = changer->ToCMYK();
    xyz_color_ = changer->ToXYZ();

    ui->widgetColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                                   .arg(rgb_color_.GetR())
                                   .arg(rgb_color_.GetG())
                                   .arg(rgb_color_.GetB()));
}

void MainWindow::on_sliderB_valueChanged(int value)
{
    rgb_color_.SetB(value);
    anyColorChanged(&rgb_color_);
}

void MainWindow::on_sliderG_valueChanged(int value)
{
    rgb_color_.SetG(value);
    anyColorChanged(&rgb_color_);
}

void MainWindow::on_sliderR_valueChanged(int value)
{
    rgb_color_.SetR(value);
    anyColorChanged(&rgb_color_);
}
