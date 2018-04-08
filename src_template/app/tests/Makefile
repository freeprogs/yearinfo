
# This file is a part of __PROGRAM_NAME__ __PROGRAM_VERSION__
#
# This file makes automatic tests for the program parts.
#
# __PROGRAM_COPYRIGHT__ __PROGRAM_AUTHOR__ __PROGRAM_AUTHOR_EMAIL__
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


# Build section

BUILD_DIR = build
RUNTESTS_SHELLSCRIPT = runtests.sh

TARGET_CALENDAR = test_calendar
BUILD_CALENDAR_DIR = test_calendar
SRC_CALENDAR_CPP_TEST = test_calendar.cpp
SRC_CALENDAR_PRO_TEST = test_calendar.pro

TARGET_MAINWINDOW = test_mainwindow
BUILD_MAINWINDOW_DIR = test_mainwindow
SRC_MAINWINDOW_CPP_TEST = test_mainwindow.cpp
SRC_MAINWINDOW_PRO_TEST = test_mainwindow.pro


# Commands

all: calendar mainwindow

make_build_directory:
	@[ -d $(BUILD_DIR) ] $&& rm -rf $(BUILD_DIR)
	@mkdir $(BUILD_DIR)
	@cp $(RUNTESTS_SHELLSCRIPT) $(BUILD_DIR)
	@chmod +x $(BUILD_DIR)/$(RUNTESTS_SHELLSCRIPT)

calendar: make_build_directory
	@[ -d $(BUILD_CALENDAR_DIR) ] $&& rm -rf $(BUILD_CALENDAR_DIR)
	@mkdir $(BUILD_CALENDAR_DIR)
	@cp $(SRC_CALENDAR_CPP_TEST) $(BUILD_CALENDAR_DIR)
	@cp $(SRC_CALENDAR_PRO_TEST) $(BUILD_CALENDAR_DIR)
	@mv $(BUILD_CALENDAR_DIR) ..
	@(cd ../$(BUILD_CALENDAR_DIR) && qmake-qt5 && make)
	@mv ../$(BUILD_CALENDAR_DIR) .
	@cp $(BUILD_CALENDAR_DIR)/$(TARGET_CALENDAR) $(BUILD_DIR)
	@echo "$(TARGET_CALENDAR) has built"

mainwindow: make_build_directory
	@[ -d $(BUILD_MAINWINDOW_DIR) ] $&& rm -rf $(BUILD_MAINWINDOW_DIR)
	@mkdir $(BUILD_MAINWINDOW_DIR)
	@cp $(SRC_MAINWINDOW_CPP_TEST) $(BUILD_MAINWINDOW_DIR)
	@cp $(SRC_MAINWINDOW_PRO_TEST) $(BUILD_MAINWINDOW_DIR)
	@mv $(BUILD_MAINWINDOW_DIR) ..
	@(cd ../$(BUILD_MAINWINDOW_DIR) && qmake-qt5 && make)
	@mv ../$(BUILD_MAINWINDOW_DIR) .
	@cp $(BUILD_MAINWINDOW_DIR)/$(TARGET_MAINWINDOW) $(BUILD_DIR)
	@echo "$(TARGET_MAINWINDOW) has built"

help:
	@echo "usage: make [ clean ]" 1>&2

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BUILD_CALENDAR_DIR)
	@rm -rf $(BUILD_MAINWINDOW_DIR)
	@echo "Cleaned $(BUILD_DIR)/$(RUNTESTS_SHELLSCRIPT)"
	@echo "Cleaned $(BUILD_DIR)/$(TARGET_CALENDAR)"
	@echo "Cleaned $(BUILD_DIR)/$(TARGET_MAINWINDOW)"

.PHONY: all calendar mainwindow
