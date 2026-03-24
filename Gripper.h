#include <iostream>

class Gripper
{
private:
    bool isClosed;   // true = close, false = open

public:
    Gripper() : isClosed(false) {}

    void open()
    {
        isClosed = false;
        std::cout << "[Gripper] OPEN (Release)" << std::endl;
    }

    void close()
    {
        isClosed = true;
        std::cout << "[Gripper] CLOSE (Grasp)" << std::endl;
    }

    bool getState() const
    {
        return isClosed;
    }
};
