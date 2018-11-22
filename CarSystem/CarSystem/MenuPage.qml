import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item{
    id: menuPage
    Layout.preferredWidth: 200
    Layout.preferredHeight: 200
    signal signalLinkBtnClicked();
    signal signalHighlightBtnClicked();

    Rectangle{
        id: meunTitle
        height: 80
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        color: "lightgray"
        Text{
            id: menuName
            anchors.fill: parent
            font.pixelSize: 20
            font.weight: Font.Medium
            text: "主菜单"
            verticalAlignment: Text.AlignBottom
            anchors.bottomMargin: 5

            Button{
                id: linkBtn
                width: 20; height: 20
                anchors.right:highlightBtn.left
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                ToolTip{
                    visible: linkBtn.hovered ? true:false
                    text:qsTr("Get links").toLowerCase()
                }
                Text{
                    anchors.fill: parent
                    text: "li"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: linkBtn.hovered ? Qt.OpenHandCursor:Qt.ArrowCursor
                    onClicked: signalLinkBtnClicked()
                }
            }

            Button{
                id: highlightBtn
                width: 20; height: 20
                anchors.right:parent.right
                anchors.rightMargin: 10
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                ToolTip{
                    visible: highlightBtn.hovered ? true:false
                    text:qsTr("highlight interactive element").toLowerCase()
                }
                Text{
                    anchors.fill: parent
                    text: "hi"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea{
                    anchors.fill: parent
                    cursorShape: highlightBtn.hovered ? Qt.OpenHandCursor:Qt.ArrowCursor
                    onClicked: signalHighlightBtnClicked()
                }
            }
        }
    }

    //@2.加载Separator
    ToolSeparator{
        visible: true
        anchors.top: meunTitle.bottom
        anchors.topMargin: 1
        anchors.left: parent.left
        anchors.right: parent.right
        orientation: "Horizontal"
    }

}

