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

#ifndef PICTURES_H
#define PICTURES_H

#include <QPixmap>
#include <vector>
#include <QDebug>

class PicturesHolder {

    std::vector<QPixmap> basises;
    std::vector<QPixmap> elements;
    std::vector<QPixmap> animals;

public:
    enum BasisIndex {
        B_None,
        B_Unknown,
        B_Yan,
        B_In
    };
    enum ElementIndex {
        E_None,
        E_Unknown,
        E_Wood,
        E_Fire,
        E_Earth,
        E_Metal,
        E_Water
    };
    enum AnimalIndex {
        A_None,
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

public:
    PicturesHolder();
    ~PicturesHolder() {};

    QPixmap basis(BasisIndex index);
    QPixmap element(ElementIndex index);
    QPixmap animal(AnimalIndex index);
};

#endif // PICTURES_H
