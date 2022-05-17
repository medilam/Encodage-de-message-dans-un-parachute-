#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MessageModel * messageModel = new MessageModel();
    ui->binaryView->setMessageModel(messageModel);
    ui->parachuteView->setMessageModel(messageModel);

    QIcon fileOpen(":/icons/document-open.png");
    ui->action_Open->setIcon(fileOpen);
    QIcon fileNew(":/icons/document-new.png");
    ui->action_New->setIcon(fileNew);
    QIcon fileSave(":/icons/document-save.png");
    ui->action_Save_as->setIcon(fileSave);

    connect(ui->action_Quit,&QAction::triggered,this,&MainWindow::close);
    connect(ui->action_Description,&QAction::triggered,this,&MainWindow::onAbout);
    connect(ui->messageLineEdit, SIGNAL(textChanged(QString)), messageModel, SLOT(setMessage(const QString)));
    connect(ui->nbSector, SIGNAL(valueChanged(int)), ui->parachuteView, SLOT(setNbSector(const int)));
    connect(ui->nbTrack, SIGNAL(valueChanged(int)), ui->parachuteView, SLOT(setNbTrack(const int)));
    connect(ui->nbSector, SIGNAL(valueChanged(int)), ui->sectorSlider, SLOT(setValue( int)));
    connect(ui->nbTrack, SIGNAL(valueChanged(int)), ui->tracks_slider, SLOT(setValue( int)));
    connect(ui->color1, SIGNAL(currentTextChanged(const QString)),ui->parachuteView, SLOT(setColor1(const QString)));
    connect(ui->color0, SIGNAL(currentTextChanged(const QString)),ui->parachuteView, SLOT(setColor0(const QString)));
    connect(ui->color1, SIGNAL(currentTextChanged(const QString)),ui->binaryView, SLOT(setColor1(const QString)));
    connect(ui->color0, SIGNAL(currentTextChanged(const QString)),ui->binaryView, SLOT(setColor0(const QString)));
    connect(ui->tracks_slider,SIGNAL(valueChanged(int)),ui->nbTrack,SLOT(setValue(int)));
    connect(ui->sectorSlider,SIGNAL(valueChanged(int)),ui->nbSector,SLOT(setValue(int)));
    connect(ui->binaryView, SIGNAL(notify()), ui->binaryView, SLOT(update()));
    connect(ui->parachuteView, SIGNAL(notify()), ui->parachuteView, SLOT(update()));
    connect(ui->shiftVal, SIGNAL(valueChanged(int)),messageModel,SLOT(setShift(int)));
    connect(messageModel, SIGNAL(notify()), ui->binaryView, SLOT(update()));
    connect(messageModel, SIGNAL(notify()), ui->parachuteView, SLOT(update()));
    connect(ui->action_Save_as,SIGNAL(triggered(bool)), this, SLOT(saveFile()));
    connect(ui->action_Open, SIGNAL(triggered(bool)), this, SLOT(loadFromFile()));
    connect(ui->action_New, SIGNAL(triggered(bool)), this, SLOT(newFile()));
}

void MainWindow::saveFile() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save parachute Code"),
                                                    "myParachuteCode.txt",
                                                    tr("Parachute Code Files (*.txt)"));
    if(fileName.isEmpty()){
        return;
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file."),file.errorString());
            return;
        }
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << ui->messageLineEdit->text() << "\n";
        stream << QString::number(ui->nbSector->value()) << "\n";
        stream << QString::number(ui->nbTrack->value()) << "\n";
        stream << ui->color1->currentText() << "\n";
        stream << ui->color0->currentText() << "\n";
        stream << QString::number(ui->shiftVal->value());

    }
}

void MainWindow::loadFromFile() {
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open parachute Code"), "",
            tr("Text files (*.txt)"));
    if (fileName.isEmpty()) {
            return;
    } else {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly |  QIODevice::Text)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
            }
        QTextStream stream(&file);
        ui->messageLineEdit->setText(stream.readLine());
        ui->nbSector->setValue(stream.readLine().toInt());
        ui->nbTrack->setValue(stream.readLine().toInt());
        ui->color1->setCurrentText(stream.readLine());
        ui->color0->setCurrentText(stream.readLine());
        ui->shiftVal->setValue(stream.readLine().toInt());

    }
}

void MainWindow::newFile() {
    ui->messageLineEdit->setText("");
    ui->nbSector->setValue(21);
    ui->nbTrack->setValue(5);
    ui->color1->setCurrentText("Red");
    ui->color0->setCurrentText("White");
    ui->shiftVal->setValue(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAbout(){
    QMessageBox::information(this,"Description","Encoding of a message in binary using a parachute");
}

