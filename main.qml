import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    visibility: "FullScreen"
    title: qsTr("Qt Quick Stack Application")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        Material.accent: Material.Orange
        Material.primary: Material.DeepOrange


        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        implicitWidth: 100
        width: window.width * 0.1
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.push("Page1Form.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.push("Page2Form.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Exit")
                width: parent.width
                onClicked:{
                    Qt.quit()
                    // window.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }
}
