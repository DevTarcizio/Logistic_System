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

    connect(&driverService,
            &DriverService::driverCreated,
            this,
            [this]()
            {
                QMessageBox::information(
                    this,
                    "Sucesso",
                    "Motorista cadastrado com sucesso!"
                    );

                accept();
            });

    connect(&driverService,
            &DriverService::requestError,
            this,
            [this](const QString &erro)
            {
                QMessageBox::critical(
                    this,
                    "Erro",
                    erro
                    );
            });
}

RegisterDriverDialog::~RegisterDriverDialog()
{
    delete ui;
}

void RegisterDriverDialog::on_btnSalvar_clicked()
{
    QString nome = ui->LnNome->text();
    QString telefone = ui->LnTelefone->text();

    if (nome.isEmpty() || telefone.isEmpty()) {
        QMessageBox::warning(
            this,
            "Campos Obrigatórios",
            "Preencha todos os campos"
            );

        return;
    }

    driverService.createDriver(nome, telefone);
}

