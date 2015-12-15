/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <QVideoWidget>
#include <vector>
#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QComboBox>
#include "info.h"

QT_BEGIN_NAMESPACE
class QAbstractItemView;
class QLabel;
class QMediaPlayer;
class QModelIndex;
class QPushButton;
class QToolButton;
class QSlider;
class QVideoProbe;
class QVideoWidget;
class QTreeWidget;
class QTreeWidgetItem;
class QScreen;
QT_END_NAMESPACE

class PlaylistModel;
class HistogramWidget;

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
signals:
    void changeMuting(bool);
    void changeRate(qreal);
    void playVideo();
    void pauseVideo();
    void updateInfo();
    void goToNext();

private slots:
    void open();
    void durationChanged(qint64 duration);
    void positionChanged(qint64 progress);
    void metaDataChanged();

    void previousClicked();
    void muteClicked();
    void playClicked();
    qreal playbackRate() const;
    void setPlaybackRate(float);
    void updateRate();

    void seek(int seconds);
    void jump(const QModelIndex &index);

    void statusChanged(QMediaPlayer::MediaStatus status);
    void bufferingProgress(int progress);
    void videoAvailableChanged(bool);
    void setState(QMediaPlayer::State state);

    void displayErrorMessage();
    void clearCheckboxes();
    void submitCheckboxes();
    void saveScreenshot();
    void needStop();
    void nextVideo();
    void inputParNum();
    void clickReady();
    void recordRTime(QTreeWidgetItem*);

#ifndef PLAYER_NO_COLOROPTIONS
    void showColorDialog();
#endif
    void addToPlaylist(const QStringList &fileNames);
    void beginSurvey();
    void endSurvey();
    void linkSurvey();
    void updateTime();
    void tutorial();

private:
    void setTrackInfo(const QString &info);
    void setStatusInfo(const QString &info);
    void handleCursor(QMediaPlayer::MediaStatus status);
    void updateDurationInfo(qint64 currentInfo);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);


    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QVideoWidget *videoWidget;
    QLabel *coverLabel;
    QSlider *slider;
    QLabel *labelDuration;
    QComboBox *rateBox;
    QPushButton *openButton;
    QToolButton *playButton;
    QToolButton *stopButton;
    QToolButton *nextButton;
    QToolButton *previousButton;
    QPushButton *screenshotButton;
    QPushButton *alertButton;
    QToolButton *muteButton;
    QSlider *volumeSlider;
    Info database;
    QTreeWidget *tabs;
#ifndef PLAYER_NO_COLOROPTIONS
    QPushButton *colorButton;
    QDialog *colorDialog;
#endif

    QLabel *labelHistogram;
    HistogramWidget *histogram;
    QVideoProbe *probe;

    PlaylistModel *playlistModel;
    QString trackInfo;
    QString statusInfo;
    qint64 duration;
    QMediaPlayer::State playerState;
    vector<QTreeWidgetItem*> boxes;
    vector<QTreeWidgetItem*> comment;
    QLabel *showTime;
    QPushButton *tutorialButton;
    vector<QTreeWidgetItem*> check;
    vector<qint64> vTime;
    vector<string> rTime;
    vector<int> vIndex;
    vector<qint64> iTime;
};

#endif // PLAYER_H
