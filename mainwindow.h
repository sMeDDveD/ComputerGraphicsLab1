#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <colors.h>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_paletteButton_clicked();

    void on_sliderB_valueChanged(int value);

    void on_sliderG_valueChanged(int value);

    void on_sliderR_valueChanged(int value);

    void on_sliderC_valueChanged(int value);

    void on_sliderM_valueChanged(int value);

    void on_sliderY_valueChanged(int value);

    void on_sliderK_valueChanged(int value);

    void on_sliderX_valueChanged(int value);

    void on_sliderY_XYZ_valueChanged(int value);

    void on_sliderZ_valueChanged(int value);

private:
    void AnyColorChanged(IConvertable *changer);

    void UpdateRGB(IConvertable *from);
    void UpdateCMYK(IConvertable *from);
    void UpdateXYZ(IConvertable *from);

    Ui::MainWindow *ui;

    bool is_changing_colors_ = false;
    RGBColor rgb_color_;
    CMYKColor cmyk_color_;
    XYZColor xyz_color_;
};
#endif  // MAINWINDOW_H
