import QtQuick 2.9

import assets 1.0

Item {
    property alias iconCharacter: textIcon.text
    property alias description: textDescription.text

    property color hoverColor: Style.colorNavigationBarBackground

    signal navigationButtonClicked()


    width: parent.width
    height: Style.heightNavigationButton

    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.colorNavigationBarBackground

        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: hoverColor
                }
            }
        ]

        Row {
            Text {
                id: textIcon
                width: Style.widthNavigationButtonIcon
                height: Style.heightNavigationButtonIcon
                font {
                    family: Style.fontAwesome
                    pixelSize: Style.pixelSizeNavigationBarIcon
                }
                color: Style.colorNavigationBarFont
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: "\uf11a"
            }
            Text {
                id: textDescription
                width: Style.widthNavigationButtonDescription
                height: Style.heightNavigationButtonDescription
                font.pixelSize: Style.pixelSizeNavigationBarText
                color: Style.colorNavigationBarFont
                verticalAlignment: Text.AlignVCenter
                text: "SET ME"
            }
        }

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: navigationButtonClicked()
        }
    }
}
