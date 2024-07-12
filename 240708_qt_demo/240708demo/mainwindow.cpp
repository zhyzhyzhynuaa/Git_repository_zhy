#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QHeaderView>
#include <QMessageBox>
#include <utility>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter->setStyleSheet("QSplitter::handle { background-color: pink; }");
    ui->splitter->setSizes({20000,70000});      //比例要万级数量级，确保大于QSplitter
    QStringList headers = {"故障名称", "故障率", "故障部位", "故障注入方式", "故障描述"};    // 设置 tableWidget 的列标题
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    setupTreeWidget();
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
    loadCSV("C:/Users/admin/Desktop/240708_qt_demo/file/测试点信息1.csv");// 加载测试点信息CSV文件
    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::onTreeWidgetItemClicked);
    connect(ui->treeWidget, &QTreeWidget::itemChanged, this, &MainWindow::onTreeWidgetItemChanged);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::onItemClicked);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::syncTabWidgets);     //tab界面关联
    connect(ui->tabWidget_2, &QTabWidget::currentChanged, this, &MainWindow::syncTabWidgets);   //tab界面关联

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTreeWidget()
{
    ui->treeWidget->clear();
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget, QStringList("滑油系统子系统"));
    ui->treeWidget->addTopLevelItem(rootItem);
    ui->treeWidget->setHeaderHidden(true);// 隐藏列名（表头）
    QTreeWidgetItem *supplyOilSystemItem = new QTreeWidgetItem(rootItem, QStringList("供油系统"));
    QTreeWidgetItem *returnOilSystemItem = new QTreeWidgetItem(rootItem, QStringList("回油系统"));
    QTreeWidgetItem *ventilationSystemItem = new QTreeWidgetItem(rootItem, QStringList("通风系统"));
    QTreeWidgetItem *otherSystemItem = new QTreeWidgetItem(rootItem, QStringList("其它"));
    loadCsvData("C:/Users/admin/Desktop/240708_qt_demo/file/供油系统1.csv", supplyOilSystemItem);
    loadCsvData("C:/Users/admin/Desktop/240708_qt_demo/file/回油系统1.csv", returnOilSystemItem);
    loadCsvData("C:/Users/admin/Desktop/240708_qt_demo/file/通风系统1.csv", ventilationSystemItem);
    loadCsvData("C:/Users/admin/Desktop/240708_qt_demo/file/其它1.csv", otherSystemItem);
    // 将所有项存储到列表中以便后续搜索使用
    storeAllItems();
}
void MainWindow::storeAllItems()
{
    allItems.clear();
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        allItems.append(*it);
        ++it;
    }
}
void MainWindow::loadCsvData(const QString &filePath, QTreeWidgetItem *parentItem)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);  // 确保以UTF-8编码读取文件
    // 跳过第一行（表头）
    if (!in.atEnd()) {
        in.readLine();
    }
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() == 5) {
            QTreeWidgetItem *item = new QTreeWidgetItem(parentItem);
            item->setCheckState(0, Qt::Unchecked); // 添加复选框
            item->setText(0, fields.at(0)); // 故障名称
            item->setData(0, Qt::UserRole, fields); // 存储所有字段数据
        }
    }
    file.close();
}
void MainWindow::syncTabWidgets(int index) {
    QTabWidget *senderTabWidget = qobject_cast<QTabWidget*>(sender());
    if (senderTabWidget == ui->tabWidget) {
        // 如果信号来自tabWidget，则同步tabWidget2
        if (index == 0) {
            ui->tabWidget_2->setCurrentIndex(0);
        } else if (index == 1) {
            ui->tabWidget_2->setCurrentIndex(1);
        }
    } else if (senderTabWidget == ui->tabWidget_2) {
        // 如果信号来自tabWidget2，则同步tabWidget
        if (index == 0) {
            ui->tabWidget->setCurrentIndex(0);
        } else if (index == 1) {
            ui->tabWidget->setCurrentIndex(1);
        }
    }
    // 检查lineEdit中的文本，并进行搜索
    QString searchText = ui->lineEdit->text().trimmed();
    on_lineEdit_textEdited(searchText);
}
void MainWindow::onTreeWidgetItemClicked(QTreeWidgetItem *item, int column)
{
    // 如果是分组节点，折叠或展开
    if (item->childCount() > 0) {
        item->setExpanded(!item->isExpanded());
    } else {
        // 切换复选框状态
        if (item->checkState(0) == Qt::Unchecked) {
            item->setCheckState(0, Qt::Checked);
        } else {
            item->setCheckState(0, Qt::Unchecked);
        }
    }
}

