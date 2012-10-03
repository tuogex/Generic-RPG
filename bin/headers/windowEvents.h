
class Window {

    private:
    bool windowed;

    bool windowOk;

    public:
    Window();

    void handle_events();

    void toggle_fullscreen();

    bool error();

};
