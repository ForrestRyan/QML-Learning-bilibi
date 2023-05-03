/*************************************************************************
 *
 * Copyright (c) 2010-2019, Klaralvdalens Datakonsult AB (KDAB)
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 2.0
import QtQuick.Controls 2.0

Rectangle {
    width: 400; height: 400
    color: "gray"

    Timer{
        id: timer
    }

    function delay(delayTime, cb) {
        timer.interval = delayTime
        timer.repeat = false
        timer.triggered.connect(cb)
        timer.start()
    }

    function callBack()
    {
        console.log("before: txt.visible: ", txt.visible)
        txt.visible = txt.visible ? false : true;
        console.log("after: txt.visible: ", txt.visible)
    }

    Text {
        id: txt
        x: 100
        text: qsTr("hello world")
        visible: false
    }

    Button {
        text: "click me"
        onDoubleClicked:  {
            delay(1000,callBack)
        }
    }

    Rectangle {
        x: 50; y: 50
        width: 300; height: 150
        color: "lightblue"

        Rectangle {
            x: 50; y: 50
            width: 50; height: 50
            color: "white"
        }
    }

    Rectangle {
        x: 50; y: 200
        width: 300; height: 150
        color: "green"

        Rectangle {
            x: 100; y: 50
            width: 150; height: 50
            color: "blue"
        }
    }
}
