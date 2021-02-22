#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QColorDialog>
#include <QIntValidator>

#include <cmath>

static RGBColor kDefaultColor = {103, 201, 0};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setAttribute(Qt::WA_AlwaysShowToolTips);

    AnyColorChanged(&kDefaultColor);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AnyColorChanged(IConvertable *changer) {
    if (is_changing_colors_) {
        return;
    }

    changer->Exacted();

    is_changing_colors_ = true;

    UpdateRGB(changer);
    UpdateCMYK(changer);
    UpdateXYZ(changer);

    QStringList rounded_colors;

    if (!rgb_color_.IsExact()) {
        rounded_colors.append(QString("RGB"));
    }

    if (!cmyk_color_.IsExact()) {
        rounded_colors.append(QString("CMYK"));
    }

    if (!xyz_color_.IsExact()) {
        rounded_colors.append(QString("XYZ"));
    }

    if (!rounded_colors.empty()) {
        ui->statusBar->showMessage(rounded_colors.join(", ") +
                                   (rounded_colors.length() == 1 ? " was" : " were") + " rounded");
        ui->statusBar->setStyleSheet("color: rgb(200, 0, 0)");
        ui->statusBar->showMaximized();
    } else {
        ui->statusBar->showMessage("All is OK", 2000);
        ui->statusBar->setStyleSheet("color: rgb(0, 200, 0)");
    }

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

    ui->spinBoxR->setValue(updater.GetR());
    ui->spinBoxG->setValue(updater.GetG());
    ui->spinBoxB->setValue(updater.GetB());

    rgb_color_ = updater;
}

void MainWindow::UpdateCMYK(IConvertable *from) {
    auto updater = from->ToCMYK();

    ui->sliderC->setValue(std::round(updater.GetC() * 100));
    ui->sliderM->setValue(std::round(updater.GetM() * 100));
    ui->sliderY->setValue(std::round(updater.GetY() * 100));
    ui->sliderK->setValue(std::round(updater.GetK() * 100));

    ui->doubleSpinBoxC->setValue(updater.GetC() * 100.0);
    ui->doubleSpinBoxM->setValue(updater.GetM() * 100.0);
    ui->doubleSpinBoxY->setValue(updater.GetY() * 100.0);
    ui->doubleSpinBoxK->setValue(updater.GetK() * 100.0);

    cmyk_color_ = updater;
}

void MainWindow::UpdateXYZ(IConvertable *from) {
    auto updater = from->ToXYZ();

    ui->sliderX->setValue(updater.GetX());
    ui->sliderY_XYZ->setValue(updater.GetY());
    ui->sliderZ->setValue(updater.GetZ());

    ui->doubleSpinBoxX->setValue(updater.GetX());
    ui->doubleSpinBoxY_XYZ->setValue(updater.GetY());
    ui->doubleSpinBoxZ->setValue(updater.GetZ());

    xyz_color_ = updater;
}

void MainWindow::on_sliderB_valueChanged(int value) {
    rgb_color_.SetB(value);

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_sliderG_valueChanged(int value) {
    rgb_color_.SetG(value);

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_sliderR_valueChanged(int value) {
    rgb_color_.SetR(value);

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_sliderC_valueChanged(int value) {
    cmyk_color_.SetC(value / 100.0);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderM_valueChanged(int value) {
    cmyk_color_.SetM(value / 100.0);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderY_valueChanged(int value) {
    cmyk_color_.SetY(value / 100.0);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderK_valueChanged(int value) {
    cmyk_color_.SetK(value / 100.0);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_sliderX_valueChanged(int value) {
    xyz_color_.SetX(value);

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_sliderY_XYZ_valueChanged(int value) {
    xyz_color_.SetY(value);

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_sliderZ_valueChanged(int value) {
    xyz_color_.SetZ(value);

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_spinBoxR_valueChanged(int value) {
    rgb_color_.SetR(value);

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_spinBoxG_valueChanged(int value) {
    rgb_color_.SetG(value);

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_spinBoxB_valueChanged(int value) {
    rgb_color_.SetB(value);

    AnyColorChanged(&rgb_color_);
}

void MainWindow::on_doubleSpinBoxC_valueChanged(double value) {
    cmyk_color_.SetC(value / 100);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_doubleSpinBoxM_valueChanged(double value) {
    cmyk_color_.SetM(value / 100);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_doubleSpinBoxY_valueChanged(double value) {
    cmyk_color_.SetY(value / 100);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_doubleSpinBoxK_valueChanged(double value) {
    cmyk_color_.SetK(value / 100);

    AnyColorChanged(&cmyk_color_);
}

void MainWindow::on_doubleSpinBoxX_valueChanged(double value) {
    xyz_color_.SetX(value);

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_doubleSpinBoxY_XYZ_valueChanged(double value) {
    xyz_color_.SetY(value);

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_doubleSpinBoxZ_valueChanged(double value) {
    xyz_color_.SetZ(value);

    AnyColorChanged(&xyz_color_);
}

void MainWindow::on_paletteButton_clicked() {
    auto color =
        QColorDialog::getColor(QColor(rgb_color_.GetR(), rgb_color_.GetG(), rgb_color_.GetB()),
                               nullptr, QString("Choose color"), QColorDialog::DontUseNativeDialog);

    if (!color.isValid()) {
        return;
    }

    auto qrgb = color.rgb();

    RGBColor rgb(qRed(qrgb), qGreen(qrgb), qBlue(qrgb));
    AnyColorChanged(&rgb);
}
