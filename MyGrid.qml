import QtQuick 2.0

Item{
    id: grid
    width: 500
    height: 500

    property double gridOpacity : 0.3

    Repeater{
        model: 8

        Rectangle{
            id: vRect
            opacity: grid.gridOpacity
            x:  grid.width/9*(index + 1)
            width: 1
            height: grid.height
            color: "grey"
        }
    }

    Repeater{
        model: 8
        Rectangle{
            opacity: grid.gridOpacity
            y: grid.height/9*(index + 1)
            width: grid.width
            height: 1
            color: "grey"
        }
    }

}

