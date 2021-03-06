#include "menuclass.h"

newProjectMenu::newProjectMenu(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("New project...");
    label = new QLabel("Enter new project name: ");
    comboBoxHeader = new QLabel("Choose chip class: ");
    projectNameChecking = new QLabel("Wrong");
    projectName = new QLineEdit;
    projectName->setPlaceholderText("Name...");
    projectName->setFrame(true);
    fileNameField = new QLineEdit("D:\\Qt5.3\\HRT\\resources\\K11053.mel");
    projectName->setMaxLength(20);
    fileNameField->setMaxLength(255);
    iniSelection = new QComboBox();
    iniSelection->addItem("HRT500.INI");
    iniSelection->addItem("HRT1500.INI");
    iniSelection->addItem("HRT3000.INI");
    okButton = new QPushButton("OK");
    okButton->setEnabled(false);
    cancelButton = new QPushButton("Cancel");
    selectMelButton = new QPushButton("Select MEL file...");

    connect(selectMelButton, SIGNAL(clicked()), this, SLOT(on_selectMelButton_clicked()));
    connect(projectName, SIGNAL(textChanged(QString)), this, SLOT(on_projectName_textChanged(QString)));

    QGridLayout *newProjectMenuLayout = new QGridLayout;
    newProjectMenuLayout->setAlignment(Qt::AlignTop);
    newProjectMenuLayout->setColumnMinimumWidth(1, 300);
    newProjectMenuLayout->addWidget(label,0,0,1,0);
    //newProjectMenuLayout->setVerticalSpacing(6);
    newProjectMenuLayout->addWidget(projectName,1,0);
    newProjectMenuLayout->addWidget(projectNameChecking,1,1,Qt::AlignCenter);
    newProjectMenuLayout->addWidget(comboBoxHeader,2,0,1,0);
    //newProjectMenuLayout->setVerticalSpacing(6);
    newProjectMenuLayout->addWidget(iniSelection,3,0,1,0);
    newProjectMenuLayout->addWidget(selectMelButton,4,0);
    newProjectMenuLayout->addWidget(fileNameField,4,1);
    newProjectMenuLayout->addWidget(okButton,5,0);
    newProjectMenuLayout->addWidget(cancelButton,5,1);
    newProjectMenuLayout->setMargin(11);
    newProjectMenuLayout->setSpacing(6);
    this->setLayout(newProjectMenuLayout);
//    this->resize(500, this->geometry().height());
}

QString newProjectMenu::getText() const
{
    return projectName->text();
}

QString newProjectMenu::getIni() const
{
    return iniSelection->currentText();
}

void newProjectMenu::on_selectMelButton_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
        fileNameField->setText(fileName);
    }
}

void newProjectMenu::on_projectName_textChanged(QString text)
{
    emit checkProjectName(text);
}

void newProjectMenu::on_fileNameCheckingResult(bool isCorrect)
{
    //qDebug()<<"Checking"<<isCorrect;
    if(isCorrect){
        projectNameChecking->setText("Correct");
        projectNameChecking->setStyleSheet("QLabel { color : green; }");
        okButton->setEnabled(true);
    }else{
        projectNameChecking->setText("Wrong");
        projectNameChecking->setStyleSheet("QLabel { color : red; }");
        okButton->setEnabled(false);

    }
}

QString newProjectMenu::getFileName() const
{
    //melName =
    return fileNameField->text();
}
