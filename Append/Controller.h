#pragma once

class Controller final
{
public:
    ~Controller();

    static void CreateInstance();

    static void DeleteInstance();

    static void Update();

    static bool LeftInput() { return leftInput; }

    static bool RightInput() { return rightInput; }

    static bool StartInput() { return startInput; }

    static bool XInput() { return xInput; }

    static bool BackInput() { return backInput; }

private:
    Controller();

    static Controller* instance;

    static int padState;

    static bool leftInput;

    static bool rightInput;

    static bool startInput;

    static bool xInput;

    static bool backInput;
};