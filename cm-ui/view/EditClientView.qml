import QtQuick 2.9
import QtQuick.Controls 2.2
import assets 1.0
import CM 1.0
import components 1.0

Item {
    property Client selectedClient

    Component.onCompleted: masterController.ui_commandController.setSelectedClient(selectedClient)

    property StringDecorator temporaryString
    property Address temporaryAddress

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
            Panel {
                headerText: "Client Details"
                contentComponent:
                    Column {
                    spacing: Style.sizeControlSpacing
                    StringEditorSingleLine {
                        stringDecor: selectedClient ? selectedClient.ui_referrence : temporaryString
                        anchors {
                            left: parent.left
                            right: parent.right
                        }
                    }
                    StringEditorSingleLine {
                        stringDecor: selectedClient ? selectedClient.ui_name : temporaryString
                        anchors {
                            left: parent.left
                            right: parent.right
                        }
                    }
                }
            }
            AddressEditor {
                address: selectedClient ? selectedClient.ui_supplyAddress : temporaryAddress
                headerText: "Supply Address"
            }
            AddressEditor {
                address: selectedClient ? selectedClient.ui_supplyAddress : temporaryAddress
                headerText: "Billing Address"
            }
        }
    }

    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandController.ui_editClientViewContextCommand
    }
}
