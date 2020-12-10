#pragma once

/****************************************************************************************
 ** GitQlient is an application to manage and operate one or several Git repositories. With
 ** GitQlient you will be able to add commits, branches and manage all the options Git provides.
 ** Copyright (C) 2020  Francesc Martinez
 **
 ** LinkedIn: www.linkedin.com/in/cescmm/
 ** Web: www.francescmm.com
 **
 ** This program is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU Lesser General Public
 ** License as published by the Free Software Foundation; either
 ** version 2 of the License, or (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 ** Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public
 ** License along with this library; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 ***************************************************************************************/

#include <QCheckBox>
#include <QStyle>

class CheckBox : public QCheckBox
{
   Q_OBJECT

public:

    /**
     * @brief Constructs a checkbox with the given parent, but with no text @#.
     *
     * @param parent The parent widget if needed
     */
   explicit CheckBox(QWidget *parent = 0);

    /**
     * @brief Constructs a checkbox with the given parent and text @#.
     *
     * @param text The text of the button
     * @param parent The parent widget if needed
     */
   explicit CheckBox(const QString &text, QWidget *parent = 0);

    /**
     * @brief Returns the path to the file containing the indicator in a dark or bright theme @#
     *
     * @param state State that describes flags that are used when drawing primitive elements
     * @return Relative path to the file with the indicator
     */
   QString getIndicator(QStyle::State state) const;

protected:

   /**
    * @brief This is the main event handler; it handles event "event". It's a reimplemented function in a subclass to customize event handling and add additional event types @#
    *
    * @param e Native window system events from the event queue are fetched and translated them into QEvents
    * @return True if the event was recognized, otherwise it returns false
    */
   bool event(QEvent *e);

   /**
    * @brief Reimplemented function in a subclass to receive paint events. @#
    *
    * @param e Paint event. A paint event is a request to repaint all or part of a widget
    */
   void paintEvent(QPaintEvent *e);
};