void MainWindow::onTreeWidgetItemChanged(QTreeWidgetItem *item, int column)
{
    if (column != 0) return;

    QStringList data = item->data(0, Qt::UserRole).toStringList();
    if (data.size() == 5) {
        if (item->checkState(0) == Qt::Checked) {
            addToTableWidget(data);
        } else if (item->checkState(0) == Qt::Unchecked) {
            removeFromTableWidget(data.at(0)); // 使用故障名称来删除行
        }
    }
}

void MainWindow::addToTableWidget(const QStringList &data)
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
    // 显示故障名称和其他信息
    for (int i = 0; i < data.size(); ++i) {
        QTableWidgetItem *tableItem = new QTableWidgetItem(data.at(i));
        ui->tableWidget->setItem(rowCount, i, tableItem);
    }
}

void MainWindow::removeFromTableWidget(const QString &faultName)
{
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        if (ui->tableWidget->item(i, 0)->text() == faultName) {
            ui->tableWidget->removeRow(i);
            break;
        }
    }
}

void MainWindow::on_pushButton_5_clicked()      //清空显示
{
    if (ui->tabWidget_2->currentIndex() == 0) { // 0是faultInformationtab页面的索引
        clearTreeWidgetChecks(ui->treeWidget->topLevelItem(0));
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
    } else if (ui->tabWidget_2->currentIndex() == 1) { // 1是testpointinformation页面的索引
        clearListWidgetChecks();
        ui->tableWidget_2->clearContents(); // 清空tableWidget_2
        ui->tableWidget_2->setRowCount(0);
    }
}
void MainWindow::clearTreeWidgetChecks(QTreeWidgetItem *item)
{
    if (item) {
        for (int i = 0; i < item->childCount(); ++i) {
            QTreeWidgetItem *child = item->child(i);
            if (child->childCount() > 0) {
                clearTreeWidgetChecks(child);
            } else {
                child->setCheckState(0, Qt::Unchecked);
            }
        }
    }
}
void MainWindow::clearListWidgetChecks()
{
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
    }
}
void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    QString searchText = arg1.trimmed();
    if (ui->tabWidget->currentIndex() == 0) { // 假设0是faultSelecttab页面的索引
        // 遍历所有项，根据搜索文本显示或隐藏项
        for (QTreeWidgetItem *item : std::as_const(allItems)) {
            if (item->text(0).contains(searchText, Qt::CaseInsensitive)) {
                item->setHidden(false);
                QTreeWidgetItem *parent = item->parent();
                while (parent) {
                    parent->setHidden(false);
                    parent->setExpanded(true);
                    parent = parent->parent();
                }
            } else {
                item->setHidden(true);
            }
        }
        // 如果搜索文本为空，显示所有项并收起所有节点
        if (searchText.isEmpty()) {
            for (QTreeWidgetItem *item : std::as_const(allItems)) {
                item->setHidden(false);
                if (item->childCount() == 0) {
                    QTreeWidgetItem *parent = item->parent();
                    if (parent) {
                        parent->setExpanded(false);
                    }
                }
            }
        }
    } else if (ui->tabWidget->currentIndex() == 1) { // 假设1是testPointSelecttab页面的索引
        // 遍历listWidget中的所有项，根据搜索文本显示或隐藏项
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QListWidgetItem *item = ui->listWidget->item(i);
            if (item->text().contains(searchText, Qt::CaseInsensitive)) {
                item->setHidden(false);
            } else {
                item->setHidden(true);
            }
        }
        // 如果搜索文本为空，显示所有项
        if (searchText.isEmpty()) {
            for (int i = 0; i < ui->listWidget->count(); ++i) {
                QListWidgetItem *item = ui->listWidget->item(i);
                item->setHidden(false);
            }
        }
    }
}

