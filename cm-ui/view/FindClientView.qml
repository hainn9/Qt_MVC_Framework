import QtQuick 2.9
import assets 1.0
import CM 1.0
import components 1.0

Item {
    property ClientSearch clientSearch: masterController.ui_clientSearch
    Rectangle {
        anchors.fill: parent
        color: Style.colorBackground

        Panel {
            id: searchPanel
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: Style.sizeScreenMargin
            }

            headerText: "Find Client"
            contentComponent:
                StringEditorSingleLine {
                stringDecor: clientSearch.ui_searchText
                anchors {
                    left: parent.left
                    right: parent.right
                }

            }
        }

        ListView {
            id: itemView
            anchors {
                top: searchPanel.bottom
                left: parent.left
                right: parent.right
                bottom: parent.bottom
                margins: Style.sizeScreenMargin
            }
            clip: true
            model: clientSearch.ui_searchResults
            delegate: SearchResultDelegate {
                client: modelData
            }
        }
    }


    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandController.ui_findClientViewContextCommand
    }
}

