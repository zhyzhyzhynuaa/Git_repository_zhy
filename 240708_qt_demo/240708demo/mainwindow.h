#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTableWidget>
#include <QStringList>
#include <QListWidget>
#include <QCheckBox>
#include <QTabWidget>
#include <QVector>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTreeWidgetItemClicked(QTreeWidgetItem *item, int column);
    void onTreeWidgetItemChanged(QTreeWidgetItem *item, int column);
    void on_pushButton_5_clicked();
    void onItemClicked(QListWidgetItem *item);//测试点
    void on_lineEdit_textEdited(const QString &arg1);
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    void loadCsvData(const QString &filePath, QTreeWidgetItem *parentItem);
    void setupTreeWidget();
    void addToTableWidget(const QStringList &data);
    void removeFromTableWidget(const QString &faultName);
    void clearTreeWidgetChecks(QTreeWidgetItem *item);
    void clearListWidgetChecks();
    void storeAllItems();
    QList<QTreeWidgetItem*> allItems; // 存储所有的树项，用于搜索功能
    void loadCSV(const QString &filePath);
    void updateTableWidget(QListWidgetItem *item);
    void syncTabWidgets(int index);
    QStringList getSelectedFaults();
    QStringList getSelectedTestPoints();
    QVector<QStringList> loadMatrixData(const QString &filePath);

};
#endif // MAINWINDOW_H
