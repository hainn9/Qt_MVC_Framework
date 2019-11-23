import QtQuick 2.9
import CM 1.0
import assets 1.0

Item {
    property StringDecorator stringDecor

    height: width > textLabel.width + textValue.width ? Style.heightDataControls : Style.heightDataControls * 2

    Flow {
        anchors.fill: parent
        Rectangle {
            width: Style.widthDataControls
            height: Style.heightDataControls
            color: Style.colorBackground

            Text {
                id: textLabel
                anchors {
                    fill: parent
                    margins: Style.heightDataControls / 4
                }
                font.pixelSize: Style.pixelSizeDataControls
                color: Style.colourDataControlsFont
                text: stringDecor.ui_label
                verticalAlignment: Qt.AlignVCenter
            }
        }

        Rectangle {
            id: background
            width: Style.widthDataControls
            height: Style.heightDataControls
            color: Style.colourDataControlsBackground
            border {
                width: 1
                color: Style.colourDataControlsFont
            }
            TextInput {
                id: textValue
                anchors {
                    fill: parent
                    margins: Style.heightDataControls / 4
                }
                font.pixelSize: Style.pixelSizeDataControls
                color: Style.colourDataControlsFont
                text: stringDecor.ui_value
                verticalAlignment: Qt.AlignVCenter
            }
        }

        Binding {
            target: stringDecor
            property: "ui_value"
            value: textValue.text
        }
    }

}
