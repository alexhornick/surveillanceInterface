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

#include "player.h"
#include <QMessageBox>
#include <QApplication>
#include <QPixmap>
#include <QBitmap>

int main(int argc, char *argv[])
{
#ifdef Q_WS_MAEMO_6
    //Meego graphics system conflicts with xvideo during fullscreen transition
    QApplication::setGraphicsSystem("raster");
#endif
    QApplication app(argc, argv);
    Player player;
    player.showFullScreen();
  // player.setStyleSheet("background-color: pink; color:pink;");

#if defined(Q_WS_SIMULATOR)
    player.setAttribute(Qt::WA_LockLandscapeOrientation);
    player.showMaximized();
#else
    player.show();
    QPixmap pixmap("Tutorial1.png");
   QMessageBox instructionBox0;
   QString instruction = "Thank you for participating in the Detecting Threat study. \n\nAs part of the study, you will perfrom three tasks. \n\nTask 1: Your first task will be to view eight videos of a single individual who may or may not be concealing a firearm. As you watch each video, you will be able to stop the video and select from a list of options of behaviors that seem suspicious. \n\nTask 2:After you’ve watched the video and identified those behaviors that you think might suggest concealment of a firearm you will be asked to respond Yes or No as to whether or not you think the person in the clip was concealing a firearm. You will then be asked to rate how certain you are using a 50% - 100% scale.\n\nTask 3: Once you’ve watched all 8 videos and entered your judgments you will complete a brief survey.\n\nClick below to be taken to tutorial and practice video. ";
    instructionBox0.setText(instruction);
    instructionBox0.exec();

    QMessageBox instructionBox1;
    instructionBox1.setIconPixmap(pixmap);
    //instructionBox1.setStyleSheet("font-size:14pt; background-color:#FAEBD7;");
   instructionBox1.exec();

   QMessageBox instructionBox2;
    QPixmap pixmap2("Tutorial2.png");
    instructionBox2.setIconPixmap(pixmap2);
    //instructionBox2.setStyleSheet("font-size:14pt; background-color:#FAEBD7;");
   instructionBox2.exec();


    QMessageBox instructionBox4;
    QPixmap pixmap4("Tutorial4.png");
    instructionBox4.setIconPixmap(pixmap4);
    //instructionBox4.setStyleSheet("font-size:14pt; background-color:#FAEBD7;");
    instructionBox4.exec();

   /* QMessageBox instructionBox5;
    QPixmap pixmap5("Tutorial5.png");
    instructionBox5.setIconPixmap(pixmap5);
    //instructionBox5.setStyleSheet("font-size:14pt; background-color:#FAEBD7;");
    instructionBox5.exec();*/

    QMessageBox instructionBox6;
    QPixmap pixmap6("Tutorial6.png");
    instructionBox6.setIconPixmap(pixmap6);
    //instructionBox6.setStyleSheet("font-size:14pt; background-color:#FAEBD7;");
    instructionBox6.exec();

    QMessageBox instructionBox3;
    QPixmap pixmap3("Tutorial3.png");
    instructionBox3.setIconPixmap(pixmap3);
    //instructionBox3.setStyleSheet("font-size:14pt; background-color:#FAEBD7;");
    instructionBox3.exec();


    QMessageBox instructionBox7;
    //instructionBox7.setStyleSheet("font-size:14pt; background-color:#FAEBD7;");
    instructionBox7.setText("As you resume the video, continue looking for suspicious behaviors, and repeat the process. \nEven if it's a behavior you've checked before, please check it again. Thanks! \n\nLet's practice! \nThe first video that will play is a practice video for you to get accustomed to this program. Your input will not be analyzed from this first video.");
    instructionBox7.exec();

#endif
    return app.exec();
}
