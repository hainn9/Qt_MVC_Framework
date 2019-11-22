import QtQuick 2.9
import assets 1.0
import components 1.0
import CM 1.0

Item {
    // property Client newClient: masterController.ui_client
    Rectangle {
        anchors.fill: parent
        color: Style.colorBackground

        CommandBar {
            commandList: masterController.ui_commandController.ui_createClientViewContextCommand
        }
    }
}
