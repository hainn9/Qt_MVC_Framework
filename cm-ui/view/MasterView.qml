import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Client Manager")

    Connections {
        target: masterController.ui_navigationController
        onGoDashboardView:
            contentFrame.replace("qrc:/view/DashboardView.qml")
        onGoCreateClientView:
            contentFrame.replace("qrc:/view/CreateClientView.qml")
        onGoFindClientView:
            contentFrame.replace("qrc:/view/FindClientView.qml")
        onGoEditClientView:
            contentFrame.replace("qrc:/view/EditClientView.qml", {selectedClient : client})
    }

    Rectangle {
        id: navigationBar
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        width: 100
        color: "#000000"

        Column {
            Button {
                text: "Dashboard"
                onClicked:
                    masterController.ui_navigationController.goDashboardView()
            }
            Button {
                text: "New Client"
                onClicked:
                    masterController.ui_navigationController.goCreateClientView()
            }
            Button {
                text: "Find Client"
                onClicked:
                    masterController.ui_navigationController.goFindClientView()
            }
        }
    }

    StackView {
        id: contentFrame
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        clip: true
        initialItem: Qt.resolvedUrl("qrc:/view/SplashView.qml")
    }
}
