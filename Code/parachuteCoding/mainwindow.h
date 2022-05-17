/** -*- mode: c++ ; c-basic-offset: 2 -*-
 * @file  mainWindow.h
 * @author Houcem Jouili et Lamhamdi Mehdi
 *
 * @brief  main Window declaration.
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "MessageModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots :
    void onAbout();

public slots:
    void saveFile();
    void loadFromFile();
    void newFile();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
