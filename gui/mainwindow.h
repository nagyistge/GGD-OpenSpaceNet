#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <string>
#include <iostream>
#include <QTextStream>
#include <QMessageBox>
#include <OpenSkyNetArgs.h>
#include <OpenSkyNet.h>
#include <boost/make_unique.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_runPushButton_clicked();

    void on_localImageFileBrowseButton_clicked();

    void on_modelFileBrowseButton_clicked();

    void on_outputLocationBrowseButton_clicked();

    void on_viewMetadataButton_clicked();

    void on_helpPushButton_clicked();

    void on_nmsCheckBox_toggled(bool checked);

    void on_bboxOverrideCheckBox_toggled(bool checked);

private:
    dg::openskynet::OpenSkyNetArgs osnArgs;
    Ui::MainWindow *ui;
    std::string action;

    std::string imageSource;
    std::string localImageFilePath;

    std::string modelFilePath;

    int confidence;
    int stepSize;
    bool pyramid;
    bool NMS;
    int nmsThreshold;

    std::string  bboxNorth;
    std::string  bboxSouth;
    std::string  bboxEast;
    std::string  bboxWest;

    std::string outputFormat;
    std::string geometryType;
    std::string outputLocation;
    std::string outputLayer;
    bool producerInfo;

    std::string processingMode;
    int maxUtilization;
    int windowSize1;
    int windowSize2;

};

#endif // MAINWINDOW_H
