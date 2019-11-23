import QtQuick 2.9
import CM 1.0
import assets 1.0

Panel {
    property Address address
    property StringDecorator tmpStringDecor

    contentComponent:
        Column {
        id: column
        spacing: Style.sizeControlSpacing
        StringEditorSingleLine {
            stringDecor: address ? address.ui_building : tmpStringDecor
            anchors {
                left: parent.left
                right: parent.right
            }
        }
        StringEditorSingleLine {
            stringDecor: address ? address.ui_street : tmpStringDecor
            anchors {
                left: parent.left
                right: parent.right
            }
        }
        StringEditorSingleLine {
            stringDecor: address ? address.ui_city : tmpStringDecor
            anchors {
                left: parent.left
                right: parent.right
            }
        }
        StringEditorSingleLine {
            stringDecor: address ? address.ui_postcode : tmpStringDecor
            anchors {
                left: parent.left
                right: parent.right
            }
        }
    }
}
