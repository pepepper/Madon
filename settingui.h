#ifndef SETTINGUI_H
#define SETTINGUI_H
#include <QMainWindow>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = 0);
    ~SettingWindow();

private slots:
    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_SettingWindow_destroyed();

    void on_pushButton_2_clicked();

private:
    Ui::SettingWindow *ui;
};

#endif // SETTINGUI_H
