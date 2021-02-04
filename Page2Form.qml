import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

Page {
    width: 600
    height: 400

    title: qsTr("Page 2")

    Label {
        id: pageLabel
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }

    Label {
        id: model1Label
        anchors{
            top: pageLabel.bottom
            left: pageLabel.left
        }
        text: TheDataList.data[0].salary
    }

    Label {
        id: model2Label
        anchors{
            top: model1Label.bottom
            left: model1Label.left
        }
        text: TheDataList.data[1].salary
    }

    Button {
        id: btnInc1
        anchors{
            top: model2Label.bottom
            left: model2Label.left
        }
        text: "Increment 1"

        onClicked: {
            TheDataList.data[0].increment()
        }
    }

    Button {
        id: btnInc2
        anchors{
            top: btnInc1.top
            left: btnInc1.right
        }
        text: "Increment 2"

        onClicked: {
            TheDataList.data[1].increment()
        }
    }

    Button {
        id: btnReset
        anchors{
            horizontalCenter: btnInc1.right
            top: btnInc1.bottom
        }
        text: "Reset"

        onClicked: {
            md.open()
        }
    }

    MessageDialog {
        id: md
        text: "Are you sure?"
        title: "Dangerous!"
        icon: StandardIcon.Question
        standardButtons: StandardButton.Yes | StandardButton.No
        onYes: {
            TheDataList.data[0].resetSalary()
            TheDataList.data[1].resetSalary()
        }
   }

}
