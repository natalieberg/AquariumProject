CameraDataHandler() {

    setup piCamera
    connect to In-memory binary stream used by piCamera
    setup newFrameAvailableCondition
    
    loop forever {
        wait until new frame available from piCamera
        get last frame from the In-memory binary stream
        set the current newFrame to be sent
        notify on newFrameAvailableCondition
    }
}
