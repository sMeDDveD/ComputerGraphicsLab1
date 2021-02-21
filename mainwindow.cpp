#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AnyColorChanged(IConvertable *changer) {
    if (is_changing_colors_) {
        return;
    }

    is_changing_colors_ = true;

    UpdateRGB(changer);
    UpdateCMYK(changer);
    UpdateXYZ(changer);

    ui->widgetColor->setStyleSheet(QString("background-color: rgb(%1, %2, %3)")
                                       .arg(rgb_color_.GetR())
                                       .arg(rgb_color_.GetG())
                                       .arg(rgb_color_.GetB()));

    is_changing_colors_ = false;
}

void MainWindow::UpdateRGB(IConvertable *from) {
    auto updater = from->ToRGB();

    ui->sliderR->setValue(updater.GetR());
    ui->sliderG->setValue(updater.GetG());
    ui->sliderB->setValue(updater.GetB());

    rgb_color_ = updater;
}

void MainWindow::UpdateCMYK(IConvertable *from) {
    auto updater = from->ToCMYK();

    ui->sliderC->setValue(updater.GetC() * 100);
    ui->sliderM->setValue(updater.GetM() * 100);
    ui->sliderY->setValue(updater.GetY() * 100);
    ui->sliderK->setValue(updater.GetK() * 100);

    cmyk_color_ = updater;
}

void MainWindow::UpdateXYZ(IConvertable *from) {
    auto updater = from->ToXYZ();

    ui->sliderX->setValue(updater.GetX());
    ui->sliderY_XYZ->setValue(updater.GetY());
    ui->sliderZ->setValue(updater.GetZ());

    xyz_color_ = updater;
}

void MainWindow::on_sliderB_valueChanged(int value) {
    rgb_color_.SetB(value);
    ui->lineEditB->setText(QString::number(value));

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_sliderG_valueChanged(int value) {
    rgb_color_.SetG(value);
    ui->lineEditG->setText(QString::number(value));

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_sliderR_valueChanged(int value) {
    rgb_color_.SetR(value);
    ui->lineEditR->setText(QString::number(value));

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_paletteButton_clicked() {
    auto color =
        QColorDialog::getColor(QColor(rgb_color_.GetR(), rgb_color_.GetG(), rgb_color_.GetB()),
                               nullptr, QString("Choose color"), QColorDialog::DontUseNativeDialog);

    auto qrgb = color.rgb();

    RGBColor rgb(qRed(qrgb), qGreen(qrgb), qBlue(qrgb));
    AnyColorChanged(&rgb);
}

void MainWindow::on_sliderC_valueChanged(int value)
{
    cmyk_color_.SetC(value / 100.0);
    ui->lineEditC->setText(QString::number(value));

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderM_valueChanged(int value)
{
    cmyk_color_.SetM(value / 100.0);
    ui->lineEditM->setText(QString::number(value));

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderY_valueChanged(int value)
{
    cmyk_color_.SetY(value / 100.0);
    ui->lineEditY->setText(QString::number(value));

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderK_valueChanged(int value)
{
    cmyk_color_.SetK(value / 100.0);
    ui->lineEditK->setText(QString::number(value));

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderX_valueChanged(int value)
{
    xyz_color_.SetX(value);
    ui->lineEditX->setText(QString::number(value));

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_sliderY_XYZ_valueChanged(int value)
{
    xyz_color_.SetY(value);
    ui->lineEditY_XYZ->setText(QString::number(value));

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_sliderZ_valueChanged(int value)
{
    xyz_color_.SetZ(value);
    ui->lineEditZ->setText(QString::number(value));

    AnyColorChanged(&xyz_color_);
}