void MainWindow::loadCSV(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return;
    }
    QTextStream in(&file);
    bool firstLine = true;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (firstLine) {
            firstLine = false;
            // 跳过标题行
            continue;
        }
        if (fields.size() != 4) {
            continue; // 跳过格式不正确的行
        }
        QString testName = fields[0];
        QString testLocation = fields[1];
        QString testSensitivity = fields[2];
        QString testDescription = fields[3];
        // 添加到listWidget
        QListWidgetItem *item = new QListWidgetItem(testName, ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        // 存储其他信息到item的data中
        item->setData(Qt::UserRole, fields);
    }
    file.close();
}

void MainWindow::onItemClicked(QListWidgetItem *item)
{
    // 切换复选框状态
    if (item->checkState() == Qt::Unchecked) {
        item->setCheckState(Qt::Checked);
    } else {
        item->setCheckState(Qt::Unchecked);
    }
    // 更新tableWidget_2
    updateTableWidget(item);
}

void MainWindow::updateTableWidget(QListWidgetItem *item)
{
    QStringList fields = item->data(Qt::UserRole).toStringList();
    if (fields.size() != 4) {
        return; // 跳过格式不正确的数据
    }
    if (item->checkState() == Qt::Checked) {
        // 添加到tableWidget_2
        int row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(fields[0]));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(fields[1]));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(fields[2]));
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(fields[3]));
    } else {
        // 从tableWidget_2中移除
        for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
            if (ui->tableWidget_2->item(row, 0)->text() == fields[0]) {
                ui->tableWidget_2->removeRow(row);
                break;
            }
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget_3->clearContents();// 清空 tableWidget_3 的内容
    ui->tableWidget_3->setRowCount(0);
    ui->tableWidget_3->setColumnCount(0);
    QStringList selectedFaults = getSelectedFaults();// 获取勾选的故障名称
    QStringList selectedTestPoints = getSelectedTestPoints();// 获取勾选的测试点名称
    QVector<QStringList> matrixData = loadMatrixData("C:/Users/admin/Desktop/240708_qt_demo/file/Dmatrix1.csv");// 从文件中加载 Dmatrix1.csv 数据
    if (matrixData.isEmpty() || selectedFaults.isEmpty() || selectedTestPoints.isEmpty()) {
        return; // 如果没有数据或没有选择任何故障or测试点，则返回
    }
    // 获取第一行和第一列的数据
    QStringList testPointNames = matrixData.first();
    QStringList faultNames;
    for (int i = 1; i < matrixData.size(); ++i) {
        faultNames.append(matrixData[i].first());
    }
    // 设置 tableWidget_3 的行和列
    ui->tableWidget_3->setRowCount(selectedFaults.size());
    ui->tableWidget_3->setColumnCount(selectedTestPoints.size());
    ui->tableWidget_3->setHorizontalHeaderLabels(selectedTestPoints);
    ui->tableWidget_3->setVerticalHeaderLabels(selectedFaults);
    // 填充 tableWidget_3 的内容
    for (int i = 0; i < selectedFaults.size(); ++i) {
        for (int j = 0; j < selectedTestPoints.size(); ++j) {
            QString faultName = selectedFaults[i];
            QString testPointName = selectedTestPoints[j];

            int row = faultNames.indexOf(faultName) + 1; // 加1是因为第一行是标题
            int column = testPointNames.indexOf(testPointName);

            if (row > 0 && column > 0) {
                QString value = matrixData[row][column];
                ui->tableWidget_3->setItem(i, j, new QTableWidgetItem(value));
            }
        }
    }
}

