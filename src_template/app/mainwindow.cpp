/*
 * This file is a part of __PROGRAM_NAME__ __PROGRAM_VERSION__
 *
 * __PROGRAM_COPYRIGHT__ __PROGRAM_AUTHOR__ __PROGRAM_AUTHOR_EMAIL__
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    moveToCenter();

    pictures = new PicturesHolder();
    calendar = new Calendar();

    focusOnRadio = false;
    ui->radioButton_era->installEventFilter(this);
    ui->radioButton_era_before->installEventFilter(this);

    clearDate();
    clearResult();
}

MainWindow::~MainWindow()
{
    delete calendar;
    delete pictures;
    delete ui;
}

void MainWindow::moveToCenter()
{
    QRect rect = frameGeometry();
    rect.moveCenter(QDesktopWidget().availableGeometry().center());
    move(rect.topLeft());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        if (!focusOnRadio)
            slot2_decreaseYear();
        break;
    case Qt::Key_Right:
        if (!focusOnRadio)
            slot3_increaseYear();
        break;
    case Qt::Key_Return:
        on_pushButton_eval_clicked();
        break;
    case Qt::Key_Escape:
        close();
        break;
    default:
        QWidget::keyPressEvent(event);
        return;
    }
}

void MainWindow::clearDate()
{
    QDate currentDate = QDate::currentDate();
    int day = currentDate.day();
    int month = currentDate.month();
    size_t year = currentDate.year();

    ui->comboBox_month->setCurrentIndex(month - 1);
    ui->spinBox_day->setValue(day);
    ui->spinBox_year->setValue(year);
    ui->radioButton_era->setChecked(true);
}

void MainWindow::clearResult()
{
    QPixmap basis = pictures->basis(PicturesHolder::B_None);
    QPixmap element = pictures->element(PicturesHolder::E_None);
    QPixmap animal = pictures->animal(PicturesHolder::A_None);
    ui->label_basis_img->setPixmap(basis);
    ui->label_element_img->setPixmap(element);
    ui->label_animal_img->setPixmap(animal);
}

void MainWindow::on_pushButton_eval_clicked()
{
    int day, month;
    size_t year;
    bool isOurEra;

    year = ui->spinBox_year->value();
    month = ui->comboBox_month->currentIndex() + 1;
    day = ui->spinBox_day->value();
    isOurEra = ui->radioButton_era->isChecked();

    calendar->setDate(day, month, year, isOurEra);

    QPixmap basisImg, elementImg, animalImg;

    switch (calendar->getBasis()) {
    case Calendar::B_Yan:
        basisImg = pictures->basis(PicturesHolder::B_Yan);
        break;
    case Calendar::B_In:
        basisImg = pictures->basis(PicturesHolder::B_In);
        break;
    case Calendar::B_Unknown:
        basisImg = pictures->basis(PicturesHolder::B_Unknown);
        break;
    }

    switch (calendar->getElement()) {
    case Calendar::E_Wood:
        elementImg = pictures->element(PicturesHolder::E_Wood);
        break;
    case Calendar::E_Fire:
        elementImg = pictures->element(PicturesHolder::E_Fire);
        break;
    case Calendar::E_Earth:
        elementImg = pictures->element(PicturesHolder::E_Earth);
        break;
    case Calendar::E_Metal:
        elementImg = pictures->element(PicturesHolder::E_Metal);
        break;
    case Calendar::E_Water:
        elementImg = pictures->element(PicturesHolder::E_Water);
        break;
    case Calendar::E_Unknown:
        elementImg = pictures->element(PicturesHolder::E_Unknown);
        break;
    }

    switch (calendar->getAnimal()) {
    case Calendar::A_Rat:
        animalImg = pictures->animal(PicturesHolder::A_Rat);
        break;
    case Calendar::A_Ox:
        animalImg = pictures->animal(PicturesHolder::A_Ox);
        break;
    case Calendar::A_Tiger:
        animalImg = pictures->animal(PicturesHolder::A_Tiger);
        break;
    case Calendar::A_Rabbit:
        animalImg = pictures->animal(PicturesHolder::A_Rabbit);
        break;
    case Calendar::A_Dragon:
        animalImg = pictures->animal(PicturesHolder::A_Dragon);
        break;
    case Calendar::A_Snake:
        animalImg = pictures->animal(PicturesHolder::A_Snake);
        break;
    case Calendar::A_Horse:
        animalImg = pictures->animal(PicturesHolder::A_Horse);
        break;
    case Calendar::A_Goat:
        animalImg = pictures->animal(PicturesHolder::A_Goat);
        break;
    case Calendar::A_Monkey:
        animalImg = pictures->animal(PicturesHolder::A_Monkey);
        break;
    case Calendar::A_Rooster:
        animalImg = pictures->animal(PicturesHolder::A_Rooster);
        break;
    case Calendar::A_Dog:
        animalImg = pictures->animal(PicturesHolder::A_Dog);
        break;
    case Calendar::A_Pig:
        animalImg = pictures->animal(PicturesHolder::A_Pig);
        break;
    case Calendar::A_Unknown:
        animalImg = pictures->animal(PicturesHolder::A_Unknown);
        break;
    }

    ui->label_basis_img->setPixmap(basisImg);
    ui->label_element_img->setPixmap(elementImg);
    ui->label_animal_img->setPixmap(animalImg);
}

void MainWindow::on_pushButton_clear_clicked()
{
    clearDate();
    clearResult();
}

void MainWindow::on_action_triggered()
{
    QString title = QString::fromUtf8("О программе");
    QString msg = QString::fromUtf8(
        "__PROGRAM_NAME__ __PROGRAM_VERSION__\n"
        "\n"
        "Вычислияет начало, стихию и животное по восточному календарю.\n"
        "\n"
        "__PROGRAM_COPYRIGHT__ __PROGRAM_AUTHOR__"
        "\n"
        "__PROGRAM_AUTHOR_EMAIL__"
    );

    QMessageBox::information(this, title, msg);
}

void MainWindow::slot1_alignNumberOfDays()
{
    int monthDays[] = {31, 28, 31, 30,
                       31, 30, 31, 31,
                       30, 31, 30, 31};
    int month = ui->comboBox_month->currentIndex() + 1;
    size_t year = ui->spinBox_year->value();
    bool isOurEra = ui->radioButton_era->isChecked();

    if (month == 2) {
        int value = monthDays[month - 1];
        if ((isOurEra && winFuncs.isLeapYear(year)) ||
            (!isOurEra && winFuncs.isLeapNegativeYear(year)))
            value++;
        ui->spinBox_day->setMaximum(value);
    } else {
        ui->spinBox_day->setMaximum(monthDays[month - 1]);
    }
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn) {
        if (object == ui->radioButton_era ||
            object == ui->radioButton_era_before) {
            focusOnRadio = true;
        }
    }
    if (event->type() == QEvent::FocusOut) {
        if (object == ui->radioButton_era ||
            object == ui->radioButton_era_before) {
            focusOnRadio = false;
        }
    }
    return false;
}

void MainWindow::slot2_decreaseYear()
{
    size_t year = ui->spinBox_year->value();
    bool isOurEra = ui->radioButton_era->isChecked();

    if (isOurEra) {
        if (year > 1)
            ui->spinBox_year->setValue(year - 1);
        else
            ui->radioButton_era_before->setChecked(true);
    } else {
        ui->spinBox_year->setValue(year + 1);
    }
}

void MainWindow::slot3_increaseYear()
{
    size_t year = ui->spinBox_year->value();
    bool isOurEra = ui->radioButton_era->isChecked();

    if (isOurEra) {
        ui->spinBox_year->setValue(year + 1);
    } else {
        if (year > 1)
            ui->spinBox_year->setValue(year - 1);
        else
            ui->radioButton_era->setChecked(true);
    }
}

bool MainWindowFunctions::isLeapYear(size_t year)
{
    // 500 делится на 100 и на 4, но не делится на 400
    // 400 делится на 100 и на 4, и делится на 400
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool MainWindowFunctions::isLeapNegativeYear(size_t year)
{
    // 1 год до нашей эры - это високосный год столетия
    // до нашей эры 1, 5, 9 ... - это годы через 4
    // до нашей эры 1, 401, 801, ... - это годы столетий
    year += 399;
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
