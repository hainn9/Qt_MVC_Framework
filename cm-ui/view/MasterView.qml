import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import assets 1.0
import components 1.0

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

    NavigationBar {
        id: navigationBar        
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
