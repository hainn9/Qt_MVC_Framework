import QtQuick 2.9
import QtQuick.Controls 2.2
import assets 1.0
import components 1.0
import CM 1.0

Item {
    property Client newClient: masterController.ui_client
    Rectangle {
        anchors.fill: parent
        color: Style.colorBackground
    }

    ScrollView {
        id: scrollView
        anchors {
            top: parent.top
            bottom: commandBar.top
            right: parent.right
            left: parent.left
            margins: Style.sizeScreenMargin
        }
        clip: true
        Column {
            spacing: Style.sizeScreenMargin
            width: scrollView.width
            StringEditorSingleLine {
                stringDecor: newClient.ui_name
                anchors {
                    left: parent.left
                    right: parent.right
                }
            }
        }
    }

    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandController.ui_createClientViewContextCommand
    }
}
