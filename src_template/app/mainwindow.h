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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QDate>
#include <QMessageBox>
#include <QKeyEvent>
#include <QSizePolicy>
#include <QDebug>
#include "pictures.h"
#include "calendar.h"

namespace Ui {
class MainWindow;
}

class MainWindowFunctions {
public:
    bool isLeapYear(size_t year);
    bool isLeapNegativeYear(size_t year);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   void moveToCenter();
   void keyPressEvent(QKeyEvent *event);
   bool eventFilter(QObject *object, QEvent *event);

private slots:
    void on_pushButton_eval_clicked();

    void on_pushButton_clear_clicked();

    void on_action_triggered();

    void slot1_alignNumberOfDays();

    void slot2_decreaseYear();

    void slot3_increaseYear();

private:
    Ui::MainWindow *ui;
    PicturesHolder *pictures;
    Calendar *calendar;
    bool focusOnRadio;
    MainWindowFunctions winFuncs;

public:
    void clearDate();
    void clearResult();
};

#endif // MAINWINDOW_H
