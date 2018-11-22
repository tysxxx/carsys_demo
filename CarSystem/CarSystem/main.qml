import QtQuick 2.9
import QtQuick 2.7
import QtQml 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Window {
    id: mainWin
    visible: true
    width: 640; height: 480
    //flags: Qt.FramelessWindowHint


    Rectangle{
        anchors.fill: parent
        color: "lightgreen"
        MenuCtrl{
            id: menuCtrl
            width: 100; height: parent.height
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            color: "lightgray"
        }

        MenuPage{
            id: menuPage
            width: 200
            anchors.left: menuCtrl.right
            anchors.leftMargin: 1
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }

//        SplitView {
//            id: split
//            //anchors.left: menuCtrl.right
//            orientation: Qt.Horizontal
//            MenuPage{
//                id: menuPage
//                //color: "lighblue"
//            }

//            MenuPage{

//            }
//       }
    }
}
