#include "header/dialog.h"
#include "ui_dialog.h"
#include "header/datareader.h"
#include "header/item.h"
#include <QMessageBox>
#include <QtConcurrent/QtConcurrent>
#include <fstream>
#include <list>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    diretorio.setFileMode(QFileDialog::DirectoryOnly);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(0);
    ui->progressBar->hide();

    connect(&this->FutureWatcher, SIGNAL (finished()), this, SLOT (slot_finished()));

}

Dialog::~Dialog()
{
    delete ui;
}

unsigned int Dialog::init_read( const std::string& dir, bool log ) {

    std::string item_db;
    if ( data::getFile(dir+"/item_db.conf", item_db ) == false ) return 1;

    std::string display_name;
    if ( data::getFile(dir+"/idnum2itemdisplaynametable.txt", display_name ) == false ) return 2;


    std::string sprite_name;
    if ( data::getFile(dir+"/idnum2itemresnametable.txt", sprite_name ) == false ) return 3;

    std::string description;
    if ( data::getFile(dir+"/idnum2itemdesctable.txt", description ) == false ) return 4;

    std::string udisplay_name;
    if ( data::getFile(dir+"/num2itemdisplaynametable.txt", udisplay_name ) == false ) return 5;

    std::string udescription;
    if ( data::getFile(dir+"/num2itemdesctable.txt", udescription ) == false ) return 6;

    std::string usprite_name;
    if ( data::getFile(dir+"/num2itemresnametable.txt", usprite_name ) == false ) return 7;

    std::string item_slot;
    if ( data::getFile(dir+"/itemslotcounttable.txt", item_slot ) == false ) return 8;

    std::ofstream saida("itemInfo.lua");
    if ( !saida ) return 9;


    std::map<std::string,std::string> view = data::format_viewid_to_map(item_db);

    std::map<std::string,std::string> disp = data::format_displayname_to_map(display_name);

    std::map<std::string,std::string> desc = data::format_description_to_map(description);

    std::map<std::string,std::string> sprite = data::format_displayname_to_map(sprite_name);

    std::map<std::string,std::string> udisp = data::format_displayname_to_map(udisplay_name);

    std::map<std::string,std::string> udesc = data::format_description_to_map(udescription);

    std::map<std::string,std::string> usprite = data::format_displayname_to_map(usprite_name);

    std::map<std::string,std::string> slot = data::format_slot_to_map(item_slot);


    saida << "tbl = {\n";

    if ( log == true ) {
        std::ofstream logerror("itemInfo.log");
        std::map<std::string, std::list<std::string>> logitem;
        for ( const auto& item: disp ) {
            std::string id = item.first;
            std::string display = item.second;
            std::string spr = sprite[id];
            std::string ds = desc[id];
            std::string udis = udisp[id];
            std::string uspr = usprite[id];
            std::string uds = udesc[id];
            std::string vi = view[id];
            std::string sl = slot[id];
            if ( display.empty() )logitem[id].push_back("Nome não encontrado.");
            if ( spr.empty() )logitem[id].push_back("Sprite não encotrada.");
            if ( ds.empty() )logitem[id].push_back("Descrição não encontrada");
            if ( udis.empty() )logitem[id].push_back("Nome de item desconhecido não encontrado.");
            if ( uspr.empty() )logitem[id].push_back("Sprite de item desconhecido não encontrado.");
            if ( uds.empty() )logitem[id].push_back("Descrição de item desconhecido não encontrado.");
            if ( vi.empty() )logitem[id].push_back("ViewId não encontrado.");

            saida << Item( id, display,  spr, ds, udis, uspr, uds, ((vi.empty())? "0":vi), ((sl.empty())? "0":sl) ).toString();
        }

        for ( const auto& error: logitem ) {
            logerror << error.first << ":";
            for ( const auto& info: error.second ) logerror << " " << info;
            logerror << std::endl;
        }

        logerror.close();
    }
    else for ( const auto& item: disp ) saida << Item( item.first, item.second,  sprite[item.first], desc[item.first], udisp[item.first], usprite[item.first], udesc[item.first], ((view[item.first].empty())? "0":view[item.first]), ((slot[item.first].empty())? "0":slot[item.first]) ).toString();

    saida << "}\nmain = function()\n\tfor ItemID,DESC in pairs(tbl) do\n\t\tresult, msg = AddItem(ItemID, DESC.unidentifiedDisplayName, DESC.unidentifiedResourceName, DESC.identifiedDisplayName, DESC.identifiedResourceName, DESC.slotCount, DESC.ClassNum)\n\t\tif not result then\n\t\t\treturn false, msg\n\t\tend\n\t\tfor k,v in pairs(DESC.unidentifiedDescriptionName) do\n\t\t\tresult, msg = AddItemUnidentifiedDesc(ItemID, v)\n\t\t\tif not result then\n\t\t\t\treturn false, msg\n\t\t\tend\n\t\tend\n\t\tfor k,v in pairs(DESC.identifiedDescriptionName) do\n\t\t\tresult, msg = AddItemIdentifiedDesc(ItemID, v)\n\t\t\tif not result then\n\t\t\t\treturn false, msg\n\t\t\tend\n\t\tend\n\tend\n\treturn true, \"good\"\nend";

    saida.close();

    return 0;
}

void Dialog::start_convert() {

    ui->progressBar->show();

    QFuture<unsigned int> future = QtConcurrent::run( this,Dialog::init_read,ui->showDirName->text().toStdString(), ui->errorCheckBox->isChecked() );

    this->FutureWatcher.setFuture(future);

}

void Dialog::slot_finished() {
    ui->progressBar->hide();

    unsigned int result = this->FutureWatcher.future().result();
    switch(result) {
    case 1:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar item_db.conf").exec();
        break;
    case 2:
         QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar idnum2itemdisplaynametable.txt").exec();
        break;
    case 3:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar idnum2itemresnametable.txt").exec();
        break;
    case 4:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar idnum2itemdesctable.txt").exec();
        break;
    case 5:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar num2itemdisplaynametable.txt").exec();
        break;
    case 6:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar num2itemdesctable.txt").exec();
        break;
    case 7:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar num2itemresnametable.txt").exec();
        break;
    case 8:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível encontrar itemslotcounttable.txt").exec();
        break;
    case 9:
        QMessageBox(QMessageBox::Information,"Cuidado","Não foi possível criar o arquivo itemInfo.lua").exec();
        break;

    }

}

void Dialog::on_selectButton_clicked()
{
    ui->showDirName->setText(diretorio.getExistingDirectory());
}

void Dialog::on_convertButton_clicked()
{

    start_convert();

}
