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

#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDate>
#include <QDebug>

class Calendar {

    enum PartOfYear {
        P_Unknown,
        P_Small,
        P_Big
    };

    int day;
    int month;
    size_t year;
    bool isOurEra;

public:
    Calendar() {};
    ~Calendar() {};
    void setDate(int day,
                 int month,
                 size_t year,
                 bool isOurEra);

public:
    enum BasisIndex {
        B_Unknown,
        B_Yan,
        B_In
    };
    enum ElementIndex {
        E_Unknown,
        E_Wood,
        E_Fire,
        E_Earth,
        E_Metal,
        E_Water
    };
    enum AnimalIndex {
        A_Unknown,
        A_Rat,
        A_Ox,
        A_Tiger,
        A_Rabbit,
        A_Dragon,
        A_Snake,
        A_Horse,
        A_Goat,
        A_Monkey,
        A_Rooster,
        A_Dog,
        A_Pig
    };
    BasisIndex getBasis();
    ElementIndex getElement();
    AnimalIndex getAnimal();

private:
    PartOfYear getPart();
    QDate tableLookUp(size_t year);
};

#endif // CALENDAR_H
