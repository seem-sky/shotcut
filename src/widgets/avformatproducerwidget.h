/*
 * Copyright (c) 2012-2015 Meltytech, LLC
 * Author: Dan Dennedy <dan@dennedy.org>
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

#ifndef AVFORMATPRODUCERWIDGET_H
#define AVFORMATPRODUCERWIDGET_H

#include <QWidget>
#include "abstractproducerwidget.h"
#include "sharedframe.h"

namespace Ui {
    class AvformatProducerWidget;
}

class AvformatProducerWidget : public QWidget, public AbstractProducerWidget
{
    Q_OBJECT

public:
    explicit AvformatProducerWidget(QWidget *parent = 0);
    ~AvformatProducerWidget();

    // AbstractProducerWidget overrides
    Mlt::Producer* producer(Mlt::Profile&);

signals:
    void producerChanged();
    void producerReopened();

private slots:
    void onFrameDisplayed(const SharedFrame&);

    void on_resetButton_clicked();

    void on_videoTrackComboBox_activated(int index);

    void on_audioTrackComboBox_activated(int index);

    void on_scanComboBox_activated(int index);

    void on_fieldOrderComboBox_activated(int index);

    void on_aspectNumSpinBox_valueChanged(int );

    void on_aspectDenSpinBox_valueChanged(int );

    void on_durationSpinBox_editingFinished();

    void on_syncSlider_valueChanged(int value);

    void on_actionOpenFolder_triggered();

    void on_menuButton_clicked();

    void on_actionCopyFullFilePath_triggered();

    void on_notesTextEdit_textChanged();

private:
    Ui::AvformatProducerWidget *ui;
    int m_defaultDuration;

    void reopen(Mlt::Producer* p);
    void recreateProducer();
};

#endif // AVFORMATPRODUCERWIDGET_H
