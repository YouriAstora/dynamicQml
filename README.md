## Dynamic QML ##

This repository contains an implementation of a C++ class that allows to dynamically reload the modified qml files in a Qt C++/QML project.

Qt Version:  5.5.1

## How to run the project ? ##

1. Open DynamicQMLDeveloping.pro in your Qt Creator.
2. Build & run.
3. Modify one of the provided qml files.
4. Press CTRL+S, and watch the result.

## How to use the DynamicQMLWindow class ?  ##

Please look how it's done in the main.cpp.
Basically you need to :
* instantiate a QQuickView
* instantiate the DynamicQMLWindow with the previous object
* set the view qml source file
* call DynamicQMLWindow show() method

*NB: If you want to expose C++ to Qml, please use the DynamicQMLWindow inner engine*  
 

