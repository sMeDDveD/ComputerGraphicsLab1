#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <colors.h>

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
    void on_sliderB_valueChanged(int value);

    void on_sliderG_valueChanged(int value);

    void on_sliderR_valueChanged(int value);

private:
    void anyColorChanged(IConvertable* changer);


    Ui::MainWindow *ui;

    RGBColor rgb_color_;
    CMYKColor cmyk_color_;
    XYZColor xyz_color_;
};
#endif // MAINWINDOW_H
