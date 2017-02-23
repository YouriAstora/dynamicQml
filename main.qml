import QtQuick 2.3
import QtQuick.Window 2.2

Rectangle {
    id: root
    visible: true
    anchors.fill:parent

    color: "black"

    objectName: "root"

    property var featuresWin: undefined

    Image{
        id: image
        source: "ressources/fox.jpg"
        anchors.centerIn:parent
    }

    Rectangle{
        anchors.fill: image
        color: "black"
        opacity: 0.7
    }

    Text{
        id: centralText
        anchors.bottom: root.verticalCenter
        anchors.bottomMargin: 20
        anchors.horizontalCenter: root.horizontalCenter
        color: "white"
        maximumLineCount: 5
        width: 500
        elide: Text.ElideRight
        text: "This qml project is DYNAMIC, try to modify an existing qml file and save it with Ctrl+S !!!"
        wrapMode: Text.Wrap
        font.pixelSize:38
    }

    CustomItem{
        id: randomItem
    }


    MyGrid{
        id: grid
        anchors.top: root.top
        anchors.bottom: root.bottom
        height: root.height
        width: root.width
    }
}

