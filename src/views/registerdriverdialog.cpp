#include "registerdriverdialog.h"
#include "ui_registerdriverdialog.h"

RegisterDriverDialog::RegisterDriverDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDriverDialog)
{
    ui->setupUi(this);

    connect(ui->btnCancelar,
            &QPushButton::clicked,
            this,
            &QDialog::reject);
}

RegisterDriverDialog::~RegisterDriverDialog()
{
    delete ui;
}

void RegisterDriverDialog::on_btnSalvar_clicked()
{
    QString nome = ui->LnNome->text();
    QString telefone = ui->LnTelefone->text();

    qDebug() << "Nome: " << nome;
    qDebug() << "Telefone: " << telefone;
}

