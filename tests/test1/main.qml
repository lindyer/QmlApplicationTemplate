import QtQuick 2.9
import QtQuick.Window 2.9

import MyTypes 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("First")
    color: "orange"
    Email {
        address: "895309655@qq.com"
        name: "linjianpeng"
        Component.onCompleted: print(address,name)
    }
    Component.onCompleted: print(email.address,email.name)
}
