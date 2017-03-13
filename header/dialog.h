#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QFutureWatcher>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void start_convert();
    unsigned int init_read(const std::string& dir, bool log);

private slots:
    void on_selectButton_clicked();

    void on_convertButton_clicked();

    void slot_finished();

private:
    QFileDialog diretorio;
    QFutureWatcher<unsigned int> FutureWatcher;
    Ui::Dialog *ui;
};


#endif // DIALOG_H
