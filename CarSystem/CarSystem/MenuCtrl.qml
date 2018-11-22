import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Rectangle {
    id: menuCtrl
    signal signalCloseMenuCtrl();
    signal signalCollapseMenu();
    signal signalPagesBtnClicked();
    signal signalNotesBtnClicked();
    signal signalConsoleBtnClicked();

    Button{
        id: collapseBtn
        anchors.left: menuCtrl.left
        anchors.right: menuCtrl.right
        text: "collapse"
        ToolTip{
            visible: collapseBtn.hovered ? true:false
            text:collapseBtn.text.toLowerCase()
        }
        background: Rectangle{
            anchors.fill: parent
            color: "gray"
        }
        MouseArea{
            anchors.fill: parent
            cursorShape: collapseBtn.hovered ? Qt.OpenHandCursor:Qt.ArrowCursor
            onClicked: signalCollapseMenu()
        }
    }

    ToolBar{
        anchors.top:collapseBtn.bottom
        anchors.left: menuCtrl.left
        anchors.right: menuCtrl.right
        ToolButton{
            id: pagesBtn
            height: 100
            anchors.left: parent.left
            anchors.right: parent.right
            text: "PAGES"
            background: Rectangle{
                id:pagesBtnBg
                anchors.fill: parent
                color: pagesBtn.hovered ? "gray":menuCtrl.color
            }
            MouseArea{
                anchors.fill: parent
                onClicked:{
                    pagesBtnBg.color = "white"
                    notesBtnBg.color = menuCtrl.color
                    consoleBtnBg.color = menuCtrl.color
                    signalPagesBtnClicked()
                }
            }
        }

        ToolButton{
            id: notesBtn
            height: 100
            anchors.top:pagesBtn.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            text: "NOTES"
            background: Rectangle{
                id:notesBtnBg
                anchors.fill: parent
                color: notesBtn.hovered ? "gray":menuCtrl.color
            }
            MouseArea{
                anchors.fill: parent
                onClicked:{
                    pagesBtnBg.color = menuCtrl.color
                    notesBtnBg.color = "white"
                    consoleBtnBg.color = menuCtrl.color
                    signalNotesBtnClicked()
                }
            }
        }

        ToolButton{
            id: consoleBtn
            height: 100
            anchors.top:notesBtn.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            text: "CONSOLE"
            background: Rectangle{
                id:consoleBtnBg
                anchors.fill: parent
                color: consoleBtn.hovered ? "gray":menuCtrl.color
            }
            MouseArea{
                anchors.fill: parent
                onClicked:{
                    pagesBtnBg.color = menuCtrl.color
                    notesBtnBg.color = menuCtrl.color
                    consoleBtnBg.color = "white"
                    signalConsoleBtnClicked()
                }
            }
        }
    }

    Button{
        id: closeBtn
        height: 25
        anchors.bottom: menuCtrl.bottom
        anchors.left: menuCtrl.left
        anchors.right: menuCtrl.right
        text: "CLOSE"
        ToolTip{
            visible: closeBtn.hovered ? true:false
            text:closeBtn.text.toLowerCase()
        }
        background: Rectangle{
            anchors.fill: parent
            color: "gray"
        }
        MouseArea{
            anchors.fill: parent
            cursorShape: closeBtn.hovered ? Qt.OpenHandCursor:Qt.ArrowCursor
            onClicked: signalCloseMenuCtrl() //按键按下发送信号
        }
    }
}