QStringList MainWindow::getSelectedFaults()
{
    QStringList selectedFaults;
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        QTreeWidgetItem *item = *it;
        if (item->childCount() == 0 && item->checkState(0) == Qt::Checked) {
            selectedFaults.append(item->text(0));
        }
        ++it;
    }
    return selectedFaults;
}
QStringList MainWindow::getSelectedTestPoints()
{
    QStringList selectedTestPoints;
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        if (item->checkState() == Qt::Checked) {
            selectedTestPoints.append(item->text());
        }
    }
    return selectedTestPoints;
}
QVector<QStringList> MainWindow::loadMatrixData(const QString &filePath)
{
    QVector<QStringList> matrixData;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件");
        return matrixData;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        matrixData.append(line.split(","));
    }
    file.close();
    return matrixData;
}
void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget_3->clearContents();
    ui->tableWidget_3->setRowCount(0);
    ui->tableWidget_3->setColumnCount(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    if (ui->tabWidget->currentIndex() == 0) { // 0是faultSelecttab页面的索引
        // 全选所有故障名称前面的复选框
        QTreeWidgetItemIterator it(ui->treeWidget);
        while (*it) {
            QTreeWidgetItem *item = *it;
            if (item->childCount() == 0) {
                item->setCheckState(0, Qt::Checked);
            }
            ++it;
        }
    } else if (ui->tabWidget->currentIndex() == 1) { // 1是testPointSelecttab页面的索引
        // 全选所有测试点名称前面的复选框
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QListWidgetItem *item = ui->listWidget->item(i);
            item->setCheckState(Qt::Checked);
            updateTableWidget(item);
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if (ui->tabWidget->currentIndex() == 0) { // 0是faultSelecttab页面的索引
        // 取消勾选所有故障名称前面的复选框
        QTreeWidgetItemIterator it(ui->treeWidget);
        while (*it) {
            QTreeWidgetItem *item = *it;
            if (item->childCount() == 0) {
                item->setCheckState(0, Qt::Unchecked);
            }
            ++it;
        }
    } else if (ui->tabWidget->currentIndex() == 1) { // 1是testPointSelecttab页面的索引
        // 取消勾选所有测试点名称前面的复选框
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QListWidgetItem *item = ui->listWidget->item(i);
            item->setCheckState(Qt::Unchecked);
            updateTableWidget(item);
        }
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    QString filePath = "C:/Users/admin/Desktop/240708_qt_demo/algorithm_workspace/initial_Dmatrix.csv";
    // 获取 tableWidget_3 中的行数和列数
    int rowCount = ui->tableWidget_3->rowCount();
    int columnCount = ui->tableWidget_3->columnCount();
    // 检查行数和列数是否有效
    if (rowCount == 0 || columnCount == 0) {
        QMessageBox::warning(this, "错误", "没有数据可以保存！");
        return;
    }
    // 打开文件以写入数据
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QMessageBox::warning(this, "错误", "无法打开文件进行写入！");
        return;
    }
    // 创建一个 QTextStream 以便写入数据
    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8); // 设置编码为 UTF-8
    // 写入表头（tableWidget_3 的列标题）
    QStringList headers;
    headers << ""; // 空字符串作为第一列，用于行标题
    for (int col = 0; col < columnCount; ++col) {
        headers.append(ui->tableWidget_3->horizontalHeaderItem(col)->text());
    }
    out << headers.join(",") << "\n";
    // 写入数据行
    for (int row = 0; row < rowCount; ++row) {
        QStringList rowData;
        // 第一列为行标题（垂直表头）
        QTableWidgetItem *verticalHeaderItem = ui->tableWidget_3->verticalHeaderItem(row);
        if (verticalHeaderItem) {
            rowData.append(verticalHeaderItem->text());
        } else {
            rowData.append(""); // 如果没有垂直表头项，则写入空字符串
        }
        // 其余列为数据
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->tableWidget_3->item(row, col);
            if (item) {
                rowData.append(item->text());
            } else {
                rowData.append("");
            }
        }
        out << rowData.join(",") << "\n";
    }
    file.close();
    QMessageBox::information(this, "保存成功", "表格内容已成功保存到文件：" + filePath);
}



