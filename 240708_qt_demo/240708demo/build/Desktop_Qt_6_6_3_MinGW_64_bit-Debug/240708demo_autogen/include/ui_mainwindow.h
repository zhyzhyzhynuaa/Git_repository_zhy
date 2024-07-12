/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTabWidget *tabWidget;
    QWidget *faultSelecttab;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeWidget;
    QWidget *testPointSelecttab;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget_2;
    QWidget *faultInformationtab;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QWidget *testpointinformation;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tableWidget_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_8;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_6;
    QTableWidget *tableWidget_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1154, 719);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        splitter->setHandleWidth(1);
        splitter->setChildrenCollapsible(false);
        frame = new QFrame(splitter);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(frame);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout->addWidget(pushButton_7);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 5);

        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName("tabWidget");
        faultSelecttab = new QWidget();
        faultSelecttab->setObjectName("faultSelecttab");
        horizontalLayout_2 = new QHBoxLayout(faultSelecttab);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        treeWidget = new QTreeWidget(faultSelecttab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");

        horizontalLayout_2->addWidget(treeWidget);

        tabWidget->addTab(faultSelecttab, QString());
        testPointSelecttab = new QWidget();
        testPointSelecttab->setObjectName("testPointSelecttab");
        horizontalLayout_3 = new QHBoxLayout(testPointSelecttab);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        listWidget = new QListWidget(testPointSelecttab);
        listWidget->setObjectName("listWidget");

        horizontalLayout_3->addWidget(listWidget);

        tabWidget->addTab(testPointSelecttab, QString());

        verticalLayout->addWidget(tabWidget);

        splitter->addWidget(frame);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        toolButton = new QToolButton(frame_2);
        toolButton->setObjectName("toolButton");

        horizontalLayout_8->addWidget(toolButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_8->addWidget(pushButton_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_8);

        tabWidget_2 = new QTabWidget(frame_2);
        tabWidget_2->setObjectName("tabWidget_2");
        faultInformationtab = new QWidget();
        faultInformationtab->setObjectName("faultInformationtab");
        horizontalLayout_4 = new QHBoxLayout(faultInformationtab);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        tableWidget = new QTableWidget(faultInformationtab);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");

        horizontalLayout_4->addWidget(tableWidget);

        tabWidget_2->addTab(faultInformationtab, QString());
        testpointinformation = new QWidget();
        testpointinformation->setObjectName("testpointinformation");
        horizontalLayout_5 = new QHBoxLayout(testpointinformation);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        tableWidget_2 = new QTableWidget(testpointinformation);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        tableWidget_2->setObjectName("tableWidget_2");

        horizontalLayout_5->addWidget(tableWidget_2);

        tabWidget_2->addTab(testpointinformation, QString());

        verticalLayout_2->addWidget(tabWidget_2);

        splitter->addWidget(frame_2);

        verticalLayout_4->addWidget(splitter);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_3);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_3->addWidget(pushButton_2);

        verticalSpacer_5 = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        pushButton_8 = new QPushButton(frame_3);
        pushButton_8->setObjectName("pushButton_8");

        verticalLayout_3->addWidget(pushButton_8);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        pushButton_4 = new QPushButton(frame_3);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout_3->addWidget(pushButton_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_3->addWidget(pushButton_3);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_7->addLayout(verticalLayout_3);

        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_4);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        tableWidget_3 = new QTableWidget(frame_4);
        tableWidget_3->setObjectName("tableWidget_3");

        horizontalLayout_6->addWidget(tableWidget_3);


        horizontalLayout_7->addWidget(frame_4);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 5);

        verticalLayout_4->addWidget(frame_3);

        verticalLayout_4->setStretch(0, 5);
        verticalLayout_4->setStretch(1, 3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1154, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(faultSelecttab), QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\351\200\211\346\213\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(testPointSelecttab), QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\202\271\351\200\211\346\213\251", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\230\276\347\244\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\351\203\250\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\346\263\250\345\205\245\346\226\271\345\274\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\346\217\217\350\277\260", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(faultInformationtab), QCoreApplication::translate("MainWindow", "\346\225\205\351\232\234\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\202\271\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\202\271\351\203\250\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\202\271\346\225\217\346\204\237\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\202\271\346\217\217\350\277\260", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(testpointinformation), QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225\347\202\271\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\347\237\251\351\230\265", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\347\237\251\351\230\265", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\345\217\257\350\247\206\345\214\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
