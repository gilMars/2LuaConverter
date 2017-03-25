/*
 * Arquivo gerado automaticamente pelo QtCreator. Arquivo de cabeçalho com os dados resposáveis pela GUI.
 * @author Gilmar B. Freitas.
 * @version 1.0
*/
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

    /*
     * Função membro que inicializa a conversão a conversão dos arquivos em outro thread e manipula outras membros da GUI.
    */
    void start_convert();

    /*
     * init_read é o método público que irá receber o diretório dos arquivo e irá carregá-los na memória principal.
     * @param dir string com o caminho do diretório dos arquivos.
     * @param log booleano que determina se a função fará log de erros ou não.
     * @return unsigned int, será um valor inteiro não assinado que representa o arquivo que não pode ser lido, valores entre 1~9.
    */
    unsigned int init_read(const std::string& dir, bool log);

private slots:
    void on_selectButton_clicked();

    void on_convertButton_clicked();

    void slot_finished();

    void on_creditos_clicked();

private:
    QFileDialog diretorio;                      // Atributo que representa o caminho dos arquivos item_db.conf e etc...
    QFutureWatcher<unsigned int> FutureWatcher; // Atributo que assiste o thread que fará a conversão do arquivo
    Ui::Dialog *ui;
};


#endif // DIALOG_H
